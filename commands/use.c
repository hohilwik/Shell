#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>


//**********************************************************************************//
// FUNCTION DESCRIPTION
// The use function takes the Assignment folder name as input
// gets the complete path of the Assignment folder and stores it in a log file

//The getPath function takes an input string. Reads the Assignment folder path from the log file
//and writes it to the input string. 

// USAGE: use <assignmentFolderName>
// eg: use Assignment

// TODO:
// more extensive testing is needed
// some extra error handling can be added as required (input validation, etc)
// add output messages for the user as required

//NOTE: The auxilary file (i.e the log file that stores the path) needs to be deleted 
//at the end of the main function of the project
//******************************************************************************//



void use(char assignmentFolderName[])
{
    char cwdPath[PATH_MAX];

    if (getcwd(cwdPath, sizeof(cwdPath)) == NULL)
    {
        printf("Could not get current working directory path.");
        return;
    }
    // //testing
    // else
    // {
    //     printf("%s\n", cwdPath);
    // }

    strcat(cwdPath, "/");
    strcat(cwdPath, assignmentFolderName);    //adding the Assignment folder name to the path

    // //testing
    // printf("%s\n", cwdPath);

    //creating log file
    FILE *fptr;

    fptr = fopen("path.txt", "w");

    if (fptr == NULL)
    {
        printf("Error; could not create path.txt");
        //exit(1);
        return;
    }

    fprintf(fptr, "%s", cwdPath);
    fclose(fptr);
}


int getPath(char* path)
{
    //reading path from the log file

    char cwdPath[PATH_MAX];

    FILE *fptr;

    fptr = fopen("path.txt", "r");

    if (fptr == NULL)
    {
        printf("Error; could not get path from path.txt");
        //exit(1);
        return -1;
    }

    fscanf(fptr, "%s", cwdPath);
    
    // //testing
    //printf("%s\n", cwdPath);

    fclose(fptr);

    strcpy(path, cwdPath);   //copying path into input string
    return 0;
}

// for testing
// int main()
// {
//     char assignmentFolderName[40];
//     char path[PATH_MAX];

//     //take input string, for the assignment folder name.
//     scanf("%s", assignmentFolderName);

//     use(assignmentFolderName);

//     getPath(path);

//     // //testing
//     //printf("%s\n", path);

//     return 0;
// }
