/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 4 - Registrar's Office*/

#include <iostream>
#include <fstream>
#include <string>
#include "readFile.h"
using namespace std;

ReadFile::ReadFile(string fileName)
{
	readFile(fileName);
}

int ReadFile::readFile(string inputFileName)
{
	ifstream inputFile;
	inputFile.open(inputFileName);
	cout << "Filename: " << inputFileName << endl;

	if (!inputFile)
	{
		throw runtime_error("The file you entered could not be found");
	}

	//print out the file and get the length
	string line;
	int length=0;
	while (getline(inputFile, line))
	{
		//cout << line << endl;
		length++;
	}
	cout << "length: " << length << endl;
	inputFile.clear();
	inputFile.seekg(0);

	//make a new int array pointer to get the length
	int* fileArray = new int [length];

	int lineCount=0;
	while (getline(inputFile, line))
	{
		fileArray[lineCount] = stoi(line);
		lineCount++;
	}

	for (int i = 0; i < length; ++i)
	{
		cout << "fileArray: " << fileArray[i] << endl;
	}

	cout << "Number of Windows: " << fileArray[0] << endl;
	return fileArray[0];
}
