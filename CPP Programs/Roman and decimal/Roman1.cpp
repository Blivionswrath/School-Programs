/*
* Programmer: Tanner Gordon
* Program: Roman/Decimal converter
* Class: Online C++ (CS-2363-TW01S)
* Description: Prompts the user to input a roman and decimal number and then displays the conversion of the number to the other type.
*/

using namespace std;
#include <iostream>
#include <String>
#include <vector>
#include <array>
#include <fstream>

bool isValidDecimalNumber(string s);
bool isValidRomanNumber(string s);
string convertRomanToDecimal(string s);
string convertDecimalToRoman(string s);
int romanConversionRates(char c);

//M,D,C,L,X,V,I uppercase ASCII values (Sorted from highest roman value to low)
array<char, 7> romanNumbersASCII = { 77,68,67,76,88,86,73};
int romanToDec = 0, decToRoman = 0, validRoman = 0, validDecimal = 0, invalid = 0, romanSum = 0, decimalSum = 0, valid = 0;
bool fileInput;

int main()
{
    ifstream inputStream;
    

    cout << "Welcome to the Roman/Decimal Converter!\n";
    while (true) {
        string input, fileName;

        cout << "Would you like to use input from a file? Y/N (0 to exit)";
        getline(cin, input);

        if (input == "y" || input == "Y") {
            fileInput = true;
        }
        else if (input == "n" || input == "N") {
            fileInput = false;
        }  
        else if (input == "0") {
            string plural = "";
            cout << "Thank you for using the Roman Decimal Converter.\n";

            if (decToRoman + romanToDec > 1 || decToRoman + romanToDec == 0) { plural = "s"; }

            cout << decToRoman + romanToDec << " value" << plural << " were converted. (" << decToRoman << " to Roman,"
                << romanToDec << " to decimal.)\n";
            return 0;
        }
        else {
            continue;
        }

        string output;
        
        if (!fileInput) {
            cout << "Please enter a number to convert, enter 0 to exit: ";
            getline(cin, input);
            cout << endl;
            if (!(isValidDecimalNumber(input) || isValidRomanNumber(input))) {
                cout << input << " is not a valid input.\n";
                continue;
            }
            if (input == "0") {
                string plural = "";
                cout << "Thank you for using the Roman Decimal Converter.\n";

                if (decToRoman + romanToDec > 1 || decToRoman + romanToDec == 0) { plural = "s"; }

                cout << decToRoman + romanToDec << " value" << plural << " were converted. (" << decToRoman << " to Roman,"
                    << romanToDec << " to decimal.)\n";
                return 0;
            }
        }
        else {
            cout << "Please enter the name of the file you would like to read from: ";
            getline(cin, fileName);
            inputStream.open(fileName.c_str());
            cout << endl;
            
            while (!inputStream.eof()) {
                getline(inputStream, input);
                
                if (!(isValidDecimalNumber(input) || isValidRomanNumber(input))) {
                    cout << input << " is not a valid input. \n";
                    invalid++;
                    continue;
                }
                else {
                    valid++;
                }

                output = isValidDecimalNumber(input) ? convertDecimalToRoman(input) :convertRomanToDecimal(input);
                cout << output << endl;
            }

        }

        
        //This line prevents crashing if no input is given
        if (input == "") { continue; }

        //output = isValidDecimalNumber(input) ? convertDecimalToRoman(input) : convertRomanToDecimal(input);
        //cout << output << endl;
        cout << "The decimal sum of the converted values: " << decimalSum << endl <<
            "The Roman sum of the converted values: " << romanSum << endl <<
            "The number of valid entries: " << valid << endl <<
            "The number of invalid entries: " << invalid << endl;
    }
}

bool isValidDecimalNumber(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!(s[i] >= 48 && s[i] <= 57)) return false;
    }
    return true;
}

bool isValidRomanNumber(string s) {
    
    bool currentLetter = false;

    //Character validation
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < romanNumbersASCII.size(); j++) {
            if (s[i] == romanNumbersASCII[j] || s[i] == romanNumbersASCII[j] + 32) {
                currentLetter = true;
            }
        }
        if (!currentLetter) return false;
    }
    //Number validation
    for (int i = 0; i < s.length(); i++) {
        int romanIndex1 = NULL;
        int romanIndex2 = NULL;

        for (int j = 0; j < romanNumbersASCII.size(); j++) {
            if (s.length() - i <= 2) {break;}
            if (s[i] == romanNumbersASCII[j] || s[i] == romanNumbersASCII[j] + 32) {
                romanIndex1 = j;
                
                //This loop is to find roman index 2 which is just for number validation
                for (int k = 0; k < romanNumbersASCII.size(); k++) {
                    if (s[i + 2] == romanNumbersASCII[k] || s[i + 2] == romanNumbersASCII[k] + 32) {
                        romanIndex2 = k;
                    }
                }
            }
            if (s[i] == s[i + 1] && romanIndex2 < romanIndex1) {
                cout << "The following string of characters is invalid: " << s[i] << s[i + 1] << s[i + 2] << endl;
                return false;
            }

        }
    }
    return true;
}

string convertRomanToDecimal(string s) {
    int sum = 0;
    int previousValue;
    vector<int> intValues;

    //Parse from ASCII roman to integer
    for (int i = 0; i < s.size(); i++) {
        intValues.push_back(romanConversionRates(s[i]));
    }
    //Operate on the decimal numbers using roman rules
    for (int i = 0; i < intValues.size(); i++) {
        if (i + 1 < intValues.size() && intValues[i] < intValues[i + 1]) {
            sum += intValues[i + 1] - intValues[i];
            i++;
        }
        else {
            sum += intValues[i];
        }
    }
    romanToDec++;
    string result = to_string(sum);
    decimalSum += sum;
    return result;
}

string convertDecimalToRoman(string s) {
    int value;
    string ret;

    value = stoi(s);
    romanSum += value;
    while (value != 0) {
        if (value >= 1000) {
            value -= 1000;
            ret += "M";
            continue;
        }
        else if (value < 1000 && value >= 900) {
            value -= 900;
            ret += "CM";
            continue;
        }
        else if (value >= 500) {
            value -= 500;
            ret += "D";
            continue;
        }
        else if (value < 500 && value >= 400) {
            value -= 400;
            ret += "CD";
            continue;
        }
        else if (value >= 100) {
            value -= 100;
            ret += "C";
            continue;
        }
        else if (value < 100 && value >= 90) {
            value -= 90;
            ret += "XC";
            continue;
        }
        else if (value >= 50) {
            value -= 50;
            ret += "L";
            continue;
        }
        else if (value < 50 && value >= 40) {
            value -= 40;
            ret += "XL";
            continue;
        }
        else if (value >= 10) {
            value -= 10;
            ret += "X";
            continue;
        }
        else if (value == 9) {
            value -= 9;
            ret += "IX";
            continue;
        }
        else if (value >= 5) {
            value -= 5;
            ret += "V";
            continue;
        }
        else if (value == 4) {
            value -= 4;
            ret += "IV";
            continue;
        }
        else if (value >= 1) {
            value -= 1;
            ret += "I";
            continue;
        }
    }
    decToRoman++;
    return ret;
}
//Helper functions

//This function was created to clean the roman conversion function.
//Returns the int equivelant of a single roman char
int romanConversionRates(char c){
    int index = NULL;
    int result = -1;
    for (int i = 0; i < romanNumbersASCII.size(); i++) {
        if (romanNumbersASCII[i] == c || romanNumbersASCII[i] + 32 == c) {
            index = i;
            break;
        }
    }
 
    switch (index) {
        case 0:
            result = 1000;
            break;
        case 1:
            result = 500;
            break;
        case 2:
            result = 100;
            break;
        case 3:
            result = 50;
            break;
        case 4:
            result = 10;
            break;
        case 5:
            result = 5;
            break;
        case 6:
            result = 1;
            break;
    }
    return result;
}