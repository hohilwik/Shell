#include <unistd.h>
#include <stdlib.h>

#include <dirent.h>
#include <errno.h>

#include <string.h>

#include <stdio.h>

//**********************************************************************************//
// FUNCTION DESCRIPTION
// Submit function takes the Assignment folder name as input
// Zips the folder and stores it with the name 'AssignmentZip.zip', in the local directory

// USAGE: submit <assignmentFolderName>
// eg: submit Assignment

// TODO:
// add error handling (input validation, etc)
// add output messages for the user 
//******************************************************************************//


void submit(char assignmentFolderName[])
{

    //zip the Assignment folder
    char zipCommand[1024];
    char assignment[1024];
    strcpy(assignment, assignmentFolderName);
    strcat(assignment, "Zip.zip ");
    strcpy(zipCommand, "zip -r ");
    strcat(zipCommand, assignment);
    strcat(zipCommand, assignmentFolderName);    //eg: "zip -r AssignmentZip.zip Assignment";

    system(zipCommand);

}


// //main function for testing
// int main()
// {
//     char assignmentFolderName[40];

//     //take input string, for the file name.
//     scanf("%s", assignmentFolderName);
    
//     submit(assignmentFolderName);

//     return 0;
// }


