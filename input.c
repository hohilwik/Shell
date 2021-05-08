#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 

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


//void tokenizer

int main(){
    init();
    char *user = getenv("USER");
    long long int i=0;
    while(!i){
        char inpt[1024];
        char dire[1024]; 
        int a;
         getcwd(dire, sizeof(dire));
        printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, user);
        printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, dire);
        fgets(inpt,1024,stdin);
        
        //tokenizer(inpt); send this inpt string to tokenizer
        }
    return 0;
}