/* Prompt.h holds the headers for the prompt class
* created by Jason Pruim, for CS232 @ Calvin.edu
* March 30,2019
*/

#include "Prompt.h"

//constructor (declares myFullPath)
Prompt::Prompt(){
	getcwd(myFullPath, FILENAME_MAX);
}
//get()
//return the string from of path to current dir
string Prompt::get() const {
	return string(myFullPath);
}
//destructor
Prompt::~Prompt(){
	//everything self destructs
	//array is fixed size
}
