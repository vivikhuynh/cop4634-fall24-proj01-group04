Project 1: myshell 

Members: Nini Huynh, Vivi Huynh 

Desciption: 
This project implements a simplified shell program that reads commands from the user, parses them, and executes them. It supports input/output redirection, background execution, and can handle a maximum of 32 arguments.

Files: 
- myshell.cpp: The main shell loop, handling user input and managing debugging output.
- parse.cpp: Implements the command line parser that breaks user input into tokens.
- parse.hpp: Exposes the functionality of the parser for the shell to use.
- param.cpp: Implements the Param class, responsible for storing the parsed input.
- param.hpp: Defines the Param class and its member funtions and data members.
- Makefile: Automates the build process for compiling and linking all source files. 

How to Compile:
1. Open a terminal and navigate to the project directory.
2. Run the command make to compile the project.
3. An executable named myshell will be created in the project directory. 

How to Run:
1. Run make -> ./myshell to start the shell in normal mode. 
2. If you want to run the shell in debug mode, run the following command: ./myshell -Debug
This will display additional debug information such as parsed tokens and redirection details. 
3. To exit the shell, type exit and press enter. 

Features: 
The shell supports background execution using the & character. When the & is placed at the end of the command, the shell will run the process in the background.
Input and output redirection are supported using < for input file and > for output files.
Example command: command < inputfile > outputfile &
This command executes command with input from inputfile and writes the outputfile, all in the background. 
