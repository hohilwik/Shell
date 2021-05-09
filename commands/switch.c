int switchdir(char *directory)
{
	int flag;
  //go to parent directory
	chdir("..");
	char temp[1024]="./";
	strcat(temp, directory);
  //now switch to the directory
	flag=chdir(temp);
	return flag;
	//0 if successful
	//-1 otherwise

}
