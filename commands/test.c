#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

#if defined(_MSC_VER)
#include <direct.h>
#define getcwd_getcwd
#elif defined(__GNUC__)
#endif

#include "test.h"

//This program tests if a folder/file exists in a given directory when given an input
/*for a particular file submitter.py if the file is indeed present in the directory
   then it will be compiled and run*/ 

//1. Given input of the file location is tokenized then is given input to this file
//2. The tokenized folder/filename is feeded to Test_file() function
//3. We obtain the path of the present directory using Dirpath() function
//4. We obtain the possible path of the required file/folder by merging strings
//5. By using the obtained path we check if the file exists/not using DoesFileExists() function
//6. If the folder exists we open it to check for the file in it
//7. If the file exists we execute the file using system() function
 
//checks if file/folder exists
int doesFileExist(const char* path)
{
    int val;
    
    /*access() will take the path of the file/folder to be checked and F_OK will check for the file existence */
    if(access(path ,F_OK) == -1){
        val = -1;//folder/file doesn't exist 
    }
    else
        val = 1;//folder/file exists
    
    return val;
}

//obtains directory path
char* DirPath()
{
    char* path_string;
    
    //getcwd returns the path of the current directory as a string if it exists 
    if((path_string = getcwd(NULL,0)) != NULL){
        return path_string;
        free(path_string);
    }
    return path_string;
}

//Tests the file in the folder if it exists
void Test_file(char* fileName)
{
/*Merging strings to get the possible directory path of the required file/folder*/
    char* new =strcat(DirPath(),"/");
    char* path =strcat(new,fileName);
    
    //the function returns 1 if file/folder exists -1 if it doesn't exist
    int dir = doesFileExist(path);
    if(dir == 1){
        /*if the path belongs to a folder we need to check for the existence of the file in that folder.
        So we open the folder using its path*/ 
        opendir(path);
        if(fileName == "submitter.py"){
            //using system() function to communicate with the terminal to execute the file if it exists
            system("python3 submitter.py");
        }
    }
}
