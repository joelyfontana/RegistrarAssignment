/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 4 - Registrar's Office*/

#include <iostream>
#include "GenQueue.h"
#include "readFile.h"
using namespace std;

int main(int argc, char** argv)
{
	string fileName = argv[1];
	//error check to make sure that the use entered the file as a command line argument 
	if (argc != 2)
	{
		cout << "Please enter the input file name as a command line argument." << endl;
		return 0;
	}

	//open, read, and print the file
	ReadFile fileReader(fileName);


	cout << "Welcome to the Student Registar!" << endl;

	cout << "The mean student wait time: " << endl;
	cout << "The median student wait time: " << endl;
	cout << "The longest student wait time: " << endl;
	cout << "The number of students waiting over 10 minutes: " << endl;
	cout << "The mean window idle time: " << endl;
	cout << "The longest window idle time: " << endl;
	cout << "The number of windows idle over 5 minutes: " << endl;

}