/*Main class to run made shell
* 
* created by Jason Pruim and Micah Bonewell, for CS232 @ Calvin.edu
* March 30,2019
*/


#include "JMShell.h"


using namespace std;
/*runs tests
* meant to be commmented out in main for actual use
*/
void runTests(){

	Path myPath = Path();
	
	Prompt myPrompt = Prompt();
	//simple path tests
	cout<<"Finding location of ls"<<endl;
	cout<<myPath.getDirectory(myPath.find("ls"))<<endl; //should print the location of ls;
	//cout<<myPath.getDirectory(0)<<endl; //should first directory in path
	cout<<"Finding index of non-existent function (-1)"<<endl;
	cout<<myPath.find("alsdf")<<endl;
	//simple prompt test
	cout<< "Prompt Test"<<endl;
	cout<< myPrompt.get()<<flush;
	cout<<"~~check for empty spaces~~"<<endl;
	cout<<"Tests Done"<<endl;


}
//Create and run the shell (with some "tests")
int main(){
	runTests();
	cout<<"Starting Constructor"<<endl;
	JMShell myJM = JMShell();
	
	myJM.run();

	
}

