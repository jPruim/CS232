/*
 * Title: CommandLine.h
 * Course: CS 232 Operating Systems
 * Professor: Joel Adams
 * Date: April 2, 2019
 * Author: Micah Bonewell
 * Team: Jason Prium & Micah Bonewell
 *
 */

#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <iostream> // istream
#include <stdlib.h> // calloc, exit, free
#include <cstring> // strlen
#include <string>
#include <iostream>

using namespace std;
class CommandLine
{	
	public:
	CommandLine();
	CommandLine(std::istream &in);
	~CommandLine();
	char* getCommand() const;
	int getArgCount() const;
	char** getArgVector() const;
	char* getArgVector(int i) const;
	bool noAmpersand() const;
	private:
	int argc;
	char** argv;
	string myInput;
};

#endif /* COMMANDLINE_H_ */
