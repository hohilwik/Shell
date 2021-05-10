#ifndef __COMMANDS_
#define __COMMANDS_


//compare function
void makeAuxDirectory();
void compare(char assignmentFolderName[], char zipFolderName[]);

//submit function
void submit(char assignmentFolderName[]);

//switch function
int switchdir(char *directory);//returns 0 if successful -1 otherwise

//test function
char* DirPath();
int Test_file(char *fileName);  //return -2 if dist does not exist, -1 is /dist/file does not exist, and 0 if successful

//update function
int update(char *directory);
int updater(const char *directory, int mode);

//use function
void use(char assignmentFolderName[]);  
int getPath(char* path);  //returns 0 if successful, -1 otherwise 



#endif
