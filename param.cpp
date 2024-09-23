#ifndef _PARAM_CPP
#define _PARAM_CPP

#include <iostream>
#include <cstring> //memory manipulation functions
#include "param.hpp"
using  namespace std;

//initializes a new Param object 
Param::Param() 
{
	inputRedirect = outputRedirect = nullptr;
	background = 0;
	argumentCount = 0;

	// Initialize the list of arguments to be empty
	for (int i = 0; i < MAXARGS; ++i) {
		argumentVector[i] = nullptr;
	}
}

// Destructor cleans up memory when the obkect is no longer needed
Param::~Param() {
	// Free the memory used for storing input and output file paths
	delete[] inputRedirect;
	delete[] outputRedirect;

	// Remove all stored arguments
	for (int i = 0; i < argumentCount; ++i) {
		delete[] argumentVector[i];
	}
}

void Param::addArgument (char* newArgument)
{
	// Check if there is space for a new argument and that it's not null
	if (argumentCount < MAXARGS && newArgument != nullptr) {
		// Create a copy of the new argument and store it in the list
		argumentVector[argumentCount] = new char[strlen(newArgument) + 1];
		strcpy(argumentVector[argumentCount], newArgument);
		++argumentCount;
	}
}

char** Param::getArguments() 
{
	// Create a new array to hold the arguments
	char** args = new char*[argumentCount + 1];
	// Copy each argument from the list to the new array
	for(int i = 0; i < argumentCount; i++) {
		args[i] = new char[strlen(argumentVector[i]) + 1];
		strcpy(args[i], argumentVector[i]);
	}
	args[argumentCount] = nullptr;
	return args;
}

void Param::setInputRedirect(char *newInputRedirect)
{
	// Free the old memory if it was allocated
	delete[] inputRedirect;
	// Allocate memory for the new input file path and copy it
	if (newInputRedirect != nullptr) {
		inputRedirect = new char[strlen(newInputRedirect) + 1];
		strcpy(inputRedirect, newInputRedirect);
	}
	else {
		inputRedirect= nullptr;
	}
}

void Param::setOutputRedirect(char *newOutputRedirect)
{
	delete[] outputRedirect;
	if (newOutputRedirect != nullptr) {
		outputRedirect = new char[strlen(newOutputRedirect) + 1];
		strcpy(outputRedirect, newOutputRedirect);
	}
	else {
		outputRedirect= nullptr;
	}
}
		
void Param::setBackground(int newBackground)
{
	background = newBackground;
}

char* Param::getInputRedirect()
{
	return inputRedirect;
	
}
		
char* Param::getOutputRedirect()
{
	return outputRedirect;
	
}
		
int Param::getBackground()
{
	return background;
}


void Param::printParams() {
    cout << "InputRedirect: [" 
         << (inputRedirect != nullptr ? inputRedirect : "NULL") 
         << "]" << endl;

    cout << "OutputRedirect: [" 
         << (outputRedirect != nullptr ? outputRedirect : "NULL") 
         << "]" << endl;

    cout << "Background: [" 
         << background 
         << "]" << endl;

    cout << "ArgumentCount: [" 
         << argumentCount 
         << "]" << endl;

    for (int i = 0; i < argumentCount; i++) {
        cout << "ArgumentVector[" 
             << i 
             << "]: [" 
             << (argumentVector[i] != nullptr ? argumentVector[i] : "NULL") 
             << "]" << endl;
    }
}

//resets the Param object to initial state
void Param::reset() {
	inputRedirect = outputRedirect = NULL;
	background = 0;
	for (int i = 0; i < argumentCount; ++i) {
		delete[] argumentVector[i];
	}
	argumentCount = 0;
}

#endif
