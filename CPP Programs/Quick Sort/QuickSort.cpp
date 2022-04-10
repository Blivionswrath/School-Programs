//Programmer: Tanner Gordon
// Online C++
//QuickSort

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>


using namespace std;

const int SMALL_LIST_SIZE = 10;

int partition(int* theArray, int startIndex, int stopIndex);
bool inOrder(int a, int b);
vector<int> tokenizeString(string s);
void quickSort(int* theArray, int theSize);
void quickSort(int* theArray, int startIndex, int stopIndex);
void insertSort(int* theArray, int theSize);
void insertSort(int* theArray, int startIndex, int stopIndex);
void setOfMedianThree(int* theArray, int startIndex, int stopIndex);
void exchange(int& a, int& b);
void displayArray(int* theArray, int size);
void toArray(string s, int* a, int size);
void writeData(string fileName, int* theArray, int theSize);

unsigned __int64 numComparisons = 0, numExchanges = 0;

int main()
{
    string input, fileName;
    ifstream inputStream;
    cout << "Welcome to the quicksort program!\nPlease enter the name of the file you would like to sort: ";
    getline(cin, fileName);

    inputStream.open(fileName.c_str());
    while (!inputStream.is_open()) {
        cout << endl << fileName << " could not be opened, please enter a file name: ";
        getline(cin, fileName);
        inputStream.open(fileName.c_str());
    }

    getline(inputStream, input);
    int n = stoi(input);
    int* theArray = new int[n];

    toArray(fileName, theArray, n);

    displayArray(theArray, n);
    quickSort(theArray, n);
    displayArray(theArray, n);

    string sortedFile;
    for (int i = 0; i < fileName.size(); i++) {
        if (fileName[i] == '.') {
            sortedFile = fileName.substr(0, i);
            break;
        }
    }
    sortedFile += "_sorted.txt";
    
    writeData(sortedFile, theArray, n);
    
    cout << "\nNumber of Comparisons: " << numComparisons;
    cout << "\nNumber of exchanges: " << numExchanges;

    cout << "\nThank you for using the quick sort program!";
}

void insertSort(int* theArray, int theSize) {
    insertSort(theArray, 0, theSize);
}

void insertSort(int* theArray, int startIndex, int stopIndex) {
  
    int size = (stopIndex - startIndex) + 1;
    cout << endl;

    int* theCopy = new int[size];

    theCopy[0] = theArray[startIndex];
    int theArrayIndex = startIndex + 1;
    for (int i = 1; i < size; i++) {
        theCopy[i] = theArray[theArrayIndex];
        int j = i;
        int k = i - 1;

        while (!inOrder(theCopy[k], theCopy[j]) && k >= 0) {
            exchange(theCopy[k], theCopy[j]);
            j--;
            k--;
        }
        theArrayIndex++;
    }

    int j = 0;
    for (int i = startIndex; i <= stopIndex; i++) {
        theArray[i] = theCopy[j];
        j++;
    }
    
    delete[] theCopy;
}

void quickSort(int* theArray, int theSize) {
    quickSort(theArray, 0, theSize - 1);
}

void quickSort(int* theArray, int startIndex, int stopIndex) {
    if (stopIndex - startIndex <= SMALL_LIST_SIZE) {
        insertSort(theArray, startIndex, stopIndex);
    }
    else {
        setOfMedianThree(theArray, startIndex, stopIndex);
        int partitionElement = partition(theArray, startIndex, stopIndex);
        quickSort(theArray, startIndex, partitionElement-1);
        quickSort(theArray, partitionElement, stopIndex);
    }
}

void setOfMedianThree(int* theArray, int startIndex, int stopIndex) {
    int debugStart = theArray[startIndex];
    int debugStop = theArray[stopIndex];
    
    int largestIndex =startIndex;
    int smallestIndex = startIndex;
    int medianIndex;
    int middleIndex = (startIndex + stopIndex) / 2;
    int debugMiddle = theArray[middleIndex];

    if (theArray[largestIndex] < theArray[middleIndex]) { largestIndex = middleIndex; }
    if (theArray[largestIndex] < theArray[stopIndex]) { largestIndex = stopIndex; }
    if (theArray[smallestIndex] > theArray[middleIndex]) { smallestIndex = middleIndex; }
    if (theArray[smallestIndex] > theArray[stopIndex]) { smallestIndex = stopIndex; }

    if (startIndex != largestIndex && startIndex != smallestIndex) { medianIndex = startIndex; }
    if (middleIndex != largestIndex && middleIndex != smallestIndex) { medianIndex = middleIndex; }
    if (stopIndex != largestIndex && stopIndex != smallestIndex) { medianIndex = stopIndex; }

    exchange(theArray[medianIndex], theArray[startIndex]);
}

int partition(int* theArray, int startIndex, int stopIndex) {
    int mainPointer = startIndex;
    int freePointer = stopIndex;
    
    while (mainPointer != freePointer) {
        if (mainPointer > freePointer) {
            if (!inOrder(theArray[freePointer], theArray[mainPointer])) {
                exchange(theArray[freePointer], theArray[mainPointer]);
                int temp = freePointer;
                freePointer = mainPointer;
                mainPointer = temp;
            }
            else {
                freePointer++;
            }
        }
        else if (mainPointer < freePointer) {
            if (!inOrder(theArray[mainPointer], theArray[freePointer])) {
                exchange(theArray[mainPointer], theArray[freePointer]);
                int temp = freePointer;
                freePointer = mainPointer;
                mainPointer = temp;
            }
            else {
                freePointer--;
            }
        }
    }

    return mainPointer;

}
//=================
//Helper functions
//=================


void exchange(int &a, int &b) {
    numExchanges++;
    int t = a;
    a = b;
    b = t;
}

bool inOrder(int a, int b) {
    numComparisons++;
    return a <= b;
}

void displayArray(int* theArray, int size) {
    cout << endl << endl;
    if (size < 200) {
        int columnNumber = 0;
        for (int i = 0; i < size; i++) {
            cout << setw(20) << right;
            cout << theArray[i];
            columnNumber++;
            if (columnNumber == 10) {
                cout << endl;
                columnNumber = 0;
            }
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

void writeData(string fileName, int* theArray, int theSize) {
    ofstream outputStream;
    outputStream.open(fileName);
    for (int i = 0; i < theSize; i++) {
        outputStream << theArray[i] << " ";
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
}