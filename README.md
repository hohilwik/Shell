# Assignment Shell

## Running the Code

//add info about cmake, etc here

Run the script below with the log files to see the output of the test played back in the terminal.

`scriptreplay --timing=assignmentName_logtime.txt assignmentName_log.txt`

## Project Structure

There are 4 directories:
* commands: Contains implementation of the commands. Eg: switch, create, etc.
* directoryfunc: Implemention of basic directory functionality. Eg: createDirectory.
* global: Header file to handle global variable.
* io: Handles the input and output of the project.

## Function Descriptions and Usage

Description of the functionality of each command and an example on how to use them.

* **switch \<subject\>** :  Changes the name of the subject  in  the  prompt  and  changes folders  appropriately.
	`flag=chdir(temp);`
	(returns flag; to verify if switch was successful).
	
	Eg: switch DSA, would change the prompt from xyz/LA> to xyz>DSA and navigate to the DSA directory.

* **create \<assignment\>** :   Creates  a  new  assignment folder. Puts the contents of the dist folder and the problem statement into the current directory.
	
	Asks input for URL, stores that in log file.
	Asks input for local location, stores that in log file.
	Creates directory
	run update command
	
	Eg: create Assignment

* **update \<assignment\>** :   Updates with the new assignment files. Deletes old files and replaces them with the new ones.

	choose whether locally or to download
	if locally ( access log file with the location and copy that directory )
	else if download ( use curl to download, then unzip, and copy to directory )
	
	Eg: update Assignment

* **test  \<assignment\>** :  Runs the submitter file in the  dist  folder.   Store  the  errors in a file.

	This function obtains the directory path:
	`char* DirPath()`
	
	And this function tests the file in the folder if it exists
	`int Test_file(char *fileName)`
	
	Eg: test Assignment

* **submit  \<assignment\>** : Makes a zip file of the assignment folder.
	Uses a system call to create a zip of the Assignment folder:
	
	`system(zipCommand);`
	
	Eg: submit Assignment

* **compare \<assignment\> \<zipfile\>** : Compares assignment folder with the submitted zip. 

	Compare function takes the Assignment folder name and the zip file name as inputs. Does md5 hash on the files in both directories. Stores the hash in an auxilary folder using this function:

	`void makeAuxDirectory()`

	compares the hash to check if any of the files in the zip are different from any of the files in the assignment folder and prints a list of those files:

	`printf("\nThe following files in the assignment folder are different from the zip file:\n");
    system(diffCommand);`
    
	(deletes the auxilary folder at the end).

	Eg: compare Assignment AssignmentZip.zip

* **use \<assignment\>** : Changes the prompt to xyz/DSA/\<assignment\>. And for all subsequent commands, if the \<assignment\> argument is not passed, it will automatically use the current directory, i.e \<assignment\>.

	The use function takes the Assignment folder name as input. 
	It gets the complete path of the Assignment folder and stores it in a log file so that subsequent function calls can use it:
	`fprintf(fptr, "%s", cwdPath);`
	
	The getPath function is called to get the absolute path to the Assignment folder:
	`int getPath(char* path)`
	
	Eg: use Assignment

