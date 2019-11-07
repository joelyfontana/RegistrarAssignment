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
	
	//bool somethin = runFunction(registrar);
	bool isOkToRun;

	/*try
	{*/
		do
		{
			registrar.nextMinute();

			isOkToRun = runFunction(registrar);

		} while (isOkToRun);

		registrar.calcStats();
		cout << "The mean student wait time: " << registrar.mean << endl;
		cout << "The median student wait time: " << registrar.median << endl;
		cout << "The longest student wait time: " << registrar.longestStudentWait<<endl;
		cout << "The number of students waiting over 10 minutes: " << registrar.greaterTen << endl;
		cout << "The mean window idle time: " << registrar.meanIdle<< endl;
		cout << "The longest window idle time: " << registrar.longIdle << endl;
		cout << "The number of windows idle over 5 minutes: " << registrar.windCount << endl;
	//}
}

bool runFunction(Registrar& reg)
{
	//bool okToRun = false;

	if (reg.fileReader->fileQueue->getSize() != 0)
	{
		//cout << "line1good" << endl;
		return true;
		
	}
	//cout << "Student Queue size: " << reg.studentQueue.getSize() << endl;
	if (reg.studentQueue.getSize() != 0)
	{
		//cout << "line2good" << endl;
		return true;
		
	}
	for (int i = 0; i < reg.numWindows; ++i)
	{
		if (reg.windowArray[i].isAtWindow == true)
		{
			//cout << "line3good" << endl;
			return true;
			
		}
	}

	//cout << "Ok to run: " << to_string(okToRun) << endl;

	//cout << "Program has ended!" << endl;
	//okToRun = false;
	return false;
}