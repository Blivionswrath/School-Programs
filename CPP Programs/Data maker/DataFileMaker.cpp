/*
* Programmer: Tanner Gordon
* Class: C++ (Online) (CS-2363-TW01S)
* Description: Creates data files  with the specified number of integers in a specified range
* Known issues: There is zero input validation.
*/
using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
string input, fileName;
int numValues, range;

int main(int argc, char * argv[])
{

	if (argc >= 2) {
		numValues = atoi(argv[1]);
	}
	if (argc >= 3) {
		range = atoi(argv[2]);
	}
	if (argc >= 4) {
		fileName = argv[3];
	}

	srand(time(0));

	cout << "Welcome to the datafile maker!" << endl;
	if (argc < 2) {
		cout << "Please enter how many integers you would like to generate: ";
		getline(cin, input);
		numValues = stoi(input);
	}
	if (argc < 3) {
	cout << "Please enter the range of the data: ";
	getline(cin, input);
	range = stoi(input);
	}

	if (argc < 4) {
	cout << "Please enter file name: ";
	getline(cin, fileName);
	}

	cout << "Writing " << numValues << " values in [0-" << range << ") to " << fileName << endl;

	ofstream fout;
	fout.open(fileName.c_str());
	fout << numValues << endl;
	for (int i = 0; i < numValues; i++) {
		fout << rand() % range << " ";
	}
}
	
