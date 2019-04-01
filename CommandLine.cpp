
/*
 * Purpose: Construct a CommandLine by reading a command-line from in,
 *          parsing it, and building instance variables for argc and argv
 *          (you may find the calloc() and free() system calls to be of use here).
 * Inputs: istream& in
 * Outputs:
 *
 */
#include "CommandLine.h"

using namespace std;

CommandLine::CommandLine(std::istream &in)
{
	// calloc(): Allocates a block of memory for an attay of num elements,
	// 				  each of them size bytes long, and inits all bits to zero
	// free(): returns memory to the system
	char ** ArgVector = new char*; // init dummy argv
	argc = 0;					  	// init argc
	int const size = 256; 		  	// default size for input char array
	char* input = new char[size]; 	// input char array
	char* cmpr = new char[size];  	// comparison char array
	char *point;
	if (in)
	{
		in.getline(input, size); // grab input

		strcpy(input, cmpr); // compare strings

		point = strtok(cmpr, " "); // create pointer

		while(point != NULL)
		{
			ArgVector[argc] = point; 	// set argv to proper command
			argc++; 					// increment argc
			point = strtok(NULL, " ");	// move pointer
		}
	}

	argv = ArgVector;
	delete[] ArgVector;
	in.ignore();
}
#include "CommandLine.h"

/*
 * Purpose: Empty inital Constructor
 * Inputs: NULL
 * Outputs:
 *
 */
CommandLine::CommandLine()
{
	argc = 0;
	argv = NULL;
}



CommandLine::~CommandLine() {
	delete[] argv; // deallocates the Arg Vector
}

/*
 * Purpose: return a pointer to the command portion of the command-line (i.e., argv[0]).
 * Inputs: None
 * Outputs: char* argv[0]
 *
 */
char* CommandLine::getCommand() const
{
	return argv[0];
}

/*
 * Purpose:  return the number of command-line arguments on the command-line (i.e., argc).
 * Inputs: None
 * Outputs: int argc
 *
 */
int CommandLine::getArgCount() const
{
	return argc;
}

/*
 * Purpose: return a pointer to a char* array, each entry of which points to one 'word'
 *          of the command-line (i.e., argv).
 * Inputs: None
 * Outputs: char** arg
 *
 */
char** CommandLine::getArgVector() const
{
	return argv;
}

/*
 * Purpose: return a pointer to the ith (zero-relative) command-line 'word' (i.e., argv[i]).
 * Inputs: int i
 * Outputs: char* argv[i]
 *
 */

char* CommandLine::getArgVector(int i) const
{
	return argv[i];
}

/*
 * Purpose: returns true if and only if no ampersand was given on the command-line
 * Inputs: NA
 * Outputs: bool
 *
 */
bool CommandLine::noAmpersand() const
{
	bool noAmp = true;
	for(int i = 0; i++; i<argc)
	{
		if (argv[i] == "&")
		{
			noAmp=false;
		}
	}
	return noAmp;
}


