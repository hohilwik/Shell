#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
  system("make clean");
  system("make install");
//TODO finish this
//not sure how to specify which makefile it is using
  system("sudo apt install curl");
//can add other dependencies later
  
  return 0;
  
}
