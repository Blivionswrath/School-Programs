#include "DataReader.h"
#include <fstream>
#include <iostream>
#include <sstream>


int main() {
	DataReader reader;
	std::string s = reader.readShader("");
	std::cout << s;
	std::cin;
}

DataReader::DataReader() {}


std::string DataReader::readShader(std::string filePath) {
	std::ifstream inputFile;
	inputFile.open(filePath);


	if (!inputFile.is_open()) {
		std::cout << "The shader file: " + filePath + "\nCould not be opened.";
		inputFile.open(DEFAULTSHADER);
	}
	std::stringstream sstream;
	std::string buffer;
	while (inputFile >> buffer) {
		sstream << buffer;
	}
	return sstream.str();
}