#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//system files
#include <dirent.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

int main()
{
	init();
	char input[1024], directory[1024], extra[1024], path[1024];
	int command, use_flag=0, dir_flag, oneword;
	while(1)
	{
		prompt(use_flag);
		scanf("%s", input);
		command= -1;
		dir_flag=0;
		oneword=0;
		if(strcmp(input, "switch")==0)	{ command=0; }
		if(strcmp(input, "create")==0)	{ command=1; }
		if(strcmp(input, "update")==0)	{ command=2; }
		if(strcmp(input, "setup")==0)	{ command=3; }
		if(strcmp(input, "test")==0)	{ command=4; }
		if(strcmp(input, "submit")==0)	{ command=5; }
		if(strcmp(input, "compare")==0)	{ command=6; }
		if(strcmp(input, "use")==0)		{ command=7; }
		if(strcmp(input, "cd")==0)		{ command=8; }
		if(strcmp(input, "pwd")==0)		{ command=9;  oneword=1; }
		if(strcmp(input, "ls")==0)		{ command=10; oneword=1; }
		if(strcmp(input, "date")==0)	{ command=11; oneword=1; }
		if(strcmp(input, "printdir")==0){ command=12; oneword=1; }
		if(strcmp(input, "exit")==0)	{ command=13; oneword=1; }
		
		
		if( oneword==0 )
	   {
		if(command!= -1 && use_flag==0 )
		{ scanf(" %s", directory); }
		else if(command== -1)
		{ scanf(" %[^\n]s", directory); }
	   }
		
		if(use_flag==0)
		{ dir_flag=getcwd(path, sizeof(path) ); }
		else if(use_flag==1 && (command!=0 && command!=1 && command!=3 && command!=7 && command!=-1 )  )
		{
			dir_flag=getPath(path);  
			strcpy(directory, path);
		}
		
		if(dir_flag== -1)
		{ 
			printf("Error getting path\n");
			continue;
		}
		
		switch(command)
		{
			case 0: //switch
			switchdir(directory);
			break;
			
			case 1: //create
			create(directory);
			break;
			
			case 2: //update
			update(directory);
			break;
			
			case 3: //setup
			setup(directory);
			break;
			
			case 4: //test
			dir_flag=chdir(directory);
			if(dir_flag==-1){ printf("Directory does not exist\n"); continue; }
			char fileName[50];
			strcpy(fileName, "submitter.py");
			dir_flag=Test_file(fileName);
				if(dir_flag==-2)		{ printf("dist folder does not exist\n"); }
				else if(dir_flag==-1)	{ printf("dist/%s does not exist\n", fileName); }
			break;
			
			case 5: //submit
			submit(directory);
			break;
			
			case 6: //compare
			scanf(" %s", extra);
			compare(directory, extra);
			break;
			
			case 7: //use
			use_flag=1;
			use(directory);
			break;
			
			case 8: //cd 
			dir_flag=chdir(directory);
			if(dir_flag== -1){ printf("Directory does not exist\n"; }
			break;
			
			case 9: //pwd 
			printf("\n%s\n", path);
			break;
			
			case -1: //system 
			strcat(input, " ");
			strcat(input, directory);
			system(input);
			break;
			
			case 10: //ls
			system("ls");
			break;
			
			case 11: //date
			system("date");
			break;
			
			case 12: //printdir 
			printDir(directory);
			break;
			
			case 13: //exit 
			exit(0);
			break;
			
			
			
		}
	
	
	}
	return 0;
}

