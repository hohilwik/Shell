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

* switch \<subject\>:  Changes the name of the subject  in  the  prompt  and  changes folders  appropriately.
Eg: switch DSA, would change the prompt from xyz/LA> to xyz>DSA and navigate to the DSA directory.

* create \<assignment\>:   Creates  a  new  assignment folder. Puts the contents of the dist folder and the problem statement into the current directory.
Eg: create Assignment

* update \<assignment\>:   Updates with the new assignment files. Deletes old files and replaces them with the new ones.
Eg: update Assignment

* test  \<assignment\>:  Runs the submitter file in the  dist  folder.   Store  the  errors in a file.
Eg: test Assignment

* submit  \<assignment\>: Makes a zip file of the assignment folder.
Eg: submit Assignment

* compare \<assignment\> \<zipfile\>: Compares assignment folder with the submitted zip. 

Compare function takes the Assignment folder name and the zip file name as inputs. Does md5 hash on the files in both directories. Stores the hash in an auxilary folder using this function:

`void makeAuxDirectory()`

compares the hash to check if any of the files in the zip are different from any of the files in the assignment folder and prints a list of those files:

`printf("\nThe following files in the assignment folder are different from the zip file:\n");
    system(diffCommand);`
    
(deletes the auxilary folder at the end).

Eg: compare Assignment AssignmentZip.zip

* use \<assignment\>: Changes the prompt to xyz/DSA/\<assignment\>. And for all subsequent commands, if the \<assignment\> argument is not passed, it will automatically use the current directory, i.e \<assignment\>.

The use function takes the Assignment folder name as input. It gets the complete path of the Assignment folder and stores it in a log file so that subsequent function calls can use it.
Eg: use Assignment

