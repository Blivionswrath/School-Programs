// Tanner Gordon
// C++ online
// Searching

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> tokenizeString(string s);
bool binarySearch(int* a, int start, int stop, int target);
bool sequentialSearch(int* a, int size, int target);
bool isTarget(int a, int b);
void toArray(string s, int* a, int size);
void copyArray(int* source, int* dest, int size);
void displayArray(int* theArray, int size);
void insertSort(int* theArray, int size);

int numComparisons = 0, numFuntionCalls = 0;

int main()
{
	string fileName, input, message;
	int n, target;
	ifstream inputStream;

	cout << "Welcome to the searching program!\nPlease enter the file you would like to search through:";
	getline(cin, fileName);

	inputStream.open(fileName);

	while (!inputStream.is_open()) {
		cout << fileName << " could not be found, please enter another file name: ";
		getline(cin, fileName);
		inputStream.open(fileName);
	}
	getline(inputStream, input);
	n = stoi(input);

    int* a = new int[n];
    int* sorted = new int[n];
    toArray(fileName, a, n);
    copyArray(a, sorted, n);
    cout << "\nSorting array...\n";
    insertSort(sorted, n);
    bool running = true;
    while (running) {

        cout << "Please enter the number you would like to search for, enter -1 to exit ";
        getline(cin, input);

        target = stoi(input);

        if (target == -1) {
            cout << "Thank you for using the searching program!";
            return 0;
        }


        if (sequentialSearch(a, n, target)) {
            message = input + " was found in ";
        }
        else {
            message = input + " was not found in ";

        }

        cout << message << numComparisons << " calls using sequential search.\n";
        numFuntionCalls = 0;
        numComparisons = 0;
        if (binarySearch(sorted, 0, n, target)) {
            message = input + " was found in ";
        }
        else {
            message = input + " was not found in ";
        }

        cout << message << numFuntionCalls << " calls using binary search.\n";

    }

}

//==========
//Searches
//==========
bool sequentialSearch(int* a, int size, int target) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (isTarget(a[i], target)) {
            found = true; 
            break;
        }
    }
    return found;
}

bool binarySearch(int* a, int start, int stop, int target) {

    numFuntionCalls++;
    bool found = false; 
    int middle = (start + (stop-1)) / 2;
    
    if(!(middle == start) && !(middle == stop)) {
        if (isTarget(a[middle], target)) {
            found = true;
        }
        else if (start - stop == 1) {
            if (isTarget(a[start], target)) { found = true; }
            else if (isTarget(a[stop], target)) { found = true; }
        }
        else if (a[middle] < target) {
            if (binarySearch(a, middle, stop, target)) { found = true; }
            else { found = false; }
        }
        else {
            if (binarySearch(a, start, middle, target)) { found = true; }
            else { found = false; }
        }
    }
    else {
        if (isTarget(a[start], target)) { found = true; }
        if (isTarget(a[start], target)) { found = true; }
    }

    return found;
}






//=====================
//Helper functions
//=====================

void toArray(string s, int* a, int size) {
    ifstream inputStream;
    inputStream.open(s.c_str());
    string tokenString;
    int values = 0;
    int increment = 0;
    getline(inputStream, tokenString);
    while (!inputStream.eof()) {
        if (increment >= size) { break; }
        getline(inputStream, tokenString);
        vector<int> tokens = tokenizeString(tokenString);
        values += tokens.size();

        for (int i = 0; i < tokens.size(); i++) {
            if (increment >= size) { break; }
            a[increment] = tokens[i];
            increment++;
        }
    }

    if (values < size) {
        cout << "\nWARNING: The amount of values is less than the amount indicated in the file\n";
    }
}

vector<int> tokenizeString(string s) {
    vector<int> result;
    stringstream stream;
    stream.str(s);
    string temp;

    while (getline(stream, temp, ' ')) {
        result.push_back(stoi(temp));
    }
    return result;
}

void displayArray(int* theArray, int size) {
    cout << endl << endl;
    if (size < 200) {
        for (int i = 0; i < size; i++) {
            cout << setw(20) << right;
            cout << theArray[i];
        }
    }
    else {
        int columnNumber = 0;
        for (int i = 0; i < 100; i++) {
            cout << setw(20) << right;
            cout << theArray[i];
            columnNumber++;
            if (columnNumber == 10) {
                cout << endl;
                columnNumber = 0;
            }
        }
        columnNumber = 0;
        cout << endl;
        for (int i = size - 100; i < size; i++) {
            cout << setw(20) << right;
            cout << theArray[i];
            columnNumber++;
            if (columnNumber == 10) {
                cout << endl;
                columnNumber = 0;
            }
        }
    }
}

void reverseArray(int* a, int size) {
    int* copy = new int[size];
    copyArray(a, copy, size);
    int j = 0;
    for (int i = size - 1; i > -1; i--) {
        a[i] = copy[j];
        j++;
    }
    delete[] copy;
}

void copyArray(int* source, int* dest, int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

bool isTarget(int a, int b) {
    numComparisons++;
    return a == b;
}

//=====================
//Sorting functions
//=====================
bool inOrder(int a, int b) {
    return a <= b;
}

void exchange(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

void insertSort(int* theArray, int size) {

    int* theCopy = new int[size];

    theCopy[0] = theArray[0];

    for (int i = 1; i < size; i++) {
        theCopy[i] = theArray[i];
        int j = i;
        int k = i - 1;

        while (!inOrder(theCopy[k], theCopy[j]) && k >= 0) {
            exchange(theCopy[k], theCopy[j]);
            j--;
            k--;
        }
    }
    copyArray(theCopy, theArray, size);
    delete[] theCopy;
}