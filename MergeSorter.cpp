#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

void naturalMerge(ifstream& input1, ifstream& input2, ofstream& output1,
	ofstream& output2, ifstream& mainInput, ofstream& mainOutput);
void binaryMerge(ifstream& input1, ifstream& input2, ofstream& output1, ofstream& output2,
	ifstream& mainInput, ofstream& mainOutput);
bool naturalSplit(ifstream& input, ofstream& output1, ofstream& output2);
bool binarySplit(ifstream& input, ofstream& output1, ofstream& output2, int splitCount);
bool naturalMerge(ifstream& input1, ifstream& input2, ofstream& output);
bool binaryMerge(ifstream& input1, ifstream& input2, ofstream& output, int splitCount);

int total = 0;
string fileName;
clock_t start, stop;
double timeElapsed;

//Command line paramaters are: Merge type(B/N), input file name
int main(int argc, char* argv[]) {
	string input;
	ifstream mainInput, input1, input2;
	ofstream output1, output2, mainOutput;

	if (argc == 3) {
		fileName = argv[2];
		while (true) {

			if (argv[1][0] == 'b' || argv[1][0] == 'B') {
				binaryMerge(input1, input2, output1, output2, mainInput, mainOutput);
				break;
			}
			else if (argv[1][0] == 'N' || argv[1][0] == 'n') {
				naturalMerge(input1, input2, output1, output2, mainInput, mainOutput);
				break;
			}
			else {
				cout << "Please enter a b or n for merge selection\n";
				return 0;
			}
		}
	}
	else {
		cout << "Welcome to the merge sorter!\nWould you like to use a binary or natural sort? B/N ";
		getline(cin, input);
	
	
		while (true) {

			if (input[0] == 'b' || input[0] == 'B') {
				binaryMerge(input1, input2, output1, output2, mainInput, mainOutput);
				break;
			}
			else if (input[0] == 'n' || input[0] == 'N') {
				naturalMerge(input1, input2, output1, output2, mainInput, mainOutput);
				break;
			}
			else {
				cout << "Please enter either B or N\n";
				getline(cin, input);
			}
		}
	}

	timeElapsed = (stop - start) / CLOCKS_PER_SEC;
	cout << "\nTime Elapsed: " << timeElapsed << " seconds";

	return 0;
}

bool naturalSplit(ifstream& input, ofstream& output1, ofstream& output2) {
	int buffer1, buffer2 = -1;
	bool sorted = true;

	if (input >> buffer1) {

	}
	else {
		cout << "There was no input.\n";

	}
	bool shouldSwitch, useOutput1;
	useOutput1 = true;
	shouldSwitch = false;
	output1 << buffer1 << ' ';
	buffer2 = buffer1;
	
	int iteration = 1;

	while (input >> buffer1) {
		iteration++;

		shouldSwitch = buffer1 < buffer2;



		if (shouldSwitch) { useOutput1 = !useOutput1; }
		if (sorted && shouldSwitch) { sorted = false; }

		if (useOutput1) {
			output1 << buffer1 << ' ';	
			buffer2 = buffer1;
		}
		else {
			output2 << buffer1 << ' ';
			buffer2 = buffer1;
		}

	}
	return sorted;
}

//Numbered Input/Output serve as the temporary file streams, currently no streams need to be opened prior to function call
void naturalMerge(ifstream& input1, ifstream& input2, ofstream& output1, ofstream& output2,
	ifstream& mainInput, ofstream& mainOutput) {

	string inputFile, outputFile;
	if (fileName == "") {
		cout << "Please enter the name of the file you would like to sort: ";
		getline(cin, inputFile);
	}
	else {
		inputFile = fileName;
	}

	mainInput.open(inputFile);

	while (!mainInput.is_open()) {
		cout << inputFile << " could not be opened, please enter the name of another file: ";
		getline(cin, inputFile);
		mainInput.open(inputFile);
	}
	//Create output file name

	for (int i = 0; i < inputFile.size(); i++) {
		if (inputFile[i] == '.') {
			outputFile = inputFile.substr(0, i) + "_sorted.txt";
			break;
		}
	}

	start = clock();

	output1.open("temp1.txt");
	output2.open("temp2.txt");
	naturalSplit(mainInput, output1, output2);
	mainInput.close();
	output1.close();
	output2.close();

	input1.open("temp1.txt");
	input2.open("temp2.txt");
	mainOutput.open(outputFile);
	naturalMerge(input1, input2, mainOutput);
	mainOutput.close();
	input1.close();
	input2.close();


	bool sorted = false;

	while (!sorted) {
		mainInput.open(outputFile);
		output1.open("temp1.txt");
		output2.open("temp2.txt");
		sorted = naturalSplit(mainInput, output1, output2);
		mainInput.close();
		output1.close();
		output2.close();

		mainOutput.open(outputFile);
		input1.open("temp1.txt");
		input2.open("temp2.txt");
		naturalMerge(input1, input2, mainOutput);
		mainOutput.close();
		input1.close();
		input2.close();

	}

	remove("temp1.txt");
	remove("temp2.txt");
	stop = clock();
	cout << "Thank you for using the natural merge sorter!\nThe data has been sorted to " << outputFile;
}

bool naturalMerge(ifstream& input1, ifstream& input2, ofstream& output) {
	int buffer1, buffer2;
	bool file1, file2;
	file1 = file2 = true;

	input1 >> buffer1;
	input2 >> buffer2;
	int iteration = 1;

	if (buffer2 < 0) { file2 = false; }

	while ( file1 && file2 ) {

		if (buffer1 <= buffer2) {
			output << buffer1 << ' ';
			if (input1 >> buffer1) {

			}
			else {
				file1 = false;
				continue;
			}
		}
		else {
			output << buffer2 << ' ';
			if (input2 >> buffer2) {
				
			}
			else {
				file2 = false; 
				break;
			}
		}
	}

	//Finish off whichever file has leftover input

	if (file1) {

		output << buffer1 << ' ';
		while (input1 >> buffer1) {
			output << buffer1 << ' ';
		}
	}

	if (file2) {

		output << buffer2 << ' ';
		while (input2 >> buffer2) {
			output << buffer2 << ' ';
		}
	}
	return true;
}

//Numbered Input/Output serve as the temporary file streams, currently no streams need to be opened prior to function call
void binaryMerge(ifstream& input1, ifstream& input2, ofstream& output1, ofstream& output2, 
	ifstream& mainInput, ofstream& mainOutput) {
	
	string inputFile, outputFile;

	if (fileName == "") {
		cout << "Please enter the name of the file you would like to sort: ";
		getline(cin, inputFile);
	}
	else {
		inputFile = fileName;
	}

	mainInput.open(inputFile);

	while (!mainInput.is_open()) {
		cout << inputFile << " could not be opened, please enter the name of another file: ";
		getline(cin, inputFile);
		mainInput.open(inputFile);
	}
	//Create output file name

	for (int i = 0; i < inputFile.size(); i++) {
		if (inputFile[i] == '.') {
			outputFile = inputFile.substr(0, i) + "_sorted.txt";
			break;
		}
	}


	int splitCount = 1;
	
	start = clock();

	output1.open("temp1.txt");
	output2.open("temp2.txt");

	binarySplit(mainInput, output1, output2, splitCount);

	mainInput.close();
	output1.close();
	output2.close();

	input1.open("temp1.txt");
	input2.open("temp2.txt");
	mainOutput.open(outputFile);

	binaryMerge(input1, input2, mainOutput, splitCount);

	input1.close();
	input2.close();
	mainOutput.close();

	splitCount *= 2;
	while (true) {
		mainInput.open(outputFile);
		output1.open("temp1.txt");
		output2.open("temp2.txt");

		binarySplit(mainInput, output1, output2, splitCount);


		mainInput.close();
		output1.close();
		output2.close();

		input1.open("temp1.txt");
		input2.open("temp2.txt");
		mainOutput.open(outputFile);

		if (splitCount > total) {
			binaryMerge(input1, input2, mainOutput, splitCount);
			input1.close();
			input2.close();
			mainOutput.close();
			break;
		}
		else {
			binaryMerge(input1, input2, mainOutput, splitCount);
		}


		input1.close();
		input2.close();
		mainOutput.close();


		splitCount *= 2;
	}
	remove("temp1.txt");
	remove("temp2.txt");
	stop = clock();

	cout << "Thank you for using the binary merge sorter!\nThe data has been sorted to " << outputFile;
}

bool binaryMerge(ifstream& input1, ifstream& input2, ofstream& output, int splitCount) {
	int buffer1, buffer2, splitDepth1, splitDepth2, count;
	bool file1, file2, nextInput1, nextInput2;
	file1 = file2 = true;
	count = 0;
	nextInput1 = nextInput2 = false;

	//Take the initial input to make sure the files can be opened.
	if (input1 >> buffer1) {
		count++;
	}
	else {
		file1 = false;
	}

	if (input2 >> buffer2) {
		count++;
	}
	else {
		file2 = false; 
	}

	splitDepth1 = splitDepth2 = 1;

	while (file1 && file2) {

		if (buffer1 < buffer2 && splitDepth1 <= splitCount) {
			output << buffer1 << ' ';
			splitDepth1++;
			nextInput1 = true;
		}
		else if (buffer2 < buffer1 && splitDepth2 <= splitCount) {
			output << buffer2 << ' ';
			splitDepth2++;
			nextInput2 = true;
		}
		
		//If we have taken enough ints from buffer1, but not buffer2, drain buffer2 until we have taken enough
		if (splitDepth1 > splitCount && splitDepth2 <= splitCount) {
			for (int i = splitDepth2; i <= splitCount; i++) {
				output << buffer2 << ' ';
				if (input2 >> buffer2) {
					splitDepth2++;
				}
				else {
					file2 = false;
					break;
				}
			}
		}

		if (splitDepth2 > splitCount && splitDepth1 <= splitCount) {
			for (int i = splitDepth1; i <= splitCount; i++) {
				output << buffer1 << ' ';
				if (input1 >> buffer1) {
					splitDepth1++;
				}
				else {
					file1 = false;
					break;
				}
			}
		}


		//If we have taken enough numbers from both buffers, reset the depth counter so we can take more numbers
		if (splitDepth1 > splitCount && splitDepth2 > splitCount) { splitDepth1 = splitDepth2 = 1; }
		
		
		if (nextInput1) {

			if (input1 >> buffer1) {
				count++;
				nextInput1 = false;
			}
			else {
				file1 = false;
			}
		}

		if (nextInput2) {
			if (input2 >> buffer2) {
				count++;
				nextInput2 = false;
			}
			else {
				file2 = false;
			}
		}

	}


	if (file1) {
		output << buffer1 << ' ';
		while (input1 >> buffer1) {
			output << buffer1 << ' ';
		}
	}

	if (file2) {
		output << buffer2 << ' ';
		while (input2 >> buffer2) {
			output << buffer2 << ' ';
		}
	}
	total = count;
	return true;
}

bool binarySplit(ifstream& input, ofstream& output1, ofstream& output2, int splitCount) {
	
	int buffer, splitDepth1, splitDepth2, count1, count2;
	count1 = count2 = 0;

	splitDepth1 = splitDepth2 = 1;

	while (input >> buffer) {

		if (splitDepth1 <= splitCount) {
			output1 << buffer << ' ';
			splitDepth1++;
			count1++;
		}
		else if(splitDepth2 <= splitCount){
			output2 << buffer << ' ';
			splitDepth2++;
			count2++;
		}
		else {
			splitDepth1 = splitDepth2 = 1;
			output1 << buffer << ' ';
			splitDepth1++;
			count1++;
		}


	}
	return true;
}