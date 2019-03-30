/* Prompt.h holds the headers for the prompt class
* created by Jason Pruim, for CS232 @ Calvin.edu
* March 30,2019
*/

#include "Prompt.h"

//constructor
//(declares myFullPath)
Prompt::Prompt(){
	getcwd(myFullPath, FILENAME_MAX);
}
//get() const
//return the string from of path to current dir (with added $)
string Prompt::get() const {
	return string(myFullPath)+"$";
}
//destructor
//deallocates memory, c++ does this automatically for everything involved
Prompt::~Prompt(){
	//everything self destructs
}
