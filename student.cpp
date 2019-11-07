/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 4 - Registrar's Office*/

#include <iostream>
#include "student.h"
using namespace std;

//use an array to take in the students - cpp or header file?? not sure which

//constructor
Student::Student(int studentWindowTime)
{
	//take in the amount of time the student needs at the window
	windowTime = studentWindowTime;
	timeInLine = 0;
}

//destructor
Student::~Student()
{

}

void Student::atWindowCheck()
{
	cout << "entering at window check" << endl;
	if (atWindow == false)
	{
		timeInLine++;
		cout << "student time in line: " << timeInLine << endl;
	}
	//cout << "students total time in line: " << imeInLine << endl;
}



