#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>  
#include<sys/types.h> 
#include<sys/wait.h> 
#include<readline/readline.h> 
#include<readline/history.h> 

#if defined(_MSC_VER)
#include <direct.h>
#define getcwd _getcwd
#elif defined(__GNUC__)
#include <unistd.h>
#endif

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void init(){
    
    printf("\n\n\n**************************************\n\n\n\n");
    printf(ANSI_COLOR_BLUE "\n\t\tAssignment Shell\n" ANSI_COLOR_RESET);
    printf("\n\n\n**************************************\n\n\n\n");
    sleep(1);
    
}

int prompt(int flag)
{
    //init();
        int check=0;
        char *user = getenv("USER");
        char *inpt;
        char dire[1024]; 
        if(flag==0){ check=getcwd(dire, sizeof(dire)); }
        if(flag==1){ check=getPath(dire); }
        if(check==-1){ return check; }
        printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, user);
        printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, dire);
        pritnf("/>");
        //inpt = readline("/>");
        //add_history(inpt);
    //input gets returned to main 
    return check;
}