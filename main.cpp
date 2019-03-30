/*Main class to run made shell
* 
* created by Jason Pruim and Micah Bonewell, for CS232 @ Calvin.edu
* March 30,2019
*/


#include "Path.h"
#include "Prompt.h"

using namespace std;

//Create and run the shell (with some "tests")
int main(){
	Path myPath = Path();
	Prompt myPrompt = Prompt();
	//simple path tests
	cout<<"Finding location of ls"<<endl;
	cout<<myPath.getDirectory(myPath.find("ls"))<<endl; //should print the location of ls;
	//simple prompt test
	cout<< "Prompt Test"<<endl;
	cout<< myPrompt.get()<<flush;
	cout<<"~~check for empty spaces~~"<<endl;
}
