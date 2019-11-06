/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 4 - Registrar's Office*/

#include <iostream>
#include "GenQueue.h"
#include "registrar.h"
#include "window.h"
#include "student.h"
#include <string>

using namespace std;


bool runFunction(Registrar &reg);

int main(int argc, char** argv)
{
	string fileName = argv[1];
	//error check to make sure that the use entered the file as a command line argument 
	if (argc != 2)
	{
		cout << "Please enter the input file name as a command line argument." << endl;
		return 0;
	}

	cout << "Welcome to the Student Registar!" << endl;

	Registrar registrar = Registrar(fileName);
	//cout << "finished reg" << endl;
	
	//bool somethin = runFunction(registrar);
	bool isOkToRun;

	try
	{
		do
		{
			cout << "\twhile loop" << endl;
			registrar.nextMinute();
			cout << "after while loop next minute" << endl;

			isOkToRun = runFunction(registrar);
			cout << "Is Ok To RUn: " << isOkToRun << endl;

		} while (isOkToRun);
	}
	catch (runtime_error e)
	{
		cout << "The mean student wait time: " << endl;
		cout << "The median student wait time: " << endl;
		cout << "The longest student wait time: " << endl;
		cout << "The number of students waiting over 10 minutes: " << endl;
		cout << "The mean window idle time: " << endl;
		cout << "The longest window idle time: " << endl;
		cout << "The number of windows idle over 5 minutes: " << endl;
	}
}

bool runFunction(Registrar& reg)
{
	//bool okToRun = false;

	if (reg.fileReader->fileQueue->getSize() != 0)
	{
		cout << "line1good" << endl;
		return true;
		
	}
	cout << "Student Queue size: " << reg.studentQueue.getSize() << endl;
	if (reg.studentQueue.getSize() != 0)
	{
		cout << "line2good" << endl;
		return true;
		
	}
	for (int i = 0; i < reg.numWindows; ++i)
	{
		if (reg.windowArray[i].windowOccupied == true)
		{
			cout << "line3good" << endl;
			return true;
			
		}
	}

	//cout << "Ok to run: " << to_string(okToRun) << endl;

	cout << "Returning False" << endl;
	//okToRun = false;
	return false;
}