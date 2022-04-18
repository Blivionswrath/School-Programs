//Programmer: Tanner Gordon
//Program: BigInteger
//Online C++ (CS-2363-TW01S)


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "BigInteger.h"
using namespace std;

int main(int argc, string * argv[])
{
    
    int inputInt;
    float inputFloat;


    cout << "Please enter an integer: ";
    cin >> inputInt;
    cout << "Please enter a floating point number: ";
    cin >> inputFloat;

    cout << endl << "Constructor tests: ";
    BigInteger a1(inputInt);
    BigInteger a2(inputFloat);
    BigInteger a3(a2);

    cout << "a1: " << a1 << endl;
    cout << "a2: " << a2 << endl;
    cout << "a3: " << a3 << endl;

    cout << endl << "Beggining addition test: " << endl;

    BigInteger c1, c2;
    cout << "Please two BigIntegers to add: ";
    cin >> c1;
    cin >> c2;

    BigInteger c3;
    c3 = c1 + c2;
    BigInteger c4(c3);
    c4 += c3;

    cout << "C1 is " << c1 << endl;
    cout << "C2 is " << c2 << endl;
    cout << "C3 (c1 + c2) is " << c3 << endl;
    cout << "C4 (c4 += c3) is " << c4 << endl;
    
    cout << endl << "Starting subtraction tests: " << endl;

    cout << "Please enter two BigIntegers: ";

    BigInteger d1, d2, d3;
    cin >> d1;
    cin >> d2;

    d3 = d1 - d2;
    cout << "D1 is " << d1 << endl;
    cout << "D2 is " << d2 << endl;
    cout << "D3 (d1 - d2) is " << d3 << endl; 
    
    BigInteger e1, e2, e3;

    cout << "Starting the multiplication tests: " << endl;
    cout << "Please enter two BigIntegers to multiply: " << endl;
    cin >> e1;
    cin >> e2;

    e3 = e1 * e2;

    cout << "E1 is " << e1 << endl;
    cout << "E2 is " << e2 << endl;
    cout << "E3 (e1 * e2) is " << e3 << endl;
    
    BigInteger f1, f2, f3;

    cout << "Starting the division tests: " << endl;
    cout << "Please enter two BigIntegers: " << endl;
    cin >> f1;
    cin >> f2;

    f3 = f1 / f2;
    
    cout << "F1 is " << f1 << endl;
    cout << "F2 is " << f2 << endl;
    cout << "F3 (F1 / F2) is " << f3 << endl;

    cout << "\nThank you for using BigInteger!";

}