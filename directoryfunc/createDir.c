#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int doesFileExist(const char *path)
{
    if (access(path, F_OK) == -1)
       { return -1; } //returns -1 if it doesn't exist

    return 1;
}
int createDir(char *dirname)
{
    const char *newdirname = dirname;
    char currdir[512];
    getcwd(currdir, sizeof(currdir));
    strcat(currdir, "/" );
    int flag=doesFileExist(strcat(currdir, newdirname)); 
    //if file exists then flag=1
    if(flag==1){ return 1; }
    
    int check = mkdir(newdirname, S_IRWXU);
    return check;
   //if successful, return 0, if permission denied or name too long, return -1
   //if directory already exists, return 1
  
   
}
