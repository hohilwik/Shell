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
    
printf(ANSI_COLOR_CYAN"                                               ..,.oooE777999V(;\n");
printf(ANSI_COLOR_CYAN"                                  ...oooP779090(;''       ''''  I\n");
printf(ANSI_COLOR_CYAN"                    ...ooB777979V;;''       .....=v}}=}=}=}}v==  5\n");
printf(ANSI_COLOR_CYAN"               97?(;''     .........<<vvvv<vvvvvvvvvvvvvvv}}}}v} L\n");
printf(ANSI_COLOR_CYAN"               ,   ..;;`;;;;;<;<<<<<<<<<<<<<v<vvvvvvvvvv}vv}}}}}. 1\n");
printf(ANSI_COLOR_CYAN"               b (:::``;;;;;;;;;;;<;<;<<<<<<<<<<<<v<v<vvvvvvvv}v}, E\n");
printf(ANSI_COLOR_CYAN"               `J ::.:.:.``;;;;;;;;;;;<;;;<<<<<<<<<<<<v<v<vvvvvvvx L\n");
printf(ANSI_COLOR_CYAN"                L  :. :.:.:.:.``;;;;;;;;;;;;;;<;<<<<<<<<<<v<<v<vv<( T\n");
printf(ANSI_COLOR_CYAN"                `> .    . .:.:.:.:.`:;``;;;;;;;;<;;;<;<<<<<<<<<<<v< >\n");
printf(ANSI_COLOR_CYAN"                 b ;           . : .:.:.:.`;;;;;;;;;;;<;;<;<<<<<<<<, I\n");
printf(ANSI_COLOR_CYAN"                 `,`               . : :.:.:.:.`.`;;;;;;;;;;;;<;<;<<. 5\n");
printf(ANSI_COLOR_CYAN"                  b ;                    . : .:.:.:.`;;;;;;;;;;;<;<;<: E\n");
printf(ANSI_COLOR_CYAN"                  `,<                         . . .:.:.:.``;;;;;;;;;;. I\n");
printf(ANSI_COLOR_CYAN"                   b :                             . . :.:.:.:.:.:.;;;. 5\n");
printf(ANSI_COLOR_CYAN"                   `>;                                  . .:..:.:.:.`.:  |\n");
printf(ANSI_COLOR_CYAN"                    b :                                      . . :.:.:.x T\n");
printf(ANSI_COLOR_CYAN"                    `,;                                          . . .::  E\n");
printf(ANSI_COLOR_CYAN"                     b :                                               _  !4\n");
printf(ANSI_COLOR_CYAN"                     `r :                                   __.__,--,;'))))).\n");
printf(ANSI_COLOR_CYAN"                      b :                         ___...--'; `))))))))' '' `>!9eOc\n");
printf(ANSI_COLOR_CYAN"                      `r :              __,--:-;;;)))))))))))'' '' ' ' _. -'-'.`!9Eg.\n");
printf(ANSI_COLOR_CYAN"                       L : . __.--_--:,)))))))))))'' ' '  _. ._.-'-'-'-'\-'\---\/\ ``Qu.\n");
printf(ANSI_COLOR_CYAN"                       `,: !x;:)))))))) ')'' ' _ _._-.'\'\_\_-'\''-\'_'\-'\'\ -_\'-\-. 95n.\n");
printf(ANSI_COLOR_CYAN"                        D` ))))'''  _ .___.-_:/-/\/-_\ /-_, /-,\ \-/_\/\,-\_/-\/-/--' ..v<]9o.\n");
printf(ANSI_COLOR_CYAN"                      __b :<> -_\._/\,- ,_ -\ _/\-\ _-\ -_/-\,\/,-/\_/-_\'\--' .vvvvvvv}v}}x}]NEo.\n");
printf(ANSI_COLOR_CYAN"                .ooPO%LOCu  `< `/\_ -:\/_/-/,\/,/-,/_,-/\ :_\:_-:__-'' ...vvvvvvvvvvvvxx}vx}}}}==No\n");
printf(ANSI_COLOR_CYAN"              .oPO'       `y. `< ~-\ _\/\_,- \ , - ,___..--' .......>>vvvvvvvvx<xvvxx}=x===}~^^   I\n");
printf(ANSI_COLOR_CYAN"        om3jR&57'          `Ey, `\ `!,\ \-/_/\_---''.......vv>>vvvvvvvvvv)v<xvx=}=<~~^~`       :_yd\n");
printf(ANSI_COLOR_CYAN"    _.rq8'                    `L, `<_ `--'.......vv<<<<v<<<<x<vv<vvvvxxxx=>~~~`         iuuuaE'\n");
printf(ANSI_COLOR_CYAN"  .@tTL'                        `y,  `< .-vvv<<<<<<<<<xxvx>vvvvv=>~~~~`         _uuua'''\n");
printf(ANSI_COLOR_CYAN".&P'                              `L,  `>>><<<<><>v<vvvvvx~`::`       ::_uuua'''\n");
printf(ANSI_COLOR_CYAN"                                    `y,  `:F_P:<x>~>^` `        _uuug'\n");
printf(ANSI_COLOR_CYAN"                                      `L,  ~~`          _uuua''\n");
printf(ANSI_COLOR_CYAN"                                        `L,:    _uuua''\n");
printf(ANSI_COLOR_CYAN"                                          `LaE''\n"ANSI_COLOR_RESET);


    printf("\n**************************************\n");
    printf(ANSI_COLOR_BLUE "\n\t\tAssignment Shell\n" ANSI_COLOR_RESET);
    printf("\n**************************************\n");
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
