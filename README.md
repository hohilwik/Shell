# Assignment Shell

## Project Structure

There are 4 main directories:
* commands: Contains implementation of the commands. Eg: switch, create, etc.
* directoryfunc: Implemention of basic directory functionality. Eg: createDirectory.
* global: Header file to handle global variable.
* io: Handles the input and output of the project.
* installer.c : Builds the project.
* shell.c : Acts as the main function for the project. Handles calling all the functions for the commands, etc.


## Running the Code

### Clone the repo 
Clone the repo to your local machine using:
```
git clone https://github.com/hohilwik/Assignment_Shell_DSA_Project.git
```

### Compile 
Compile installer.c :
```
gcc installer.c -o installer
```
### Run
Run the executable:
```
./installer
```

<br>
<br>

Run the script below with the log files to see the output of the test played back in the terminal.

`scriptreplay --timing=assignmentName_logtime.txt assignmentName_log.txt`

This project maintains and stores log files. So this script uses the log files for the terminal session, and replays them like a video.

This keeps track of everything so that the log files can be sent to TAs for debugging. Moreover it also solves the issue the situation where the code is not worked, but was working previously. 


## Function Descriptions and Usage

Description of the functionality of each command and an example on how to use them.

* **switch \<subject\>** :  Changes the name of the subject  in  the  prompt  and  changes folders  appropriately.
	* Uses this function to switch directories:
	`int switchdir(char *directory)`
	
	* Returns a flag; to verify that the switch was successful:
	`flag=chdir(temp);`
	
	* Changes the subject directory in the shell prompt and changes the directory to the new one, accordingly.
	 **Usage**: 
	 ```bash 
	 switch <name_of_other_subject_folder>
	 ```  
	 
	Eg: 'switch DSA' would change the prompt from xyz/LA> to xyz/DSA> and navigate to the DSA folder.

* **create \<assignment\>** :   Creates  a  new  assignment folder. Puts the contents of the dist folder and the problem statement into this folder.
	
	* Prompts user to choose whether to download the assignment files (dist files, problem statements, etc) from a URL or to copy from a local directory
	* If URL is selected, asks input for URL and stores that in log file. 
	* If download from local directory is selected, asks input for absolute path of the local directory and stores that in log file.
	
	 (Because they are stored in log files, dont need to keep entering the URL or the directory path each time).
	* Creates a directory for the assignment files in the current working directory. 
	* (run the update command to update this directory with new assignment files)
	
	 **Usage**: 
	 ```bash 
	 create <name_for_the_Assignment_folder> 
	 ```
	Eg: 'create Assignment' will store the assignment files into a folder called 'Assignment'.

* **update \<assignment\>** :   Updates the assignment folder with the new assignment files. Deletes old files and replaces them with the new ones.

	* Prompts user to choose whether to download the assignment files from a URL or to copy from a local directory. (So can update from either, depending on the mode selected).
	* If URL is selected, reads the URL from the log file (that was created when we ran the create command). 
	(curl is used to download from the URL, then unzip and copy to the assignment folder)
	* If download from local directory is selected, reads the absolute path of the directory stored in the log file and copies it to the assignment folder.
	
	 **Usage**: 
	 ```bash 
	 update <name_of_the_Assignment_folder> 
	 ```
	 Eg: 'update Assignment' will update the files in the Assignment folder with the latest files.

* **test  \<assignment\>** :  Runs the submitter.py file in the  dist  folder.   Store  the  errors in a file.

	* This function obtains the directory path:
	`char* DirPath()`
	
	* And this function tests the file in the folder if it exists
	`int Test_file(char *fileName)`
	* Checks if submitter.py exists.
	* If it exists runs it on the Assignment to check if it works as expected.
	* Stores the results in a log file. This can be used to ensure that the Assignment works, or to store any possible errors that can then be used for debugging.
	
	 **Usage**: 
	 ```bash 
	 test <Assignment> 
	 ```
	 Eg: 'test Assignment' runs submitter.py on Assignment.
	
	
* **submit  \<assignment\>** : Makes a zip file of the assignment folder.
	Uses a system call to create a zip of the Assignment folder:
	
	`system(zipCommand);`
	
	The zip folder is stored in the current directory with the name \<assignment\>Zip.zip
	
	 **Usage**: 
	 ```bash 
	 submit <Assignment> 
	 ```
	 Eg: 'submit Assignment' creates a zip folder in the current working directory with the name \'AssignmentZip.zip'
	
	
* **compare \<my_assignment\> \<submitted_zipfile\>** : Compares the user\'s assignment folder (with their assignment files) with the submitted zip. 
	
	* Compare function takes the Assignment folder name and the zip file name as inputs. 
	* Does md5 hash on the files in both directories. Stores the hash in an auxilary folder using this function:

	`void makeAuxDirectory()`

	* Compares the hash to check if any of the files in the zip are different from any of the files in the assignment folder and prints a list of those files:

	`printf("\nThe following files in the assignment folder are different from the zip file:\n");`
    
	(deletes the auxilary folder at the end).

	 **Usage**: 
	 ```bash 
	 compare <my_Assignment> <my_submitted_AssignmentZip.zip> 
	 ```
	Eg: 'compare my_Assignment my_AssignmentZip.zip' will print a list of the all the files that are in the folder my_Assignment but not in (or different from) the folder my_AssignmentZip.zip
	
	
* **use \<assignment\>** : Changes the prompt to xyz/DSA/\<assignment\>. And for all subsequent commands, if the \<assignment\> argument is not passed, it will automatically use the current directory, i.e \<assignment\>.

	* The use function takes the Assignment folder name as input. 
	* It gets the complete path of the Assignment folder and stores it in a log file so that subsequent function calls can use it:
	`fprintf(fptr, "%s", cwdPath);`
	
	* The getPath function is called to get the absolute path to the Assignment folder:
	`int getPath(char* path)`
	
	 **Usage**: 
	 ```bash 
	 use <Assignment>
	 ```
	Eg: 'use Assignment' will change the prompt to xyz/DSA/Assignment> and every function call hereafter will be passed the default parameter \'Assignment\' if it is not provided. 

