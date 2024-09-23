#include <iostream>
#include <sstream>
#include "parse.hpp"
#include "param.hpp"
using namespace std;

void parseCommandLine(const string &input, Param &params) {
    params.reset(); // Reset the Param object before parsing a new command

    istringstream stream(input);    // Read through the input string
    string token;

    //default values for input/output redirection 
    params.setInputRedirect(nullptr);
    params.setOutputRedirect(nullptr);
    params.setBackground(0);

    while (stream >> token) {
        // Ignore '$$$' token
        if (token == "$$$") {
            continue;
        }
        
        //handle input redirection 
        if (token == "<") {
            if (stream >> token) { // Read the next token from the command
                // Allocate memory (reserve a block of memory in computer's RAM) to store the filename.
                // +1 null terminator '\0' at the end of the string
                char* filename = new char[token.length() + 1];
                strcpy(filename, token.c_str());    // Copy filename from token into the allocated memory
                params.setInputRedirect(filename);    // Set the input redirect filename in the Param object. Tells the shell where to get input from
            }
            else {
                cerr << "Error: Input redirection '<' must be follow by a filename." << endl;
            }
        } 
        //handle output redirection
        else if (token == ">") {
            if (stream >> token) {
                //memory for the output file 
            char* filename = new char[token.length() + 1];
                strcpy(filename, token.c_str());
                params.setOutputRedirect(filename);
            }
            else {
                cerr << "Error: Output redirection '>' must be follow by a filename." << endl;
            }
        }
        //background execution 
        else if (token == "&") {
            params.setBackground(1);
        }
        else {
            //memory for the argument 
            char* arg = new char[token.length() + 1];
            strcpy(arg, token.c_str());
            params.addArgument(arg);
        }
    }
}
