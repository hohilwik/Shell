#ifndef __COMMANDS_
#define __COMMANDS_


//compare function
void makeAuxDirectory();
void compare(char assignmentFolderName[], char zipFolderName[]);

//submit function
void submit(char assignmentFolderName[]);

//switch function
int switchdir(char *directory);

//test function
int doesFileExist(const char* path);
char* DirPath();
int Test_file(char *fileName);

//use function
void use(char assignmentFolderName[]);
void getPath(char* path);


#endif
