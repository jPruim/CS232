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
	CL = CommandLine();
	//cout<<"Finished JMShell constructor"<<endl;

}

JMShell::~JMShell() {
	myPath.~Path();;
	myPrompt.~Prompt();
	CL.~CommandLine();

}
void JMShell::run()
{
	int status;
	pid_t child_pid;
	while(1)
	{
		cout<<shellPromptFormat()<<flush;
		CL = CommandLine(cin);
		cout<<CL.toString()<<endl;

		//cout<<"Command Line created"<<endl;
		int index;
		if(CL.getCommand()!=NULL){
			string str(CL.getArgVector(0));
			if(index = myPath.find(str)!= -1)
			{
				//cout<<"Made it"<<endl;
				if((child_pid = fork()) == 0){
					cout<<"Child PID = 0"<<endl;
					const char* fullFile = (myPath.getDirectory(index)+"/"+CL.getCommand()).c_str();
					cout<<fullFile<<endl;
					execve(fullFile, CL.getArgVector(),NULL);
					exit(1);
				}
				else{
					if(!CL.noAmpersand()){waitpid(child_pid, &status, 0);};
				}
			}
			else
			{
				cout<<"Invalid Function"<<endl;
			}
		}
	}
}
string JMShell::shellPromptFormat(){
	return myPrompt.get()+"$";
}

