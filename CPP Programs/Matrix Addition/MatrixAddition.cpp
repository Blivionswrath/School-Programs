// Programmer: Tanner Gordon
// Class: C++ Online

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

double** readFile(string s);
double** addMatrices(double** m1, double** m2);
vector<double> tokenzizeString(string s);
bool validate(string s1, string s2);
void displayMatrix(double** m);

vector<double> matrixDimensions(2);

int main(int argc, char** argv) {
    string file1, file2;
    cout << "Welcome to the matrix addition program!\n";
    
    if (argc > 1) {
        file1 = argv[1];
    }
    if (argc > 2) {
        file2 = argv[2];
    }

    if (argc == 1) {
        cout << "Please enter the name of file 1: ";
        getline(cin, file1);
        cout << "Please enter the name of file 2: ";
        getline(cin, file2);
    }
    if (argc == 2 ) {
        cout << "Please enter the name of file 2: ";
        getline(cin, file2);
    }

    //Validation for array sizes
    bool valid = validate(file1, file2);

    if (!valid) {
        cout << "Please make sure matrices are of the same dimensions.\n";
    }
    else {

    double** m1 = readFile(file1);
    double** m2 = readFile(file2);

    displayMatrix(m1);
    cout << endl << endl;
    displayMatrix(m2);
    
    cout << "\nThe sum of these matrices is: \n\n";
    double** m3 = addMatrices(m1, m2);
    displayMatrix(m3);
    }
    cout << "\n\nThank you for using matrix addition!";
}

double** addMatrices(double** m1, double** m2) {
    double** m3 = new double* [matrixDimensions[0]];

    for (int i = 0; i < matrixDimensions[0]; i++) {
        m3[i] = new double[matrixDimensions[1]];
    }

    for (int i = 0; i < matrixDimensions[0]; i++) {
        for (int j = 0; j < matrixDimensions[1]; j++) {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return m3;
}

double** readFile(string s ) {
    string fileName = s;
    ifstream inputStream;
    inputStream.open(s);
    
    while (!inputStream.is_open()) {
        cout << "\"" << fileName << "\" could not be opened, please re-enter the file name: ";
        getline(cin, fileName);
    }

    string firstLine;
    getline(inputStream, firstLine);
    vector<double> dimensions = tokenizeString(firstLine);
    
    double** result = new double*[dimensions[0]];
        
    for(int i = 0; i < dimensions[0]; i++) {
        result[i] = new double[dimensions[1]];
    }
    
    string input;
    for (int i = 0; i < dimensions[0]; i++) {
        getline(inputStream, input);
        vector<double> tokens = tokenizeString(input);

        for (int j = 0; j < dimensions[1]; j++) {
            result[i][j] = tokens[j];
        }
    }

    inputStream.close();
    return result;
}

vector<double> tokenizeString(string s) {
    vector<double> result;
    stringstream tokenStream;
    tokenStream.str(s);
    string temp;
    while (getline(tokenStream, temp, ' ')) {
        result.push_back(stod(temp));
    }

    return result;
}

bool validate(string s1, string s2) {
    ifstream validationStream;
    string file1 = s1, file2 = s2, validationLine;
    validationStream.open(file1);
    bool valid = true;
    
    while (!validationStream.is_open()) {
        cout << "\"" << file1 << "\" could not be opened, please enter another file name: ";
        getline(cin, file1);
    }
    getline(validationStream, validationLine);
    vector<double> dimensions1 = tokenizeString(validationLine);
    validationStream.close();

    validationStream.open(file2);
    while (!validationStream.is_open()) {
        cout << "\"" << file2 << "\" could not be opened, please enter another file name: ";
        getline(cin, file2);
    }
    getline(validationStream, validationLine);
    vector<double> dimensions2 = tokenizeString(validationLine);

    if (dimensions1[0] != dimensions1[0] || dimensions1[1] != dimensions1[1]) {
        valid = false;
    }
    if (valid) {
        matrixDimensions[0] = dimensions1[0];
        matrixDimensions[1] = dimensions1[1];
    }

    return valid;
}

void displayMatrix(double** m) {
    cout << setw(10);
    for (int i = 0; i < matrixDimensions[0]; i++ ) {
        for (int j = 0; j < matrixDimensions[1]; j++) {
            cout << setw(10);
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}
