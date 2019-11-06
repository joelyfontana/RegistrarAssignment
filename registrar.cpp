/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 4 - Registrar's Office*/

#include <iostream>
#include "registrar.h"
#include "readFile.h"
#include "student.h"
#include <string>
using namespace std;

Registrar::Registrar(string fileName)
{
	fileReader = new ReadFile(fileName);
	//tempStudent = new Student(atWindow);
	//remove the first element in the file
	numWindows = fileReader->fileQueue->remove();
	time = 0; 
	cout << "Number of Windows Open: " << numWindows << endl;
	//cout << "time: " << time << endl;
	makeWindows();
}

Registrar::~Registrar()
{

}

void Registrar::makeWindows()
{
	windowArray = new Window[numWindows];
}

void Registrar::makeStudents()
{
	//remove the time from the queue
	//SEG FAULT IS HERE
	cout << "FileQueue Length: " << fileReader->fileQueue->getSize() << endl; //size of my massive dick
	if (fileReader->fileQueue->getSize() == 0)
	{
		throw runtime_error("end of file");
	}
	cout << "Current Time: " << time << "\tFileQueue Peek: " << fileReader->fileQueue->peek() << endl;
	if (time == fileReader->fileQueue->peek())
	{
		int tempTime = fileReader->fileQueue->remove();
		cout << "time: " << tempTime << endl;
		int numStudents = fileReader->fileQueue->remove();
		for (int i = 0; i < numStudents; ++i)
		{
			int rmStudent = fileReader->fileQueue->remove();
			Student* student = new Student(rmStudent);
			Student* usedStudent = new Student(rmStudent);
			studentQueue.insert(student);
			//make a used student queue for metrics
			usedStudentQueue.insert(usedStudent);
			cout << "student queue: " << rmStudent << endl;
		}
		int studentSize = studentQueue.getSize();
		cout << "studentQueue Size: " << studentSize << endl;
	}
}

//make a function to keep track of/ increment the time
void Registrar::nextMinute()
{
	//cout << "Num Windows: " << numWindows << endl;
	//incriment the time for each individual window
	for (int i = 0; i < numWindows; ++i)
	{
		cout << "Window " << i << " is occupied: " << to_string(windowArray[i].isAtWindow) << endl;
		
		if (windowArray[i].isAtWindow == false)
		{	
			if (studentQueue.getSize() != 0)
			{
				windowArray[i].timeInterval();
			}
		}
	}
	cout << "Makestudents" << endl;
	makeStudents();

	for (int i = 0; i < numWindows; ++i)
	{
		if (windowArray[i].isAtWindow == false)
		{
			if (studentQueue.getSize() != 0)
			{
				windowArray[i].getStudent(studentQueue.remove());
			}
		}
	}
	time++;
}

//get total time 
//void Registrar::getTime()
//{
//	tempStudent->atWindowCheck();
//}
//calculate the statistics 
void Registrar::calcStats()
{
	tempStudent->atWindowCheck();
	tempStudent->totalTimeInLine;
	
	//calc the mean - total student wait time divided by the length of the used student queue
	mean = tempStudent->totalTimeInLine/ usedStudentQueue.getSize();
	//median - reorder the wait times from lowest to highest and then find the middle value (or the two middle values and them then divide by two)

	//get the wait time at the bottom for the longest wait time

	//get the values in the list greater than 10 and return the students that belong to that object

	//calc the mean window idle time - total window idle time/ number of windows

	//find the longest window idle time

	//got through the queue of idle windows and count the ones idle for longer than 5 minutes and return that



}