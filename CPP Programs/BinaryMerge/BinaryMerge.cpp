


#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

bool binaryMerge(ifstream& input1, ifstream& input2, int mergeDepth, ofstream& output, int splitSize);
bool binaryCheck(ifstream& input);
void splitFile(ifstream& input, ofstream& output1, ofstream& output2, int mergeDepth);

int total = 0, splitCount = 0;
bool shouldCount = true;
int main(int argc, char* argv[]) {

	string inputFile, outputFile, buffer;
	ifstream inputStream, iftemp1, iftemp2;
	ofstream oftemp1, oftemp2, output;
	int mergeDepth;
	clock_t start, stop;
	double elapsedTime;
	cout << "Please enter the name of the file you would like to be sorted: ";
	getline(cin, inputFile);
	//Create the name for the output file
	for (int i = 0; i < inputFile.size(); i++) {
		if (inputFile[i] == '.') {
			buffer = inputFile.substr(0, i);
			break;
		}
	}
	outputFile = buffer + "_sorted.txt";
	start = clock();

	//This will be an overloaded function for binary merge.
	//Do the first split and merge 
	oftemp1.open("temp1.txt");
	oftemp2.open("temp2.txt");
	inputStream.open(inputFile);


	int splitCount = 1;
	splitFile(inputStream, oftemp1, oftemp2, splitCount);
	mergeDepth = total / 2;
	inputStream.close();
	oftemp1.close();
	oftemp2.close();

	output.open(outputFile);

	iftemp1.open("temp1.txt");
	iftemp2.open("temp2.txt");

	binaryMerge(iftemp1, iftemp2, mergeDepth, output, splitCount);

	output.close();
	iftemp1.close();
	iftemp2.close();

	while (splitCount < total / 2) {
		splitCount *= 2;
		if (splitCount > total / 2) { mergeDepth = splitCount; }

		
		//Open files to do a new split		
		inputStream.open(outputFile);
		oftemp1.open("temp1.txt");
		oftemp2.open("temp2.txt");
		splitFile(inputStream, oftemp1, oftemp2, splitCount);
		
		inputStream.close();
		oftemp1.close();
		oftemp2.close();
		//Merge files
		output.open(outputFile);
	
		iftemp1.open("temp1.txt");
		iftemp2.open("temp2.txt");
	
		binaryMerge(iftemp1, iftemp2, mergeDepth, output, splitCount);
		
		output.close();
		iftemp1.close();
		iftemp2.close();

	}

	inputStream.open(outputFile);
	bool finished = binaryCheck(inputStream);
	inputStream.close();
	
	if (remove("temp1.txt") != 0) {
		cout << "\nError removing temp file\n";
	}

	if (remove("temp2.txt") != 0) {
		cout << "\nError removing temp file\n";
	}

	stop = clock();
	elapsedTime = (stop - start) / CLOCKS_PER_SEC;

	cout << "Thank you for using the merge sorter\nElapsed Time: " << elapsedTime << " seconds.";
	return 0;
}

void splitFile(ifstream& input, ofstream& output1, ofstream& output2, int splitCount) {
	int inputCount1, inputCount2, buffer1, buffer2;
	inputCount1 = inputCount2 = 0;
	while (!input.eof()) {

		while (inputCount1 < splitCount) {
			if (input >> buffer1) {
			output1 << buffer1 << ' ';
			inputCount1++;
			}
			else {
				break;
			}
			continue;
		}

		while (inputCount2 < splitCount) {
			if (input >> buffer2) {

			output2 << buffer2 << ' ';
			inputCount2++;
			}
			else {
				break;
			}
			continue;
		}
		//Shouldcount is only active on the first split. 
		//The total variable will be used to determine the last merge depth that should be used.
		if (shouldCount) { total = total + inputCount1 + inputCount2; }
		inputCount1 = inputCount2 = 0;
	}
	if (shouldCount) { shouldCount = false; }
	
}

bool binaryCheck(ifstream& input) {
	int buffer1, buffer2;
	input >> buffer1;
	input >> buffer2;
	while (!input.eof()) {
		if (buffer1 > buffer2) {
			return false;
		}
		buffer1 = buffer2;
		input >> buffer2;
	}
	return true;
}

//This function has been mmodified from the demo code for binary merge.

bool binaryMerge(ifstream& input1, ifstream& input2, int mergeDepth, ofstream& output, int splitSize) {
	int depthCount1 = 1;
	int depthCount2 = 1;

	int splitDepth1 = 1;	//These variables track when our next set of numbers should be taken
	int splitDepth2 = 1;


	bool file1 = true;
	bool file2 = true;

	int buffer1, buffer2;

	if (input1 >> buffer1) {
		//Buffer1 was filled
	}
	else {
		return false;
	}
	if (input2 >> buffer2) {
		//Buffer2 was filled
	}
	else {
		return false;
	}

	if (file1 && file2) {

		// both files are good, and we've already loaded up both of the buffers

		while (true) {
			if (splitDepth1 > splitSize && splitDepth2 > splitSize) { splitDepth1 = splitDepth2 = 1; }
			
			
			if (buffer1 < buffer2 && splitDepth1 <= splitSize) {
				depthCount1++;
				splitDepth1++;
				output << buffer1;  
				output << " ";	    
				if (depthCount1 <= mergeDepth && input1 >> buffer1) {
					//If we have finished this set of numbers for the sublist, empty the next set in the other sublist.
					if (splitDepth1 > splitSize) {
						while (splitDepth2 <= splitSize) {
							splitDepth2++;
							output << buffer2 << ' ';
							input2 >> buffer2;
						}
					}
				}
				else {
					file1 = false;
					break;  // either f1 is at EOF or we have read the last item for that merge depth
				}
			}
			else {
				depthCount2++;		// bump the depth counter for this file
				splitDepth2++;
				output << buffer2;  // write that element to the output file
				output << " ";	    // and a space to separate the numbers

				if (depthCount2 <= mergeDepth && input2 >> buffer2) {
					if (splitDepth2 > splitSize) {
						while (splitDepth1 <= splitSize) {
							

							splitDepth1++;
							output << buffer1 << ' ';
							input1 >> buffer1;
							
						}
					}
				}
				else {
					
					file2 = false;
					break;  // either f2 is at EOF or we have read the last item for that merge depth
				}
			}
		}

	}
	if (file2) {  // file1 is dry, read the rest of file2 up to either merge depth or end of file, whichever comes first
		output << buffer2 << " ";           // take care of the item read previously
		depthCount2++;                       // bump the counter
		while (depthCount2 <= mergeDepth && input2 >> buffer2) {
			// read and write until either EOF or depth reached
			output << buffer2 << " ";
			depthCount2++;
		}
	}
	else {
		output << buffer1 << " ";
		depthCount1++;
		while (depthCount1 <= mergeDepth && input2 >> buffer1) {
			output << buffer1 << " ";
			depthCount1++;
		}
	}

	// merge complete!
	return true;
}
