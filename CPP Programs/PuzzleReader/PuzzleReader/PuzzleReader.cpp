// Programmer: Tanner Gordon
// Class: C++ Online

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

char** toCharMatrix(string file);
int** toIntMatrix(char** m);
bool isValid(string s1);
vector<char> tokenizeString(string s1);
int valueOf(char c);
void displayMatrix(char** m);
int displayMatrix(int** m);

vector<int> matrixDimensions(2);

int main() {

	string s1;

	cout << "Please enter the puzzle file you would like to read: ";
	getline(cin, s1);

	bool valid = isValid(s1);

	if (!valid) {
		cout << endl << s1 << " is not a valid file.";
	}
	else {

		char** charMatrix = toCharMatrix(s1);
		int** intMatrix = toIntMatrix(charMatrix);

		cout << "\n\n";
		displayMatrix(charMatrix);
		cout << "\n\n";
		int sum = displayMatrix(intMatrix);
		cout << "\n\nThe sum of the matrix is: " << sum;
	}

 }

bool isValid(string s1) {
	ifstream inputStream;
	string fileName = s1, input;
	int rows = 0;
	bool result = true;

	inputStream.open(fileName);
	
	while (!inputStream.is_open()) {
		cout << fileName << " could not be opened, please enter a new file name: ";
		getline(cin, fileName);
		inputStream.open(fileName);
	}

	getline(inputStream, input);
	rows++;

	vector<char> tokens = tokenizeString(input);
	matrixDimensions[1] = tokens.size();
	
	while (!inputStream.eof()) {
		getline(inputStream, input);
		rows++;
	}
	matrixDimensions[0] = rows;
	int product = matrixDimensions[0] * matrixDimensions[1];

	if (matrixDimensions[0] != matrixDimensions[1]) {
		result = false;
		cout << "This file is not a valid puzzle.";
	}

	return result;
}

vector<char> tokenizeString(string s1) {
	vector<char> result;
	stringstream tokenStream;
	tokenStream.str(s1);
	string temp;
	while (getline(tokenStream, temp, ' ')) {
		result.push_back(temp[0]);
	}

	return result;
}

int valueOf(char c) {
	int result;
	if (c == '-') {
		result = -1;
	}
	else if (c >= '0' && c <= '9') {
		result = c - 48;
	}
	else if (c >= 'A' && c <= 'J' ) {
		result = 9 + (c - 64);
	}
	else if (c >= 'a' && c <= 'j') {
		result = 9 + (c - 96);
	}
	else if (c >= 'K' && c <= 'T') {
		result = 19 + (c - 74);
	}
	else if (c >= 'k' && c <= 't') {
		result = 19 + (c - 106);
	}
	else if (c >= 'U' && c <= 'Z') {
		result = 29 + (c - 84);
	}
	else if (c >= 'u' && c <= 'z') {
		result = 29 + (c - 116);
	}
	else {
		result = -9;
	}
	return result;
}

char** toCharMatrix(string file) {
	ifstream inputStream;
	inputStream.open(file);
	char** result = new char*[matrixDimensions[0]];

	for (int i = 0; i < matrixDimensions[0]; i++) {
		result[i] = new char[matrixDimensions[1]];
	}

	string input;
	int row = 0;
	while (!inputStream.eof()) {
		getline(inputStream, input);
		vector<char> tokens = tokenizeString(input);

		for (int i = 0; i < tokens.size(); i++) {
			result[row][i] = tokens[i];
		}
		row++;
	}

	return result;

}

int** toIntMatrix(char** m) {
	int** result = new int*[matrixDimensions[0]];

	for (int i = 0; i < matrixDimensions[0]; i++) {
		result[i] = new int[matrixDimensions[1]];
	}

	for (int i = 0; i < matrixDimensions[0]; i++) {
		for (int j = 0; j < matrixDimensions[1]; j++) {
			result[i][j] = valueOf(m[i][j]);
		}
	}
	
	return result;
}



void displayMatrix(char** m) {
	cout << setw(10);
	for (int i = 0; i < matrixDimensions[0]; i++) {
		for (int j = 0; j < matrixDimensions[1]; j++) {
			cout << setw(3);
				cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

int displayMatrix(int** m) {
	cout << setw(10);
	int sum = 0;
	for (int i = 0; i < matrixDimensions[0]; i++) {
		for (int j = 0; j < matrixDimensions[1]; j++) {
			cout << setw(3);
			if (m[i][j] == -1) {
				cout << "- ";
			}
			else {
				cout << m[i][j] << " ";
				sum += m[i][j];
			}
		}
		cout << endl;
	}
	return sum;
}