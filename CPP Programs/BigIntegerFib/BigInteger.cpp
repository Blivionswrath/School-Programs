//Programmer: Tanner Gordon
//Program: BigInteger
//Online C++ (CS-2363-TW01S)


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> toDigits(string s);
vector<int> trimLeadingZeros(vector<int> v);
vector<int> addLeadingZeros(vector<int> v, int count);
vector<int> normalize(vector<int> v, int = 10);
vector<int> add(vector<int> v1, vector<int> v2);
vector<int> addFile(string s1);
vector<int> fibonnacciRecursive(int n);
int valueOf(char c);
void displayDecimalDigits(vector<int> v);
void writeDigits(vector<int> v);

vector<int>* memo;

int main(int argc, string * argv[])
{
    ofstream outputStream;
    string input;
    //cout << "Would you like to read from a file? Y/N ";
    while (true) {

    cout << "Please enter the fibonacci index you would like to calculate: ";
    getline(cin, input);
    int n = stoi(input);

    memo = new vector<int>[n + 1];

    for (int i = 0; i < n + 1; i++) {
        memo[i] =  vector<int>(0);
    }

    vector<int> result = fibonnacciRecursive(n);
    outputStream.open("output.txt");

    cout << "fib(" << n << ") = ";
    outputStream << "fib(" << n << ") = ";
    outputStream.close();
    writeDigits(result);
    displayDecimalDigits(result);
    }

    /*
    if (input == "y" || input == "Y") {
        string s1;
        cout << "Please enter the name of file 1: ";
        getline(cin, s1);

        vector<int> result = addFile(s1);
        ofstream output;

        output.open("Output.txt");


        for (int i = 0; i < result.size(); i++) {
            output << result[i];

        }
        

        displayDecimalDigits(result);

    }
    else {

        string s1, s2;
        cout << "Welcome to BigInteger!\nPlease enter a BigInteger: ";
        getline(cin, s1);
        cout << "Please enter another BigInteger: ";
        getline(cin, s2);

        vector<int> v1 = add(toDigits(s1), toDigits(s2));
        cout << "The sum is: ";
        displayDecimalDigits(v1);
    }
    */
    
    cout << "\nThank you for using BigInteger!";
}

vector<int> toDigits(string s) {
    vector<int> ret(s.size());
    for (unsigned int i = 0; i < ret.size(); i++) {
        ret[i] = valueOf(s[i]);
    }

    return ret;
}

int valueOf(char c) {
    int result = 0;

    if (c >= 48 && c <= 57) {
        result = c - 48;
    }
    else {
        char d;
        if (islower(c)) {
            d = toupper(c);
        }
        else {
            d = c;
        }
        
        //A through F
        if (d >=65 && d <= 74) {
            result = 9 + (d - 64);
        }//G through T
        else if (d >= 75 && d <= 84) {
            result = 19 + (d - 74);
        }
        else if (d >= 85 && d <= 90) {
            result = 29 + (d - 84);
        }
        
    }

    return result;
}

void displayDecimalDigits(vector<int> v) {
    for (int i : v) {
        cout << i;
    }
    cout << endl;
}

vector<int> trimLeadingZeros(vector<int> v) {
    
    int count = 0;
    for (int i : v) {
        if (i == 0) {
            ++count;
        }
        else {
            break;
        }
    }
    vector<int> result(v.size() - count);

    for (unsigned int i = count, r = 0; i < v.size(); i++, r++) {
        result[r] = v[i];
    }
    return result;
}

vector<int> addLeadingZeros(vector<int> v, int count) {

    vector<int> result(v.size() + count);
    //Add zeros
    for (int i = 0; i < count; i++) {
        result[i] = 0;
    }
    //Copy Vector
    for (int i = 0; i < v.size(); i++) {
        result[i + count] = v[i];
    }

    return result;
} 

vector<int> normalize(vector<int> v, int base) {
    vector<int> result = addLeadingZeros(v, 1);

    for (int i = result.size() - 1; i >= 0; --i) {
        while (result[i] >= base) {
            result[i] -= base;
            result[i - 1] += 1;
        }
    }
    result = trimLeadingZeros(result);
    return result;
}

vector<int> add(vector<int> v1, vector<int> v2) {
    if (v1.size() > v2.size()) {
        int count = v1.size() - v2.size();
        v2 = addLeadingZeros(v2, count);
    }
    else if (v2.size() > v1.size()){
        int count = v2.size() - v1.size();
        v1 = addLeadingZeros(v1, count);
    }

    vector<int> result(v1.size());

    for (int i = 0; i < v1.size(); i++) {
        result[i] = v1[i] + v2[i];
    }

    result = normalize(result);

    return result;
}

vector<int> addFile(string s1) {
    string file1 = s1, input;
    ifstream inputStream;
    vector<vector<int>> bigInts;
    inputStream.open(file1);

    while (!inputStream.is_open()) {
        cout << "Could not open " << file1 << " , please enter another file name: ";
        getline(cin, file1);
        inputStream.open(file1);
    }

    while (!inputStream.eof()) {
        getline(inputStream, input);

        bigInts.push_back(toDigits(input));
    }
    
    while (bigInts.size() > 1) {
    vector<int> v1 = bigInts.back();
    bigInts.pop_back();
    vector<int> v2 = bigInts.back();
    bigInts.pop_back();

    bigInts.push_back(add(v1, v2));

    }
    
    if (bigInts.size() > 1) {
        cout << "Logic Error";
    }

    return bigInts[0];
}

vector<int> fibonnacciRecursive(int n) {
    vector<int> result;
    if (n > 2) {
        if (memo[n].size() != 0) {
            result = memo[n];
        }
        else {
            result = add(fibonnacciRecursive(n-1),fibonnacciRecursive(n-2));
            memo[n] = result;
        }
    }
    else {
        result.push_back(1);
    }

    return result;
}

void writeDigits(vector<int> v) {
    ofstream outputStream;
    outputStream.open("output.txt");
    for (int i = 0; i < v.size(); i++) {
        outputStream << v[i];
    }
    outputStream << "\n";
    outputStream.close();
}