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
	//while(1){
		cout<<shellPromptFormat()<<flush;
		CL = CommandLine(cin);
		cout<<"Input argc is: "<<CL.getArgCount()<<endl;
		cout<<"Input argv is:"<<flush;
		cout<<CL.getArgVector(0)<<flush;
		cout<< ":"<<endl;
	//}
}
string JMShell::shellPromptFormat(){
	return myPrompt.get()+"$";
}

