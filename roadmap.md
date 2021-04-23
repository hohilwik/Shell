# Roadmap

We need to have support for a few commands, and the functions required to run those commands effectively. 

There might be a bit of extra code involved that might seem unnecessary given the constraints, but it really helps streamline the process and makes the program more flexible and debugging easier.



## Commands

1. switch
2. create
3. update*
4. setup*
5. test
6. submit*
7. compare*
8. use

The ones which are non-trivial and would take more than two hours to implement are marked with asterisks. That might seem unreasonable right now but once the basic structure is built, a lot of these can be easily implemented

For update, we will need some extra work for getting the downloads, and possibly something to interact with Moodle, which can later be resused for submit without much change.

compare will require a few extra functions to use MD5, but a lot of the code for that is open-source, and even if we have to implement it ourselves, is less than 150 lines of code


## Functions and Modules

1. input- will handle all of the input
2. output- will handle all of the output
3. tokenizer- will take the input and split it into words/commands that can then be parsed
4. parser*- takes the commands given and converts them into function calls with given input
5. downloader*- used for the update, will need some Moodle integration
6. directory manager routines*- core of the folder management, many other functions will use this
7. folder structure parser*- not very complex but its functioning will affect everything else deeply, it will take the given folder structure and parse it into commands for the directory manager and mkdir
8. ASCII tree display- for displaying the folder structure as a tree so the user can check how things are and we can test if they are going right
9. MD5 hashing and checksums*- can copy code for this but best if this is written without bugs
10. logger- simple code to create and append log files, pretty important for a lot of the functioning
11. function caller- this will handle most of the function calls in one place, to make debugging easier and to make the code more flexible
12. backup commands- backs up files whenever there is an edit or something is deleted so that the user can go back to older files if need be. Logger is essential for this to work properly
13. password-manager- this will store the login information for Moodle in a usable format
14. moodle_submitter*- this will again use the Moodle integration in order to take the zipped files and submit them to Moodle. 


## Style Guide and Schedule

This is not a particularly long project, especially since we can use syscalls, although bugs might slow it down. Write good code from the start, and it will seriously cut down on the debug time. Add comments for everything your code does to make it more readable for the rest of the team, follow certain style considerations to make the code easier to manage. I'll explain soon what I mean by that. 

I'll be making the general structure for the program by 24th April, as in, all the files required, some of the functions and structures that are obvious to make right now, and we will add to it as time goes. 

I'll add to this section as we develop certain stylistic choices for the code, and we will be following the scrum routine as discussed for the project timeline management. If each member puts in 4 hours per sprint then we can get done with the whole thing in about a week. 

//TODO

