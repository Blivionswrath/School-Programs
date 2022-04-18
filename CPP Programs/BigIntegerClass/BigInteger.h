#ifndef BIGINTEGER
#define BIGINTEGER

using namespace std;
#include <iostream>
#include <vector>
#include <string>

class BigInteger {

public:
	//This will house all the digits of the big integer
	vector<int> digits;
	bool negative = false;

	BigInteger() {
		digits.push_back(0);
	}

	BigInteger(int a) {
		string s = to_string(a);
		if (s[0] == '-') {
			negative = true;
			s = s.substr(1, s.size() - 1);
		}
		digits = toDigits(s);
	}

	BigInteger(double a) {
		int b = (int)a;
		string s = to_string(b);
		digits = toDigits(s);
	}

	BigInteger(float a) {
		int b = (int)a;
		string s = to_string(b);
		digits = toDigits(s);
	}

	BigInteger(const BigInteger& a) {
		digits = a.digits;
		negative = a.negative;
	}

	//====================
	//BigInteger functions
	//====================

protected:
	//Function used to fill the biginteger vector
	vector<int> toDigits(string s) {
		vector<int> ret(s.size());
		for (unsigned int i = 0; i < ret.size(); i++) {
			if (s[i] == '.') { break; }
			ret[i] = valueOf(s[i]);
		}

		return ret;
	}
	
	void displayDigits() {

		for (int i : digits) {
			cout << i;
		}
		cout << endl;
	}


	//Convert ASCII to integer (This was made for the roman number conversions)
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
			if (d >= 65 && d <= 74) {
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

	BigInteger trimLeadingZeros(BigInteger v) {

		int count = 0;
		for (int i : v.digits) {
			if (i == 0) {
				++count;
			}
			else {
				break;
			}
		}
		vector<int> temp(v.size() - count);
		BigInteger result;
		result.digits = temp;
		

		for (unsigned int i = count, r = 0; i < v.size(); i++, r++) {
			result.digits[r] = v.digits[i];
		}
		return result;
	}


	BigInteger addLeadingZeros(BigInteger v, int count) {
		vector<int> temp(v.size() + count);
		BigInteger result;
		result.digits = temp;
		//Add zeros
		for (int i = 0; i < count; i++) {
			result.digits[i] = 0;
		}
		//Copy Vector
		for (int i = 0; i < v.size(); i++) {
			result.digits[i + count] = v.digits[i];
		}

		return result;
	}

 	BigInteger addTrailingZeros(BigInteger v, int count) {
		BigInteger result = v;
		while (count > 0) {
			result.digits.push_back(0);
			count--;
		}
		return result;
	}

	BigInteger add(BigInteger v1, BigInteger v2) {
		if (v1.size() > v2.size()) {
			int count = v1.size() - v2.size();
			v2 = addLeadingZeros(v2, count);
		}
		else if (v2.size() > v1.size()) {
			int count = v2.size() - v1.size();
			v1 = addLeadingZeros(v1, count);
		}
		vector<int> temp(v1.size());
		BigInteger result;
		result.digits = temp;
		for (int i = 0; i < v1.size(); i++) {
			result.digits[i] = v1.digits[i] + v2.digits[i];
		}

		result = normalize(result, 10);

		return result;
	}
	//change the other functions to BigInteger rather than vectors
	BigInteger subtract(BigInteger v1, BigInteger v2) {
		int difference;
		bool negativeOutcome = false;
		if (v1.size() > v2.size()) {
			difference = v1.size() - v2.size();
			//TODO: This one
			v2 = addLeadingZeros(v2, difference);
		}
		else if (v1.size() < v2.size()) {
			difference = v2.digits.size() - v1.digits.size();
			addLeadingZeros(v1, difference);
		}
		vector<int> temp(v1.size());
		BigInteger v3;
		v3.digits = temp;

		
		//This loop cycles through and subtracts each place from the beginning of the number,
		//if the subtraction outcome is negative, we enter a recursive function to "Borrow" 
		//from the more significant digits
		for (int i = v1.size() - 1; i >= 0; i--) {

			if (v1.digits[i] < v2.digits[i]) {
				
				if (subtractionRecursion(v1, v2, i, i)) {
					//Do nothing unless we get a false outcome (The number will be negative)
				}
				else {
					
					//Send the subtraction the other way so we get a positive outcome with a negative flag
					negativeOutcome = true;
					break;
				}
			}
			v3.digits[i] = v1.digits[i] - v2.digits[i];
		}
		
		if (negativeOutcome){
			v3 = subtract(v2, v1);
			v3.negative = true;
		}
		trimLeadingZeros(v3);
		return v3;
	}

	bool subtractionRecursion(BigInteger &v1, BigInteger &v2, int index, int startIndex) {
		//Base case is if we can decrement the current digit place without causing another negative
		if (v1.digits[index] > v2.digits[index]) {
			v1.digits[index]--;
			return true; 

		}

		//If we reach the end of the big int, return false, if not enter recursion in the next index
		if (index - 1 < 0) {
			return false;
		}
		else if (subtractionRecursion(v1, v2, index - 1, startIndex)) {
			v1.digits[index] += 10;
			//If this isn't the initial index that needs to borrow, decrement for the next to borrow
			if (index != startIndex) {
				v1.digits[index]--;
			}
			return true;
		}


	}

	BigInteger multiply(BigInteger& v1, BigInteger& v2) {
		BigInteger result, smaller, larger, a1;
		int shift = 0;
		int count = 0;
		
		if (v1.size() < v2.size()) {
			count = v1.size() - 1;
			smaller = v1;
			larger = v2;
		}
		else {
			count = v2.size() - 1;
			smaller = v2;
			larger = v1;
		}


		for (int i = count; i >= 0; i--) {
			
			for (int j = smaller.digits[i]; j > 0; j--) {
				a1 += larger;
			}
			if (shift > 0) {
				a1 = addTrailingZeros(a1, shift);
			}
			result += a1;
			a1 = 0;
			shift++;
		}
		
		return result;
	}

	BigInteger divide(BigInteger& a, BigInteger& b) {
		//  x / y;
		BigInteger x = a;
		BigInteger y = b;
		BigInteger result;
		int count = 0;
		int shift;
		if (x == y) {
			result = 1;
		}
		else if(x < y) {
			result = 0;
		}
		else {
			shift = y.size() - x.size();
			addTrailingZeros(x, shift);

			while (x >= y) {
				count++;
				x -= y;
			}
			result += count;
			addTrailingZeros(result, shift);
			shift--;
			count = 0;
			while (shift >= 0) {
				while (x >= y) {
					x -= y;
					count++;
				}

				result.digits[shift] = count;
				count = 0;
				shift--;
			}

		}
		return result;
	}

	int size() {
		return digits.size();
	}
	
	BigInteger normalize(BigInteger v, int base) {
		BigInteger result = addLeadingZeros(v, 1);

		for (int i = result.digits.size() - 1; i >= 0; --i) {
			while (result.digits[i] >= base) {
				result.digits[i] -= base;
				result.digits[i - 1] += 1;
			}
		}
		result = trimLeadingZeros(result);
		return result;
	}

public:
	//Operator overloads
	BigInteger &operator=(const BigInteger& a) {
		digits = a.digits;
		negative = a.negative;
		return *this;
	}

	BigInteger &operator+=(const BigInteger& a){ 
		if (a.negative) {
			BigInteger temp = subtract(*this, a);
			digits = temp.digits;
			return *this;
		}
		else {
			BigInteger temp = add(*this, a);
			digits = temp.digits;
			return *this;
		}
		
	}

	BigInteger operator+(const BigInteger& a) {
		BigInteger temp = *this;
		temp += a;
		return temp;
	}

	BigInteger& operator-=(const BigInteger& a) {
		if (a.negative) {
			BigInteger temp = add(*this, a);
			digits = temp.digits;
			return *this;
		}
		else {		
			BigInteger temp = subtract(*this, a);
			digits = temp.digits;
			negative = temp.negative;
			return *this;
		}
	}

	BigInteger operator-(const BigInteger& a) {
		BigInteger temp = *this;
		temp -= a;
		return temp;
	}

	BigInteger& operator*=(BigInteger& a) {

		if (negative ^ a.negative) {
			//Set these flags to false to avoid logic problems with addition
			negative = false;
			a.negative = false;

			BigInteger temp = multiply(*this, a);
			digits = temp.digits;
			negative = true;
			return *this;
		}
		else {
			negative = false;

			//This duplicate was made to simplify the setting of a's flag to false for the multiplication process
			BigInteger b(a);
			b.negative = false;
			BigInteger temp = multiply(*this, b);
			digits = temp.digits;
			return *this;
		}
	}

	BigInteger operator*(BigInteger& a) {
		BigInteger temp = *this;
		temp.negative = negative;
		temp *= a;
		return temp;
	}

	BigInteger operator/= (BigInteger& a) {
		if (negative ^ a.negative) {
			negative = false;
			BigInteger b = a;
			b.negative = false;
			b = divide(*this, b);
			negative = true;
			digits = b.digits;
			return *this;
		}
		else {
			negative = false;
			BigInteger b = a;
			b.negative = false;
			b = divide(*this, b);
			negative = false;
			digits = b.digits;
			return *this;
		}
	
	}

	BigInteger operator/(BigInteger& a) {
		BigInteger temp = *this;
		temp /= a;
		return temp;
	}

	bool operator==(BigInteger& a) {
		
		bool ret = true;
		BigInteger temp1 = *this;
		BigInteger temp2 = a;

		trimLeadingZeros(temp1);
		trimLeadingZeros(temp2);

		if ((temp1.negative && temp2.negative) || !(temp1.negative && temp2.negative)) {

		}
		else {
			ret = false;
			return ret;
		}

		if (temp1.size() != temp2.size()) {
			ret = false; 
			return ret;
		}
		for (int i = 0; i < a.size(); i++) {
			if (temp1.digits[i] != temp2.digits[i]) {
				ret = false;
				return ret;
			}
		}
		return ret;
	}

	bool operator>(BigInteger& a) {
		BigInteger temp = *this;
		BigInteger temp2 = a;
		bool ret;
		if (temp == temp2) {
			ret = false;
			return ret;
		}
		if (subtract(temp, temp2).negative) {
			ret = false;
		}
		else {
			bool ret = true;
		}
		return ret;
	}

	bool operator>=(BigInteger& a) {
		BigInteger temp1 = *this;
		BigInteger temp2 = a;
		bool ret;
		if (temp1 == temp2) {
			ret = true;
			return ret;
		}
		if (subtract(temp1, temp2).negative) {
			ret = false;
		}
		else {
			ret = true;
		}
		return ret;
	}

	bool operator<(BigInteger& a) {
		BigInteger temp1 = *this;
		BigInteger temp2 = a;

		bool ret; 
		
		if (temp1 == temp2) {
			ret = false;
			return ret;
		}
		if (subtract(temp1, temp2).negative) {
			ret = true;
		}
		else {
			ret = false;
		}
		return ret;
	
	}

	bool operator<=(BigInteger& a) {
		BigInteger temp1 = *this;
		BigInteger temp2 = a;
		bool ret;
		if (temp1 == temp2) {
			ret = true;
			return ret;
		}
		if (subtract(temp1, temp2).negative) {
			ret = true;
		}
		else {
			bool ret = false;
		}
		return ret;
	}

	friend istream &operator>>(istream& is,  BigInteger& a) {
		string s;
		is >> s;
		int n = stoi(s);
		BigInteger b(n);
		a.digits = b.digits;
		a.negative = b.negative;

		return is;
	}

	friend ostream& operator<<(ostream& os, const BigInteger& a) {
		if (a.negative) { os << '-'; }
		for (int i : a.digits) {
			os << i;
		}

		return os;
	}
};

#endif