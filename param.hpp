/**
 *  param.hpp
 *  
 *  Thomas Reichherzer
 *  Copyright 2009 UWF - CS. All rights reserved.
 *
 */

#ifndef _PARAM_HPP
#define _PARAM_HPP

/* Don't test program with more than this many tokens for input  */
#define MAXARGS 32

/* Class to hold input data                                  */
class Param
{
	private:
		char *inputRedirect;           /* file name or NULL            */
		char *outputRedirect;          /* file name or NULL            */
		int   background;              /* either 0 (false) or 1 (true) */
		int   argumentCount;           /* same as argc in main()       */
		char *argumentVector[MAXARGS]; /* array of strings             */
		
	public:
		
		/**
		 * Constructs an empty Param object.
		 */
		Param(); 
		~Param();
		
		/**
		 * Adds an argument string to the argument list in this object. This function
		 * does not create a string copy of the original string. 
		 * 
         * @param newArgument a new argument to be added to the argument list; 
		 *                    if NULL nothing will be added		 
         */
		void addArgument (char* newArgument);
		
		/**
		 * Returns an argument list referencing char* strings. The last element in the 
		 * list is NULL to mark the end of list elements. This makes the size of 
		 * the list one larger than the number of arguments added to this object.
		 * 
		 * Note: 
		 *   Caller must deallocate memory for the list.
		 */
		char** getArguments();
	
		// getter & setter functions
		
		/**
		 * Sets the filename for input redirection.
		 *
		 * @param newInputRedirect a string specifying the input redirect filename
		 */
		void setInputRedirect(char *newInputRedirect);
		
		/**
		 * Sets where the output should go.
		 * 
		 * @param newOutputRedirect a string with the filename where output should be saved.
		 * 							If it's NULL, it means no file is set for output.
		*/
		void setOutputRedirect(char *newOutputRedirect);
		
		/**
		 * Sets whether the command should run in the background.
		 * 
		 * @param newBackground an integer value. Use 1 to run the command in the background, or 0 to run it in the foreground.
		 */ 
		void setBackground(int newBackground);
		
		/**
		 * Returns the filename for input redirection.
		 *
		 * @return a string representing a filename
		 */
		char* getInputRedirect();
		
		
		/**
		 * Gets the filename where the output is directed.
		 * 
		 * @return the filename where the output will be saved, or NULL if no file is set.
		*/
		char* getOutputRedirect();
		
		/**
		 * Checks if the command should run int he background.
		 * 
		 * @return 1 if the command is set to run in the background, 0 if not.
		*/
		int getBackground();

		/**
		 * Prints the information in the specified structure to standard out.
         */
		void printParams();

		/**
		 * Resets the Param object to its initial state. 
 		 * Any dynamically allocated memory for arguments will be properly deallocated.
 		*/
		void reset();

};

#endif
