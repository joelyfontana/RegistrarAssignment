/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 4 - Registrar's Office*/

#pragma once
#include <iostream>
using namespace std;

class Student
{
public:
	Student(int studentWindowTime);
	~Student();
	int atWindowCheck();

	bool atWindow;
	int timeInLine;
	int totalTimeInLine;
	int windowTime;
};