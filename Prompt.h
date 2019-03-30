/* Prompt.h holds the headers for the prompt class
* created by Jason Pruim, for CS232 @ Calvin.edu
* March 30,2019
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <unistd.h>

using namespace std;

//declaration of prompt class and function stubs
class Prompt{
	private:
	char myFullPath[FILENAME_MAX];
	public:
	Prompt();
	~Prompt();
	string get() const; 
};
