void copyDir(char *sourceDir, char *targetDir)
{
	char copyCommand[1024];
	strcpy(copyCommand, "cp -r ");
	strcat(copyCommand, sourceDir);
	strcat(copyCommand, " ");
	strcat(copyCommand, targetDir);
	//cp -r sourceDir targetDir 
	system(copyCommand);
	
	return;
}
