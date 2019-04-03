/*
 * Title: JMShell.h
 * Course: CS 232 Operating Systems
 * Professor: Joel Adams
 * Date: April 2, 2019
 * Author: Micah Bonewell
 * Team: Jason Prium & Micah Bonewell
 *
 */

#ifndef JMSHELL_H_
#define JMSHELL_H_

#include "Path.h"
#include "Prompt.h"
#include "CommandLine.h"
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>



using namespace std;

class JMShell {
	private:
	Path myPath;
	Prompt myPrompt;
	//CommandLine *CL;

	public:
	void analyzeFun(CommandLine *commL, string cmd);
	string shellPromptFormat();
	JMShell();
	void systemComm(CommandLine *CL, int index);
	virtual ~JMShell();
	void run();
};

#endif /* JMSHELL_H_ */
