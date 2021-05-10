#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

#if defined(_MSC_VER)
#include <direct.h>
#define getcwd _getcwd
#elif defined(__GNUC__)
#endif

//#include "test.h"
#include "commands.h"
#include "directoryfunc/directoryfunc.h"

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
 

// //checks if file/folder exists
// int doesFileExist(const char* path)
// {
//     int val;
    
//     /*access() will take the path of the file/folder to be checked and F_OK will check for the file existence */
//     if(access(path ,F_OK) == -1){
//         val = -1;//folder/file doesn't exist 
//     }
//     else
//         val = 1;//folder/file exists
    
//     return val;
// }


//obtains directory path
char* DirPath()
{
    char path_string[1024];
    
    //getcwd returns the path of the current directory as a string if it exists 
    if( getcwd(path_string, sizeof(path_string) ) != NULL )
	{
        return path_string;
    }
    return -1;
}

//Tests the file in the folder if it exists
int Test_file(char *fileName)
{
    //concatenating strings to get the directory path of the required folder/file
    char dist[1024]= "./dist";
    char path[1024];
    strcpy(path, DirPath() );
    strcat(path, "/dist");
    int flag1=chdir(dist);
	if(flag1!=0)
	{ 
		return -2; //dist does not exist 
	}
    //the function returns 1 if file/folder exists -1 if it doesn't exist
	strcat(path, "/");
    int dir = doesFileExist( strcat(path, fileName ) );
      if(dir == 1)
      {
        /*if the path belongs to a folder we need to check for the existence of the file in that folder.
        So we open the folder using its path*/ 
            //using system() function to communicate with the terminal to execute the file if it exists
	char temp[1024]="python3 ";
	strcat(temp, fileName);
	//temp is now "python3 filename.py"
	int size=sizeof(fileName);
	for(int i=0; i<size; i++)
	{
		if(fileName[i]=='.'){ fileName[i]='_'; }
		//changing all the periods to underscores
	}
	char script[1024]="script --timing=";
	strcat(script, fileName);
	strcat(script, "_logtime.txt ");
	strcat(script, fileName);
	strcat(script, "_log.txt");
	//string becomes "script --timing=filename_py_logtime.txt filename_py_log.txt"
	//start logging
	system(script);
	//run the command
        system(temp);
	//stop logging
	system("exit");
      }
	  chdir("..");
	  chdir("..");
	return dir;
	//return -2 if dist does not exist, -1 is /dist/file does not exist, and 0 if successful
}

