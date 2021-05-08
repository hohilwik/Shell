#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "create.h"

void createdir(char dirname[])
{
    char directory[1024];
    DIR* direc = opendir(dirname);
    if(direc){
        //need to use the update command here 
        printf("direcory exists calling update function");
    }
    else if(direc==NULL){
        strcpy(directory, "mkdir ");
        strcat(directory, dirname);
        system(directory);
        
    }


}

/*int main(){
    //parer and tokenizer value need to be passed to the dirname[]
    //for testing purpose sending this example dir name(DSA)
    char direc[1024] = "DSA";
    createdir(direc);    
    return 0;
}*/
