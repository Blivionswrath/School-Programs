#ifndef ROMANNUMBERS
#define ROMANNUMBERS

#include <string>
#include <array>
#include <vector>

using namespace std;

class RomanNumber {

private:
	int theValue;
	

	bool isValidDecimalNumber(string s) {
		for (int i = 0; i < s.length(); i++) {
			if (!(s[i] >= 48 && s[i] <= 57)) return false;
		}
		return true;
	}

	bool isValidRomanNumber(string s) {
	array<char, 7> romanNumbersASCII = { 77,68,67,76,88,86,73 };

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
				if (s.length() - i <= 2) { break; }
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
		string result = to_string(sum);
		return result;
	}

	//This is a helper function made to clean up the conversion function	
	int romanConversionRates(char c) {
		array<char, 7> romanNumbersASCII = { 77,68,67,76,88,86,73 };
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


public:

	const static int maxValue = 10000;

	RomanNumber() {
		theValue = 1;
	}

	RomanNumber(int n) {
		try {
			if (n <= 0) {
				throw 1;
			}
			else if (n > maxValue) {
				throw 2;
			}
			else {
				theValue = n;
			}
		}
		catch (int* e) {
			cout << "ERROR: " << n << "\nPlease enter a valid number.\n";
			theValue = 1;
		}
	}


	RomanNumber(double n) {
		int i = (int)n;
		try {
			if (i <= 0) {
				throw 1;
			}
			else if (i > maxValue) {
				throw 2;
			}
			else {
				theValue = i;
			}
		}
		catch (int* e) {
			cout << "ERROR: " << n << "\nPlease enter a valid number.\n";
			theValue = 1;
		}
	}

	RomanNumber(string s) {
		int n;
		try {
			if (isValidDecimalNumber(s)) {
				n = stoi(s);
			}
			else if (isValidRomanNumber(s)) {
				n = stoi(convertRomanToDecimal(s));
			}
			else {
				cout << endl << "Please enter a valid roman or decimal." << endl;
				throw 0;
			}
		

			if (n <= 0) {
				throw 1;
			}
			else if (n > maxValue) {
				throw 2;
			}
			else {
				theValue = n;
			}
		}
		catch (int* e) {
			cout << "ERROR: Please enter a valid number.\n";
			theValue = 1;
		}
	}

	RomanNumber(RomanNumber& n) {
		theValue = n.theValue;
	}


	
	string toString() {
		string ret;
		int value = theValue;
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

		return ret;
	}

	//==================
	//Operator overloads
	//==================

	operator int() {
		return theValue;
	}

	operator double() {
		return (double)theValue;
	}

	operator string() {
		return to_string(theValue);
	}

	RomanNumber& operator+=(const RomanNumber& n) {
		theValue += n.theValue;
		return *this;
	}

	RomanNumber& operator+(const RomanNumber& n) {
		RomanNumber temp = *this;
		temp += n;
		return temp;
	}

	RomanNumber& operator-=(const RomanNumber& n) {
		if (n.theValue >= theValue) {
			theValue = 1;
		}
		else {
			theValue -= n.theValue;
		}
		return *this;
	}

	RomanNumber& operator-(const RomanNumber& n) {
		RomanNumber temp = *this;
		temp -= n;
		return temp;
	}
	
	RomanNumber& operator*=(const RomanNumber& n) {
		theValue *= n.theValue; 
		return *this;
	}

	RomanNumber& operator*(const RomanNumber& n) {
		RomanNumber temp = *this;
		temp *= n;
		return temp;
	}

	RomanNumber& operator/=(const RomanNumber& n) {
		if (theValue < n.theValue) {
			theValue = 1;
		}
		else {
			theValue /= n.theValue;
		}
		return *this;
	}

	RomanNumber& operator/(const RomanNumber& n) {
		RomanNumber temp = *this;
		temp /= n;
		return temp;
	}

	bool operator==(RomanNumber n) {
		bool result = false;
		if (theValue == n.theValue) { result = true; }
		return result;
	}

	bool operator!=(RomanNumber n) {
		bool result = false;
		if (!(*this == n)) { result = true; }
		return result;
	}

	bool operator>(RomanNumber n) {
		bool result = true;
		if (theValue <= n.theValue) { result = false; }
		return result;
	}

	bool operator>=(RomanNumber n) {
		bool result = true;
		if (theValue < n.theValue) { result = false; }
		return result;
	}

	bool operator<(RomanNumber n) {
		bool result = true;
		if (theValue >= n.theValue) { result = false; }
		return result;
	}

	bool operator<=(RomanNumber n) {
		bool result = true;
		if (theValue > n.theValue) { result = false; }
		return result;
	}

	friend istream& operator>>(istream& is, RomanNumber& n) {
		string s;
		is >> s;
		RomanNumber b(s);
		n = b;
		return is;
	}

	friend ostream& operator<<(ostream& os, RomanNumber& n) {
		os << n.toString();
		return os;
	}

};
#endif