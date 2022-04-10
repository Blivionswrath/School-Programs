//Tanner Gordon
//Program: Magic Square
//C++ Online

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>

using namespace std;

bool isCompletePuzzle(int **m);
bool isValidPuzzle(int** m);
bool validFile(string file);
bool solvePuzzle(int** m);
vector<int> tokenizeString(string s);
int** toPuzzle(string file);
void displayPuzzle(int** m);


int* dimensions = new int[2];
int maxNumber;
clock_t start, stop;
double elapsedTime;
int solutionCount = 0;
int magicNumber;

int main()
{

	string file;

	cout << "Welcome to the magic square program!\nPlease enter the input file to solve: ";
	getline(cin, file);

	if (!validFile(file)) {
		cout << file << " is not a valid file.";
		return 0;
	}

	int n = dimensions[0];
	maxNumber = n * n;
	magicNumber= 0.5 * n * (maxNumber + 1);
	int** puzzle = toPuzzle(file);

	start = clock();
	displayPuzzle(puzzle);
	solvePuzzle(puzzle);
	
	stop = clock();
	elapsedTime = (stop - start) / CLOCKS_PER_SEC;
	
	cout << endl << solutionCount << " solutions found in " << elapsedTime << " seconds.";
}

//initial file validation
bool validFile(string file) {
	ifstream inputStream;
	inputStream.open(file.c_str());
	bool valid = true;
	string currentLine;

	if(!inputStream.is_open()){
		valid = false;
		cout << "ERROR: Could not open " << file << endl;
	}

	vector<int> tokens;
	int rows = 0;
	dimensions[1] = 0;
	while (!inputStream.eof()) {
		getline(inputStream, currentLine);
		tokens = tokenizeString(currentLine);
		if (tokens.size() != dimensions[1] && dimensions[1] != 0) {
			valid = false;
			cout << "ERROR: Multiple column counts.\n";
		}
		dimensions[1] = tokens.size();
		rows++;

	}

	dimensions[0] = rows;

	if(dimensions[0] != dimensions[1]){
		cout << "ERROR: File is not a square.\n";
		valid = false;
	}

	return valid;
	
}

//Cut strings into tokens to process.
vector<int> tokenizeString(string s) {
	vector<int> result;
	stringstream line;
	string temp;
	line.str(s);
	int add;
	
	while (getline(line, temp, ' ')) {
		add = stoi(temp);
		result.push_back(add);
	}
	return result;
}

//Create the initial puzzle with the given file
int** toPuzzle(string file) {
	ifstream inputStream;
	inputStream.open(file);

	int** result = new int* [dimensions[0]];

	for (int i = 0; i < dimensions[1]; i++) {
		result[i] = new int[dimensions[1]];
	}

	int row = 0;
	string currentLine;
	while (!inputStream.eof()) {
		getline(inputStream, currentLine);	
		vector<int> tokens = tokenizeString(currentLine);

		for (int i = 0; i < dimensions[1]; i++) {
			result[row][i] = tokens[i];
		}
		row++;
	}
	return result;
}

void displayPuzzle(int** m) {
	cout << endl;
	for (int i = 0; i < dimensions[0]; i++) {
		cout << endl;

		for (int j = 0; j < dimensions[1]; j++) {
			cout << setw(10);
			cout << m[i][j] << ' ';
		}
	}
}

bool solvePuzzle(int** m) {
	bool isSolution = false;
	
	if (isCompletePuzzle(m)) {
		if (isValidPuzzle(m)) {
			isSolution = true;
		}
		return false;
	}
	else{

		for (int row = 0; row < dimensions[0]; row++) {
			if (isSolution == true) { break; }

			for (int column = 0; column < dimensions[1]; column++) {
				if (isSolution == true) { break; }

				if (m[row][column] == 0) {
					for (int num = 1; num <= maxNumber; num++) {
						m[row][column] = num;
						if (solvePuzzle(m)) {
							isSolution = true;
							break;
						}
					}
					m[row][column] = 0;
					return false;
				}
				
			}
		}
	}
	return isSolution;
}

bool isValidPuzzle(int** m) {
	int n = dimensions[0];
	int valid = true;
	int sum = 0;

	//Check diagonals
	if (valid) {

		sum = 0;
		int j = 0;
		for (int i = 0; i < dimensions[0]; i++) {
			sum += m[i][j];
			j++;
		}
		if (sum != magicNumber) { valid = false; }

		sum = 0;
		j = 0;

		for (int i = dimensions[0] - 1; i > -1; i--) {
			sum += m[i][j];
			j++;
		}
		if (sum != magicNumber) { valid = false; }

	}

	sum = 0;
	//Check rows
	if (valid) {

		for (int i = 0; i < dimensions[0]; i++) {
			if (!valid) { break; }

			for (int j = 0; j < dimensions[1]; j++) {
				if (!valid) { break; }
				sum += m[i][j];
			}

			if (sum != magicNumber) { valid = false; }
			sum = 0;
		}
	}

	//Check columns
	
	sum = 0;
	if (valid) {
		for (int i = 0; i < dimensions[1]; i++) {
			if (!valid) { break; }

			for (int j = 0; j < dimensions[0]; j++) {
				if (!valid) { break; }
				sum += m[j][i];

			}
			if (sum != magicNumber) { valid = false; }
			sum = 0;
		}
	}


	//Check digits
	if (valid) {
		int index;
		int* memo = new int[n * n];

		for (int i = 0; i < n*n; i++) {	
			memo[i] = 0;
		}

		for (int i = 0; i < dimensions[0]; i++) {
			if (!valid) { break; }
			for (int j = 0; j < dimensions[1]; j++) {
				if (!valid) { break; }
	
				index = m[i][j] - 1;
				if (memo[index] != 0) { valid = false; }
				memo[index] = m[i][j];
			}
		}
	}

	if (valid) {
		solutionCount++;
		stop = clock();
		elapsedTime = (stop - start) / CLOCKS_PER_SEC;
		cout << "\nA solution was found (" << elapsedTime << " seconds elapsed)\n";
		displayPuzzle(m);
	}
	return valid;
}

bool isCompletePuzzle(int** m) {
	bool complete = true;

	if (m[dimensions[0] - 1][dimensions[1] - 1] == 0) { complete = false; }

	return complete;
}