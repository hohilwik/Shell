#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//system files
#include <dirent.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

int create(char *directory)
{
	int flag=0, mode;
	flag=createDir(directory);
	if(flag==1){ printf("Directory already exists!\n"); }
	else if(flag== -1){ printf("Could not create directory\n"); }
	else if(flag== 0)
	{
		//
		printf("Enter the URL from where the relevant files are to be fetched/>");
		prompt(0);
		writelogger(directory, 1);
		printf("Enter the absolute address of local directory from which files are to be fetched/>");
		prompt(0);
		writelogger(directory, 0);
		//write to log file for future use
		//yes there are different log files for each of them, fight me 
		
	}
	return flag;
	
	
}

int writelogger(char* directory, int mode)
{	
	int flag=0;
	if(mode==0) //locally
	{
		//write directory path to file
		char filename[1024];       //store file name
		strcpy(filename, directory);
		strcat(filename, "_path_log.txt");
		char line[1024];  //define length as needed
		FILE *fptr;
		fptr = fopen(filename, "w");
		if (fptr == NULL)
		{
			printf("Error opening path_log file");
			flag=8;
		}
		scanf("%s", line);
		fprintf(line, "%s", fptr);
		fclose(fptr);
		copyDir(line, directory); 
	}
	else if(mode==1) //download
	{
		//write URL to file
		char filename[1024];       //store file name
		strcpy(filename, directory);
		strcat(filename, "_URL_log.txt");
		char line[1024];  //define length as needed
		FILE *fptr;
		scanf("%s", line);
		fptr = fopen(filename, "w");
		if (fptr == NULL)
		{
			printf("Error opening URL_log file");
			flag=9;
		}
		fprintf(line, "%s", fptr);
		fclose(fptr);
	}
	return flag;
}
