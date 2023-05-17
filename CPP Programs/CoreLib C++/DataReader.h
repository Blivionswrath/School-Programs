#ifndef DATAREADER_H
#define DATAREADER_H
#include <string>

class DataReader {
public:
	std::string fileName;
	const std::string DEFAULTSHADER = "Default.txt";
	DataReader();

	/// <summary>
	/// Reads the given filepath and returns the code in a string
	/// </summary>
	/// <param name="filePath">Where the file lies</param>
	/// <returns>Returns code in a string</returns>
	std::string readShader(std::string filePath);

	std::string loadModel(std::string filePath);

};


#endif
