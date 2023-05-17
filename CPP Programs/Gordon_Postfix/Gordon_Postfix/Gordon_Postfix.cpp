/*
* Programmer: Tanner Gordon
* Program: Integer postfix calculator
* Description: A calculator that uses postfix operatoins for integers only.
* Class: Online C++ (CS-2363-TW01S)
*/

using namespace std;

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

int calculate(vector<string> tokens);
int add(int n1, int n2);
int subtract(int n1, int n2);
int divide(int n1, int n2);
int multiply(int n1, int n2);
int modulos(int n1, int n2);

bool valid = true;

int main()
{

    cout << "Welcome to the postfix calculator!\n";
    
    while (true) {
        vector<string> tokens;
        string input, temp;
        ifstream inputStream;
        stringstream tokenStream;
        int sum = 0, invalid = 0;

        cout << "Would you like to read input from a file? Y/N (0 to exit) ";
        getline(cin, input);
        if (input == "0") {
            cout << "Thank you for using the postfix calculator!\n";
            return 0;
        }
        
        if (input == "n" || input == "N") {
            cout << "Please enter the expression you would like to evaluate or enter 0 to exit: ";
            getline(cin, input);
            
            if (input == "0") {
                cout << "Thank you for using the postfix calculator!\n";
                return 0;
            }


            //Tokenize the string with a space delimiter
            while (getline(tokenStream, temp, ' ')) {
                tokens.push_back(temp);
            }

            int result = calculate(tokens);

            cout << result << endl;
        }
        else {
            cout << "Please enter the name of the file you would like to read from: ";
            getline(cin, input);
            inputStream.open(input.c_str());

            while (!inputStream.eof()) {
                getline(inputStream, input);
                tokenStream.str(input);
                tokenStream.clear();
                //tokenize
                tokens.erase(tokens.begin(), tokens.end());
                while (getline(tokenStream, temp, ' ')) {
                    tokens.push_back(temp);
                }
                
                int result = calculate(tokens);

                if (!valid) {
                    invalid++;
                    valid = true;
                    continue;
                }
                else {
                    cout << result << endl;
                    sum += result;
                }
            }
            cout << "The total sum of calculations is: " << sum << endl <<
                "The amount of invalid entries is: " << invalid << endl;
        }

        

    }

}

int calculate(vector<string> tokens) {
    int returnValue, toAdd;
    vector<int> intStack;
    int n1, n2, result;

    for (int i = 0; i < tokens.size(); i++) {
        //If the token size is 1, check to see if it is an operator
        if (tokens[i].size() == 1 && valid) {
            
            switch (tokens[i][0]){
            
            case '+' :
                if (intStack.size() < 2) {
                    cout << "Not enough operand in stack" << endl;
                    valid = false;
                    break;
                }
                n1 = intStack.back();
                intStack.pop_back();
                n2 = intStack.back();
                intStack.pop_back();
                result = add(n1, n2);
                intStack.push_back(result);
                continue;
            
            case '-' :
                if (intStack.size() < 2) {
                    cout << "Not enough operand in stack" << endl;
                    valid = false;
                    break;
                }
                n1 = intStack.back();
                intStack.pop_back();
                n2 = intStack.back();
                intStack.pop_back();
                result = subtract(n2, n1);
                intStack.push_back(result);
                continue;
            
            case '/' :
                if (intStack.size() < 2) {
                    cout << "Not enough operand in stack" << endl;
                    valid = false;
                    break;
                }
                n1 = intStack.back();
                intStack.pop_back();
                n2 = intStack.back();
                intStack.pop_back();
                result = divide(n2, n1);
                intStack.push_back(result);
                continue;
            
            case '*' :
                if (intStack.size() < 2) {
                    cout << "Not enough operand in stack" << endl;
                    valid = false;
                    break;
                }
                n1 = intStack.back();
                intStack.pop_back();
                n2 = intStack.back();
                intStack.pop_back();
                result = multiply(n1, n2);
                intStack.push_back(result);
                continue;
            
            case '%' :
                if (intStack.size() < 2) {
                    cout << "Not enough operand in stack" << endl;
                    valid = false;
                    break;
                }
                n1 = intStack.back();
                intStack.pop_back();
                n2 = intStack.back();
                intStack.pop_back();
                result = modulos(n2, n1);
                intStack.push_back(result);
                continue;
            }
        }

        if (valid) {
            toAdd = stoi(tokens[i]);
            intStack.push_back(toAdd);
        }
    }

    if (intStack.size() > 1) {
        cout << "WARNING: The entire int stack was not consumed.\n";
        valid = false;
    }
    if (intStack.size() > 0) {
        returnValue = intStack.back();
        return returnValue;
    }
    else {
        returnValue = 0;
        return returnValue;
    }

}

//Operator functions
int add(int n1, int n2) {
    int result = n1 + n2;
    return result;
}

int subtract(int n1, int n2) {
    int result = n1 - n2;
    return result;
}

int divide(int n1, int n2) {
    int result = n1 / n2;
    return result;
}

int multiply(int n1, int n2) {
    int result = n1 * n2;
    return result;
}

int modulos(int n1, int n2) {
    int result = n1 % n2;
    return result;
}