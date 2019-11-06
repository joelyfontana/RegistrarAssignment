/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 4 - Registrar's Office*/

#include <iostream>
#include <fstream>
#include <string>
#include "readFile.h"
#include "GenQueue.h"
using namespace std;

ReadFile::ReadFile(string fileName)
{
	//cout << "entered the readFile con" << endl;
	//instantiate the queue
	fileQueue = new GenQueue<int>();
	//cout << "print" << endl;
	readFile(fileName);
	//cout << "fileRead" << endl;
}

void ReadFile::readFile(string inputFileName)
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
	//cout << "after line" << endl;
	while (getline(inputFile, line))
	{
		//cout << "while loop" << endl;
		int fileLine = stoi(line);
		cout << "fileLine: " << fileLine << endl;
		fileQueue->insert(fileLine);
	}
	int temp = fileQueue->peek();
	int qSize = fileQueue->getSize();
	//cout << "size: " << qSize << endl;
	//cout << "fileQueue: " << temp << endl;
	//close the file
	inputFile.close();
}
