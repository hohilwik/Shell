#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//system files
#include <dirent.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

int update(char *directory)
{
	int flag=0, mode;
	prompt();
	printf("How would you like to update?\n");
	printf("Enter 0 for local file, 1 for downloading from URL");
	scanf("%d", &mode);
	updater(directory, mode);
	return flag;
}

int updater(const char *directory, int mode)
{
	int flag=0;
	if(mode==0) //locally
	{
		//read directory path from file
		char filename[1024];       //store file name
		strcpy(filename, directory);
		strcat(filename, "_path_log.txt");
		char line[1024];  //define length as needed
		FILE *fptr;
		fptr = fopen(filename, "r");
		if (fptr == NULL)
		{
			printf("Error opening path_log file");
			flag=8;
		}

		fgets(line, 1024, fptr);
		fclose(fptr);
		copyDir(line, directory); 
	}
	else if(mode==1) //download
	{
		//read URL from file
		char filename[1024];       //store file name
		strcpy(filename, directory);
		strcat(filename, "_URL_log.txt");
		char line[1024];  //define length as needed
		FILE *fptr;
		fptr = fopen(filename, "r");
		if (fptr == NULL)
		{
			printf("Error opening path_log file");
			flag=9;
		}
		fgets(line, 1024, fptr);
		fclose(fptr);
		char curlCall[1024];
		strcpy(curlCall, "curl -L -o dist.zip ");
		strcat(curlCall, line);
		system(curlCall);
		//some curl code as a syscall
		//some copyDir command after unzip syscall 
		//copyDir( , directory);
	}
	return flag;
}
