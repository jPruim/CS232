/*
 * JMShell.cpp
 *
 *  Created on: Apr 1, 2019
 *      Author: mjb88
 */

#include "JMShell.h"

using namespace std;

JMShell::JMShell() {
	//cout<<"Started JMShell constructor"<<endl;
	myPath = Path();
	myPrompt = Prompt();
	//cout<<"Finished JMShell constructor"<<endl;

}

JMShell::~JMShell() {
	myPath.~Path();;
	myPrompt.~Prompt();
	//CL->~CommandLine();

}
void JMShell::systemComm(CommandLine *CL, int index)
{
	string myCommandStr(CL->getCommand());
	pid_t child_pid = fork();
	if(child_pid == 0){			
		string fullFile = myPath.getDirectory(index)+"/"+myCommandStr;
		//cout<<"-"<<fullFile<<"-"<<endl;
		char* nullPtr[] = {NULL};
		execve(fullFile.c_str(), CL->getArgVector(),nullPtr);
		cout<<"Should Never Print"<<endl;
		exit(1);
	}
	else if(child_pid< 0)
	{
		cout<<"Failed child"<<endl;
	}
	else{
		if(CL->noAmpersand())
		{
			waitpid(child_pid, NULL, 0);
			//cout<<"Child Process Teminated"<<endl;
		};
	}

}
void JMShell::run()
{
	int status;
	int index;
	string fullFile;
	while(1)
	{
		cout<<shellPromptFormat()<<flush;
		CommandLine *CL = new CommandLine(cin);
		//cout<<"Command Line created"<<endl;
		int index;
		if(CL->getCommand()!=NULL){
			string myCommandStr(CL->getCommand());

			analyzeFun(CL,myCommandStr);
			//delete myCommandStr;
		}
		delete CL;
	}
}
string JMShell::shellPromptFormat(){
	string str = myPrompt.get()+"$";
	return str;
}
void JMShell::analyzeFun(CommandLine* commL, string cmd)
{
	if (cmd == "cd" )
	{
		char * dir = commL->getArgVector(1);
		int result = chdir(dir); // change the directory
		if (result == -1)
		{
			cout << "Unable to find the directory: " << dir << endl;
		} else
		{
			myPrompt = Prompt();
		}
	}
	// Command to output the current path
	else if (cmd == "pwd")
	{
		cout << myPrompt.get() << endl;
	} else if (cmd == "exit")
	{
		cout << "Exiting the program" << endl;
		exit(0);
	}
	// Command not recognized
	else
	{
		string myComm = cmd;
		int index = myPath.find(myComm);		
		if(index!= -1)
		{
			systemComm(commL, index);	
		}
		else
		{
			cout << "The command: " << cmd << " you are using is still a work in progress" << endl;
		}
	}
}

