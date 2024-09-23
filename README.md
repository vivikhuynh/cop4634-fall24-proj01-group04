Project 1: myshell 

Members: Nini Huynh, Vivi Huynh 

Description: 
The purpose of myshell is to develop a lightweight shell that can manage background processes and input/output redirection in addition to receiving commands from the user, parsing them into an organized format, and executing them. This project focuses on process management and synchronization. 

Files: 
- myshell.cpp: implements the main shell functionality.
- parse.cpp: contains the command-line parsing logic.
- parse.hpp: defines the parsing functions and structures.
- param.cpp: implements the Param class for storing command parameters.
- param.hpp: defines the Param class and its methods.
- Makefile: Automates the build process.
- README.md: documentation for the project.

How to Compile:
1. Open a terminal and navigate to the project directory.
2. Run the command make to compile the project.
3. An executable named myshell will be created in the project directory. 

How to Run:
1. Run make -> ./myshell to start the shell in normal mode. 
2. If you want to run the shell in debug mode, run the following command: ./myshell -Debug
This will display additional debug information such as parsed tokens and redirection details. 
- 'ls' :list files in the current directory.
- 'ls > output.txt' :redirect the output of 'ls' to a file named 'output.txt'.
- 'cat < input.txt' :display the contents of 'input.txt'.
- 'cat < input.txt &' :display the contents of 'input.txt' in the background.
- './slow &' :run the slow program in the background.
3. To exit the shell, type 'exit' and press enter. 

Features: 
- Displays a custom shell prompt ('$$$').
- Accepts user commands until 'exit' is entered.
- Parses commands into tokens.
- Supports input ('<') and output ('>') redirection.
- Allows commands to run in the background ('&').
- Provides a debug mode that displays parsed command parameters. 