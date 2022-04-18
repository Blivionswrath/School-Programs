/*
* Programmer: Tanner Gordon
* Program: Roman/Decimal converter
* Class: Online C++ (CS-2363-TW01S)
* Description: Prompts the user to input a roman and decimal number and then displays the conversion of the number to the other type.
*/

using namespace std;
#include <iostream>

#include "RomanNumbers.h"


int main()
{
    cout << "Welcome to the Roman Numbers demo!\n";

        cout << "Testing constructors...\n";
        int x1 = 246;
        RomanNumber n1;
        RomanNumber n2(x1);
        RomanNumber n3((double)x1);
        RomanNumber n4(to_string(x1));
        RomanNumber n5(n4);
        
        cout << endl << "x1 = " << x1 << endl;
        cout << "n1(default) = " << n1 << endl;
        cout << "n2(int) = " << n2 << endl;
        cout << "n3(double) = " << n3 << endl;
        cout << "n4(string) = " << n4 << endl;
        cout << "n5(RomanNumber) = " << n5 << endl;

        cout << endl << "Beginning logic operation tests:\n";

        RomanNumber a1, a2;
        string message;
        cout << "Please enter a roman or decimal number: ";
        cin >> a1;
        cout << "Please enter another: ";
        cin >> a2;

        cout << "a1 is " << a1 << endl;
        cout << "a2 is " << a2 << endl << endl;
        
        a1 == a2 ? message = "True\n" : message = "False\n";
        cout << "a1 == a2: " << message;
        a1 != a2 ? message = "True\n" : message = "False\n";
        cout << "a1 != a2: " << message;
        a1 > a2 ? message = "True\n" : message = "False\n";
        cout << "a1 > a2: " << message;
        a1 >= a2 ? message = "True\n" : message = "False\n";
        cout << "a2 >= a2: " << message;
        a1 <= a2 ? message = "True\n" : message = "False\n";
        cout << "a1 <= a2: " << message;
        a1 < a2 ? message = "True\n" : message = "False\n";
        cout << "a1 < a2: " << message;


        cout << endl << "Now beginning addition demo..." << endl;

        RomanNumber b1, b2, b3;
        cout << "Please enter two Roman or decimal numbers: ";
        cin >> b1 >> b2;

        cout << "b1 is " << b1 << endl;
        cout << "b2 is " << b2 << endl;
        b3 = b1 + b2;
        cout << "b1 + b2 (b3) is " << b3 << endl;

        RomanNumber c1, c2, c3;

        cout << endl << "Now beginning subtraction demo..." << endl;
        cout << "Please enter two Roman or decimal numbers." << endl;
        cin >> c1 >> c2;

        c3 = c1 - c2;
        
        cout << "c1 is " << c1 << endl;
        cout << "c2 is " << c2 << endl;
        cout << "c1 - c2 is " << c3 << endl;
        RomanNumber d1, d2, d3;
        cout << "Now beginning the multiplication demo..." << endl;
        cout << "Please enter two Roman or decimal numbers: " << endl;
        cin >> d1 >> d2;
        d3 = d1 * d2;
        cout << "d1 is " << d1 << endl;
        cout << "d2 is " << d2 << endl;
        cout << "d1 * d2 is " << d3 << endl;
        
        RomanNumber e1, e2, e3;

        cout << endl << "Now beginning the division demo..." << endl;
        cout << "Please enter two Roman or decimal numbers: " << endl;
        cin >> e1 >> e2;

        e3 = e1 / e2;
 
        cout << "e1 is " << e1 << endl;
        cout << "e2 is " << e2 << endl;
        cout << "e1 / e2 is " << e3 << endl;

        cout << "Thank you for using the Roman Number demo!";

}