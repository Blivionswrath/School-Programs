//Programmer: Tanner Gordon
//C++ Online OCCC
//Bag program

#include <string>
#include <ostream>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <ctime>

using namespace std;

string toLowerCase(string s);
string removePunctuation(string s);

clock_t start, stop;

struct BagNode {
	BagNode* next;
	string dataValue;
	int dataCount;
};

class Bag {
private:
	BagNode* head;
public:
	Bag() {
		head = NULL;
	}

	void traverse(ostream* sout = &cout) {
		BagNode* p = head;

		while (p) {
			*sout << p->dataValue << " (" << p->dataCount << ")\n";
			p = p->next;
		}

	}


	void insert(string &value) {


		
		string lowerCaseValue = value;
		string temp = value;
		
		//I made the lowercase step inline to increase performance
		if (value[0] >= 65   && value[0] <= 90) {
			lowerCaseValue[0] += 32;
		}
		if (head == NULL) {
			BagNode* newNode = new BagNode;
			newNode->dataValue = temp;
			newNode->dataCount = 1;
			newNode->next = NULL;
			head = newNode;
			return;
		}
		else if (head->next == NULL && toLowerCase(head->dataValue) == lowerCaseValue) {
			head->dataCount++;
		}
		BagNode* current = head;
		BagNode* nextNode = current->next;
		
		if (toLowerCase(head->dataValue) > lowerCaseValue) {
			BagNode* newNode = new BagNode;
			newNode->next = head;
			current->next = nextNode;
			newNode->dataValue = value;
			newNode->dataCount = 1;
			
			head = newNode;
			return;
		}

		
		string currentLowerCase;
		string nextLowerCase;
		string currentUpperCase;
		string nextUpperCase;
		while (current && nextNode) {
			

			if (current->dataValue[0] >= 65 && current->dataValue[0] <= 90) {
				currentLowerCase = current->dataValue;
				currentLowerCase[0] += 32;
			}
			else {
				currentLowerCase = current->dataValue;
			}
			if (nextNode->dataValue[0] >= 65 && nextNode->dataValue[0] <= 90) {
				nextLowerCase = nextNode->dataValue;
				nextLowerCase[0] += 32;
			}
			else {
				nextLowerCase = nextNode->dataValue;
			}

			if (current->dataValue[0] >= 'a' && current->dataValue[0] <= 'z') {
				currentUpperCase = current->dataValue;
				currentUpperCase[0] -= 32;
			}

			if (nextNode->dataValue[0] >= 'a' && current->dataValue[0] <= 'z') {
				nextUpperCase = nextNode->dataValue;
				nextUpperCase[0] -= 32;
			}
			

			//If they match, increment
			if (current->dataValue == value) {
				current->dataCount++;
				return;
			}
			//If the current can be converted to lower and it matches, change to lower and increment
			else if (currentLowerCase == value) {
				current->dataValue = currentLowerCase;
				current->dataCount++;
				return;
			}
			//If the current has been changed to upper case and matches, increment the lower case value and move on
			else if (currentUpperCase == value) {
				current->dataCount++;
				return;
			}

			if (currentLowerCase < lowerCaseValue && nextLowerCase > lowerCaseValue) {
				BagNode* newNode = new BagNode;
				newNode->dataValue = value;
				newNode->dataCount = 1;
				newNode->next = nextNode;
				current->next = newNode;
				return;
			}
			else if (current->next == NULL) {
				//If we reach the end of the list and haven't inserted, put the new item at the end
				BagNode* newNode = new BagNode;
				current->next = newNode;
				newNode->dataValue = value;
				newNode->dataCount = 1;
				newNode->next = NULL;
				return;				

			}
			current = current->next;
			if (current->next) {
				nextNode = current->next;
			}
		}
	}


};


//Helper function that returns the string in lower case
string toLowerCase(string s) {
	string result = s;
	for (int i = 0; i < s.size(); i++) {

		if (s[i] >= 65 && s[i] <= 90) {
			result[i] = s[i] + 32;
		}
		else {
			result[i] = s[i];
		}
	}


	return result;
}


int main(int argc, char* argv[]) {
	string inputFile, outputFile, input;
	ifstream inputStream;
	ofstream outputStream;
	Bag bag;

	if (argc >= 3) {
		inputFile = argv[1];
		outputFile = argv[2];
	}
	else if (argc == 2) {
		inputFile = argv[1];
		cout << "Please enter the name of the file to write to: ";
		getline(cin, outputFile);
	}
	else {
		cout << "Please enter the name of a to read from: ";
		getline(cin, inputFile);
		cout << "Please enter the name of the file to write to: ";
		getline(cin, outputFile);
	}

	inputStream.open(inputFile);

	while (!inputStream.is_open()) {
		cout << "Could not open " << inputFile << ". Please enter another file to read: " << endl;
		getline(cin, inputFile);
		inputStream.open(inputFile);
	}
	if (outputFile != "") {
		outputStream.open(outputFile);
	}
	double timeElapsed;
	start = clock();
	while (inputStream >> input) {


		if (input == "") {
			continue;
		}
		string processedString = removePunctuation(input);

		bag.insert(processedString);
	}
	if (outputStream.is_open()) {
		bag.traverse(&outputStream);
	}
	else {
		bag.traverse();
	}

	stop = clock();

	timeElapsed = (stop - start) / CLOCKS_PER_SEC;

	cout << "\nTime elapsed is: " << timeElapsed << " seconds";

	cout << "\nThank you for using the string bag!";

}

string removePunctuation(string s) {

	string result = s;

	while (result[0] > 127 || result[0] < 0) {
		result.erase(0, 1);
	}


	int firstEraseIndex = 0, lastEraseIndex = 0;
	bool setFirst = true, setLast = false;
	bool complete = false, lastIteration = false;
	while (!complete) {
		for (int i = 0; i < result.size(); i++) {
			if (i == result.size() - 1) {
				lastIteration = true;
			}
			if (setFirst && (result[i] < 0 || result[i] > 127)) {
				firstEraseIndex = i;
				setFirst = false;
				setLast = true;
			}

			//If we need to find the last index to erase
			if ((setLast && !(result[i] > 127 || result[i] < 0)) || (lastIteration && setLast)) {

				if (lastIteration) {
					lastEraseIndex = i;
				}
				else {
					lastEraseIndex = i - 1;
				}

				if (result.size() == 1) {
					lastEraseIndex = 1;
				}

				result.erase(firstEraseIndex, lastEraseIndex);
				firstEraseIndex = lastEraseIndex = 0;
				lastIteration = false;
				break;
			}

			if (lastIteration) {
				complete = true;
			}
		}
		if (result == "") { return ""; }
	}
	int lastIndex = result.size() - 1;
	while (result[lastIndex] > 127 || result[lastIndex] < 0) {

		result.erase(lastIndex);
		lastIndex = result.size() - 1;
	}

	bool alnum = isalnum(result[0]);

	while (!alnum) {
		result.erase(0, 1);
		alnum = isalnum(result[0]);
		if (result == "") { return ""; }
	}

	lastIndex = result.size() - 1;

	alnum = isalnum(result[lastIndex]);

	while (!alnum) {
		result.erase(lastIndex);
		lastIndex = result.size() - 1;
		alnum = isalnum(result[lastIndex]);
	}


	return result;
}