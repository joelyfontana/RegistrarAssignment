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
	//set the window occupied equal to false;
	windowTime = 0;
	isAtWindow = false;
	//windowOccupied = false;
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

void Window::timeInterval()
{
	if (isAtWindow == true)
	{
		//incriment the time the student is at the window
	
		windowTime++;
		cout << "Student time at window: " << windowTime << endl;
		//windowOccupied = true;
	}
	//incriment idle time
	else
	{
		windowIdle++;
	}
	
}