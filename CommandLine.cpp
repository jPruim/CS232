#include "CommandLine.h"


/*
 * Purpose: Construct a CommandLine by reading a command-line from in,
 *          parsing it, and building instance variables for argc and argv
 *          (you may find the calloc() and free() system calls to be of use here).
 * Inputs: istream& in
 * Outputs:
 *
 */
CommandLine::CommandLine()
{
	// calloc(): Allocates a block of memory for an attay of num elements,
	// 				  each of them size bytes long, and inits all bits to zero
	// free(): returns memory to the system
	argc = 0;
	argv = NULL;
}

/*
 * Purpose: Construct a CommandLine by reading a command-line from in,
 *          parsing it, and building instance variables for argc and argv
 *          (you may find the calloc() and free() system calls to be of use here).
 * Inputs: istream& in
 * Outputs:
 *
 */
CommandLine::CommandLine(std::istream &in)
{
	// calloc(): Allocates a block of memory for an attay of num elements,
	// 				  each of them size bytes long, and inits all bits to zero
	// free(): returns memory to the system

//	argc = 0;					  	// init argc
//	int const size = 256; 		  	// default size for input char array
//	char ** ArgVector = new char*[size]; // init dummy argv
//	for(int i = 0; i < size; i++){ArgVector[i] = 0;};
//	char* input= new char[size]; 	// input char array
//	char* point;
//
//	in.getline(input, size); // grab input
//	if(input != NULL)
//	{
//		point = strtok(input, " "); // create pointer
//
//		while(point != NULL)
//		{
//			ArgVector[argc] = point; 	// set argv to proper command
//			argc++; 					// increment argc
//			point = strtok(NULL, " ");	// move pointer
//		}
//	}
//
//	argv = ArgVector;
	const int size = 256;
	char* input= new char[size];
	char* point;
	argc = 0;
	argv = (char**)calloc(size,sizeof(char*));
	in.getline(input, size); // grab input
	if(input != NULL)
	{
		point = strtok(input, " "); // create pointer

		while(point != NULL)
		{
			argv[argc] = string(point).c_str(); 	// set argv to proper command
			//cout<<point<<endl;
			argc++; 					// increment argc
			point = strtok(NULL, " ");	// move pointer
		}
	}
}



CommandLine::~CommandLine() {
	//delete[] argv; // deallocates the Arg Vector (however it auto deallocates so nothing to be deleted, causes an error
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
		string s = argv[i];
		if (s == "&")
		{
			noAmp=false;
		}
	}
	return noAmp;
}

string CommandLine::toString(){
	for(int i = 0; i < argc; i++){
		cout<<"-"<<argv[i]<<"-"<<endl;
	}
}
