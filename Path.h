/* Path.h holds the headers for the path class
* created by Jason Pruim, for CS232 @ Calvin.edu
*March 30,2019
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <dirent.h>

using namespace std;
//declaration of path class and function stubs
class Path
{
	private:
	vector<string> vecDir;
	char* myEnv;
	public:
	Path();
	~Path();
	int find(const string& program) const;
	string getDirectory(int i) const;
};
