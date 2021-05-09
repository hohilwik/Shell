#include <unistd.h>
#include <stdlib.h>

#include <dirent.h>
#include <errno.h>

#include <string.h>

#include <stdio.h>
#include <sys/syscall.h>
#include <sys/types.h>

//**********************************************************************************//
// FUNCTION DESCRIPTION
// Compare function takes the Assignment folder name and the zip file name as inputs
// Does md5 hash on the files in both directories and compares them
// Prints the file names in the Assignment folder that are different from those in the zip file.

// USAGE: compare <assignmentFolderName>, <zipFolderName>
// eg: compare Assignment AssignmentZip.zip

// TODO:
// modularize the code
// more extensive testing is needed
// add error handling (input validation, etc)
// add output messages for the user 
// scope is currently limited to Linux - need to extend to other systems as required
//******************************************************************************//


void makeAuxDirectory()
{
    //Create a auxillary directory (called 'hashfolder').
    //hashfolder is a work folder that temporarily stores the output of the md5 hash 
    //and the unziped version of the file for processing. It is deleted at the end of the execution.
    
    DIR *dir = opendir("hashfolder");

    if (dir)
    {
        // Directory already exists.
        //TODO: display error message OR get confirmation to remove the directory               
        closedir(dir);
    }
    else if (ENOENT == errno)
    {
        // If directory does not exist, create it.
        char *mkdirCommandName = "mkdir hashfolder";

        system(mkdirCommandName);
    }
}


void compare(char assignmentFolderName[], char zipFolderName[])
{
    makeAuxDirectory();

    //********************************************//
    //cat folder names together with the commands //
    //********************************************//
    
    //finds the files in the Assignment folder and then performs md5sum and stores it in txt file 
    char folderfilehashCommand[80];
    strcpy(folderfilehashCommand, "find ");
    strcat(folderfilehashCommand, assignmentFolderName);
    strcat(folderfilehashCommand, " -type f -exec md5sum {} + > hashfolder/filehash1.txt");   
    //printf("%s\n", folderfilehashCommand);

    system(folderfilehashCommand);

    //unzip the zipped folder so that we can compare contents with the Assignment folder
    char unzipCommand[80];
    strcpy(unzipCommand, "unzip ");
    strcat(unzipCommand, zipFolderName);
    strcat(unzipCommand, " -d hashfolder");        //eg: "unzip AssignmentZip.zip -d hashfolder";

    system(unzipCommand);


    //finds the files in the zip file and then performs md5sum and stores it in txt file
    char zipfilehashCommand[80];
    strcpy(zipfilehashCommand, "find ");
    strcat(zipfilehashCommand, "hashfolder/");
    strcat(zipfilehashCommand, assignmentFolderName);
    strcat(zipfilehashCommand, " -type f -exec md5sum {} + > hashfolder/filehash2.txt");    
    //printf("%s\n", zipfilehashCommand);

    system(zipfilehashCommand); 

    //****************************************************************//
    //command to find the differences in the two hashes and print them//
    //****************************************************************//

    char *diffCommand = "awk 'NR==FNR{c[$1]++;next};c[$1] == 0 {print $2}' hashfolder/filehash2.txt hashfolder/filehash1.txt";   

    printf("\nThe following files in the assignment folder are different from the zip file:\n");
    system(diffCommand);

    
    //removing aux directory; i.e: hashfolder
    //char *removefolderCommand = "rm -r hashfolder";
    
    system("rm -r hashfolder");

}


// //main function for testing
// int main()
// {
//     char assignmentFolderName[40];
//     char zipFolderName[40];

//     //take input string, for the file names.
//     scanf("%s %s", assignmentFolderName, zipFolderName);
    
//     compare(assignmentFolderName, zipFolderName);

//     return 0;
// }




