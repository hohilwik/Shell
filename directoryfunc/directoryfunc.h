#ifndef __DIRFUNC_
#define __DIRFUNC_

//copyDir
void copyDir(char *sourceDir, char *targetDir);

//createDir
int doesFileExist(const char *path);  //returns -1 if it doesn't exist
int createDir(char *dirname);   //if successful, return 0, if permission denied or name too long, return -1, if directory already exists, return 1

#endif

