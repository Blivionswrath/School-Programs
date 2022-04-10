//Tanner Gordon
//Online C++

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

bool inOrder(int a, int b);
vector<int> tokenizeString(string s);
void exchange(int& a, int& b);
void exchangeSort(int* theArray, int size);
void insertSort(int* theArray, int size);
void selectionSort(int* a, int size);
void reverseArray(int* a, int size);
void copyArray(int* source, int* dest, int size);
void displayArray(int* theArray, int size);
void toArray(string s, int* a, int size);

unsigned __int64 numComparisons = 0, numExchanges = 0;

int main()
{
    string input, fileName;
    ifstream inputStream;
    cout << "Welcome to the sorting program!\nPlease enter the name of the file you would like to sort: ";
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
    int* theCopy = new int[n];
    int* duplicateArray = new int[n];
    int* reversedArray = new int[n];

    for (int i = 0; i < n; i++) {
        duplicateArray[i] = 1;
    }

    toArray(fileName,theArray, n);

        
    copyArray(theArray, theCopy, n);
    copyArray(theArray, reversedArray, n);
    reverseArray(reversedArray, n);
    displayArray(theArray, n);
    
    //==============
    //Exchange sorts
    //==============
    cout << "\nExchange Sort: \n";
    exchangeSort(theCopy, n);
    displayArray(theCopy, n);
    cout << "\n\nComparisons: " << numComparisons << "\nExchanges: " << numExchanges << endl;
    numComparisons = numExchanges = 0;
    cout << "\nPre-sorted Exchange sort: \n";
    exchangeSort(theCopy, n);
    displayArray(theCopy, n);
    cout << "\n\nComparisons: " << numComparisons << "\nExchanges: " << numExchanges << endl;
    numComparisons = numExchanges = 0;

    cout << "\nReversed exchange: \n";
    copyArray(reversedArray, theCopy, n);
    cout << "\nReversed array: \n";
    displayArray(theCopy, n);
    exchangeSort(theCopy, n);
    cout << "\nSorted array: \n";
    displayArray(theCopy, n);
    cout << "\n\nComparisons: " << numComparisons << "\nExchanges: " << numExchanges << endl;
    numComparisons = numExchanges = 0;
    
    cout << "\nDuplicate array exchange sort: \n";
    exchangeSort(duplicateArray, n);
    cout << "\n\nComparisons: " << numComparisons << "\nExchanges: " << numExchanges << endl;
    numComparisons = numExchanges = 0;

    //=================
    //Insertion sorts
    //=================
    copyArray(theArray, theCopy, n);
    cout << "\nInsertion Sort: \n";

    displayArray(theCopy, n);
    insertSort(theCopy, n);
    displayArray(theCopy, n);
    cout << "\n\nComparisons: " << numComparisons << "\nExchanges: " << numExchanges << endl;
    numComparisons = numExchanges = 0;

    cout << "\nPre-sorted insertion sort:\n";
    insertSort(theCopy, n);
    cout << "\n\nComparisons: " << numComparisons << "\nExchanges: " << numExchanges << endl;
    numComparisons = numExchanges = 0;
    
    cout << "\nInsertion reversed: \n\nReversed array: \n";
    copyArray(reversedArray, theCopy, n);
    displayArray(theCopy, n);
    insertSort(theCopy, n);
    cout << "\nSorted array:\n";
    displayArray(theCopy, n);
    cout << "\n\nComparisons: " << numComparisons << "\nExchanges: " << numExchanges << endl;
    numComparisons = numExchanges = 0;
    
    cout << "\nDuplicate array insertion sort: \n";
    insertSort(duplicateArray, n);
    cout << "\n\nComparisons: " << numComparisons << "\nExchanges: " << numExchanges << endl;
    numExchanges = numComparisons = 0;

    //=================
    //Selection sorts
    //=================

    copyArray(theArray, theCopy, n);
    cout << "\nSelection Sort: \n";
    selectionSort(theCopy, n);
    displayArray(theCopy, n);
    cout << "\n\nComparisons: " << numComparisons << "\nExchanges: " << numExchanges << endl;
    numComparisons = numExchanges = 0;
    
    cout << "\nPre-sorted selection sort:\n";
    selectionSort(theCopy, n);
    cout << "\n\nComparisons: " << numComparisons << "\nExchanges: " << numExchanges << endl;
    numComparisons = numExchanges = 0;
    
    cout << "\nReversed Selection: \n";
    copyArray(reversedArray, theCopy, n);
    cout << "\nReversed array:\n";
    displayArray(theCopy, n);
    selectionSort(theCopy, n);
    cout << "\nSorted array:\n";
    displayArray(theCopy, n);
    cout << "\n\nComparisons: " << numComparisons << "\nExchanges: " << numExchanges << endl;
    numComparisons = numExchanges = 0;
    
    cout << "\nDuplicate Array selection sort: \n";
    selectionSort(duplicateArray, n);
    cout << "\n\nComparisons: " << numComparisons << "\nExchanges: " << numExchanges << endl;

    cout << "\nThank you for using the sorting program!";
}

//========================
//Sorting functions
//========================

void exchangeSort(int* theArray, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            if (!inOrder(theArray[j], theArray[j + 1])) {
                exchange(theArray[j], theArray[j + 1]);
            }
        }
    }
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

void selectionSort(int* a, int size) {
    int currentMinIndex;
    bool changed;

    for (int i = 0; i < size; i++) {
        changed = false;
        currentMinIndex = i;
        for (int j = i; j < size; j++) {
            if (!inOrder(a[currentMinIndex], a[j])) {
                currentMinIndex = j;
                changed = true;
            }
        }
        if (changed) {
            exchange(a[currentMinIndex], a[i]);
        }
    }

}


//==============================
//Helper functions
//==============================

bool inOrder(int a, int b) {
    numComparisons++;
    return a <= b;
}

void exchange(int& a, int& b) {
    numExchanges++;
    int t = a;
    a = b;
    b = t;
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

void toArray(string s,int* a, int size) {
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