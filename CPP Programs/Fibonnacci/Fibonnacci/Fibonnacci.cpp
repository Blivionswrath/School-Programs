// Fibonnacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <string>


using namespace std;

unsigned __int64 fibonacci_loop(int);
unsigned __int64 fibonacci_recursive(int);

unsigned __int64* memo; 


int main()
{
    clock_t start, finish;
    unsigned __int64 result;
    double elapsedTime;
    
    string input;
    cout << "Welcome to the fibonacci program!\n";  
    while (true) {

            cout << "Please enter the index you would like to calculate using recursion: ";
            getline(cin, input);
            int n = stoi(input);
            memo = new unsigned __int64[n + 1];
            for (int i = 0; i < n+1; i++) {
                memo[i] = 0;
            }
            start = clock();
            result = fibonacci_recursive(n);
            finish = clock();

            elapsedTime = (double)((finish - start) / CLOCKS_PER_SEC);
            cout << "Time required: " << elapsedTime << " seconds." << endl;

            cout << "fib(" << input << ") = " << result << endl;

    }
}

unsigned __int64 fibonacci_loop(int n) {


    unsigned __int64 result = 1;
    if (n > 2) {
        unsigned __int64 a = 1;
        unsigned __int64 b = 1;
        for (int count = 3; count <= n; count++) {
            result = a + b;
            a = b;
            b = result;
        }
    }
    return result;
}

unsigned __int64 fibonacci_recursive(int n) {



    unsigned __int64 result = 1;
    if (n > 2) {
        unsigned __int64 n1, n2;
    
        if (memo[n] != 0) {
            result = memo[n];
        }
        else {
            result = fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
            memo[n] = result;

        }
    }
    return result;
}
