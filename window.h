/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 4 - Registrar's Office*/

#pragma once
#include <iostream>
#include "student.h"
using namespace std;

class Window
{
private:
	//make a private student pointer 
	Student* student;

public: 
	Window();
	~Window();
	void getStudent(Student* nextStudent);
	void timeInterval();
	//variables
	bool isAtWindow;
	int windowTime;
	int windowIdle;
	int totalWindow;
	//bool windowOccupied;

};