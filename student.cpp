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
StudentInfo::StudentInfo()
{
	
}

//destructor
StudentInfo::~StudentInfo()
{

}

void StudentInfo::timeInterval()
{
	if (atWindow == true)
	{
		waitTimeLeft--;
	}
	else
	{
		waitTime++;
	}
}


