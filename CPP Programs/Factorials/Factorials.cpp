// Factorials.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

unsigned __int64 factorial_loop(int);
unsigned __int64 factorial_recursive(int);

int main(int argc, char* argv[])
{
    clock_t start, stop;
    double timeElapsed;
    int n;
    string input;
    if (argc > 1) {
        ofstream outputStream;
        outputStream.open("output.txt");
        input = argv[1];
        n =stoi(input);
        unsigned __int64 result = factorial_recursive(n);
        outputStream << "!" << n << " = " << result;
        cout << "!" << n << " = "<< result << "\n Thank you for using factorial calculator!";
        outputStream.close();
    }
    else {


        cout << "Welcome to the factorial calculator!";
        while (true) {

            cout << "Please enter the factorial you would like to calculate, enter 0 to exit\n";
            getline(cin, input);

            n = stoi(input);

            if (n == 0) {
                cout << "Thank you for using factorial calculator!";
                return 0;
            }


            unsigned __int64 result = factorial_recursive(n);

            cout << "!" << n << " = " << result << endl;
        }
    }
   
}

unsigned __int64 factorial_loop(int n) {
    unsigned __int64 result = 1;
    
    if (n > 1) {
        for (int i = 0; i <= n; i++) {
            result *= i;
        }
    }
    
    return result;
}

unsigned __int64 factorial_recursive(int n) {
    unsigned __int64 result = 1;

    if (n > 1) {
        result = n * factorial_recursive(n - 1);
    }
    return result;
}