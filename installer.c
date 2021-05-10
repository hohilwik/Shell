#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
  system("./build.sh");
//TODO finish this
//not sure how to specify which makefile it is using
  system("sudo apt install curl");
  system("./exe.out");
//can add other dependencies later
  
  return 0;
  
}
