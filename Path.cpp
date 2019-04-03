/* Path.h holds the headers for the path class
* created by Jason Pruim, for CS232 @ Calvin.edu
* March 30,2019
*/
#include "Path.h"

using namespace std;
//get evironment paths and add to vector
Path::Path(){
	myEnv = getenv("PATH");
	if(myEnv == NULL){
		cerr<<"Null Path"<<endl;
		exit(1);
	}

	//cout<<myEnv<<endl;
	string delimiter = ":";
	//Seperate out the different directories
	size_t pos = 0;
	string myEnv2 = myEnv;
	string token;
	//cout<< "Start of seperating directories"<<endl;
	while ((pos = myEnv2.find(delimiter)) != string::npos) {
   		token = myEnv2.substr(0, pos);
    		//cout << token << endl;
		vecDir.push_back(token);
    		myEnv2.erase(0, pos + delimiter.length());
	}
	//print message to see if the vector is correctly made;
	//for(int i = 0;i < vecDir.size(); i++){cout<<vecDir[i]<<endl;};
	

}
Path::~Path(){
	// myEnv self destructs as no call to new or malloc is used (errors if I delete it)
	//vectors self-destruct (based on how the class is made
	//therefore no destructor is needed
}

//find a program by iterating through the path
int Path::find(const string& program) const {
	DIR * currDir;
	struct dirent *ent;
	//cout<<vecDir.size()<<endl;
	//cout<<vecDir[18]<<endl;
	for(int i = 0;i < vecDir.size(); i++){
		currDir = opendir(vecDir[i].c_str());
		if(currDir){//check if folder exists (some don't namely #18)
			while((ent = readdir(currDir))!= NULL){
				if (ent->d_type == DT_REG) {  // regular file
	      				if (ent->d_name == program) {closedir(currDir);return i;}; //return index of program location
	    			}
			}
			closedir(currDir);
		}	
	}
	return -1; //return -1 if file not found

}
//returns the string name of the directory at index i
string Path::getDirectory(int i) const{
	if(i <0 ||i>= vecDir.size() ){return "";};
	return vecDir[i].c_str();
	
}
