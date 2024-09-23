#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "parse.hpp"
#include "param.hpp"
using namespace std;

//display shell prompt 
void displayPrompt() { 
    //prints custom shell prompt to standard prompt
    cout << "$$$ "; 
}

int main(int argc, char *argv[]) {
    //Debug is enabled
    bool debug = (argc > 1 && strcmp(argv[1], "-Debug") == 0);
    Param params;
    string input;

    while (true) {
        displayPrompt();
        getline(cin, input);

        //exit condition
        if (input == "exit") {
            break;
        }

        //parse the input
        parseCommandLine(input, params);

        //print params in debug mode
        if (debug) {
            params.printParams();
        }

        // Create a new process
        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork Failed");
            continue; 
        }

        // Run in the child process
        if (pid == 0) {
            // Handle input redirection
            if (params.getInputRedirect()) {
                freopen(params.getInputRedirect(), "r", stdin);
            }
            // Handle output redirection
            if (params.getOutputRedirect()) {
                freopen(params.getOutputRedirect(), "w", stdout);
            }

            // Get the arguments to execute
            char** args = params.getArguments();

            execvp(args[0], args); // Replace the child process with the command to execute
            perror("Exec Failed");
            exit(EXIT_FAILURE);
        }
        else {
            // If the command is not background, wait for the child process to finish
            if (params.getBackground() == 0) {
                waitpid(pid, nullptr, 0);
            }
        }
    }

    // Collect any terminated child processes
    while (waitpid(-1, nullptr, WNOHANG) > 0);
    return 0;
} 