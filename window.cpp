/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 4 - Registrar's Office*/

#include <iostream>
#include "window.h"
#include "registrar.h"
using namespace std;

Window::Window()
{
	windowTime = 0;
	windowIdle = 0;
	isAtWindow = false;
}

Window::~Window()
{

}

//a student is at the window
void Window::getStudent(Student* nextStudent)
{
	isAtWindow = true;
	//windowOccupied = true;
	//assign the student at the window to next student
	student = nextStudent;
	//when the student gets to the window, the time spent at the window starts at 0
	windowTime = 0;
	//cout << "windowTime: " << windowTime << endl;
}

Student* Window::removeStudent()
{
	if (isAtWindow == true)
	{
		if (windowTime == student->windowTime)
		{
			//cout << "student time: " << student->windowTime << endl;
			isAtWindow = false;
			student->atWindow = false;
			Student* tempStudent = student;
			student = nullptr;
			return tempStudent;
		}
	}

	return NULL;
}

void Window::timeInterval()
{
	if (isAtWindow == true)
	{
		//incriment the time the student is at the window
		windowTime++;
		//cout << "Student time at window: " << windowTime << endl;
	}
	//incriment idle time
	else
	{
		windowIdle++;
	}
	
}

Student* Window::peekStudent()
{
	return student;
}