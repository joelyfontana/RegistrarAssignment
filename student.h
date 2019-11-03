/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 4 - Registrar's Office*/

#include <iostream>
using namespace std;

class StudentInfo
{
public:
	StudentInfo();
	~StudentInfo();

	bool atWindow;
	signed int waitTimeLeft; //so it cant go negative
	int waitTime;

	//functions
	void timeInterval();
};