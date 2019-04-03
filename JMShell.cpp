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

		//cout<<"Command Line created"<<endl;
		int index;
		if(CL.getCommand()!=NULL){
			char* myCommand = CL.getCommand();
			string myCommandStr(myCommand);
			vector<string> strings {myCommandStr, "",NULL};
    			vector<char*> cstrings;
    			cstrings.reserve(strings.size());

    			for(size_t i = 0; i < strings.size(); ++i)
        			cstrings.push_back(const_cast<char*>(strings[i].c_str()));
			index = myPath.find(myCommandStr);
			//cout<<index<<endl;
			if(index!= -1)
			{
				//cout<<"Made it"<<endl;
				if((child_pid = fork()) == 0){
					//cout<<"Child PID = 0"<<endl;cout<<CL.getCommand()<<endl;cout<<myPath.getDirectory(index)<<endl;cout<<myCommandStr<<endl;
					string fullFile = myPath.getDirectory(index)+"/"+myCommandStr;
    					char *cptr = new char[fullFile.size()+1]; // +1 to account for \0 byte
   					strncpy(cptr, fullFile.c_str(), fullFile.size());
					//cout<<cptr<<endl;
					execve(myCommand, CL.getArgVector(),const_cast<char*>(myCommand));
					delete [] cptr;
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

