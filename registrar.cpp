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
#include <algorithm>
using namespace std;

Registrar::Registrar(string fileName)
{
	fileReader = new ReadFile(fileName);
	//tempStudent = new Student(atWindow);
	//remove the first element in the file
	numWindows = fileReader->fileQueue->remove();
	time = 0; 
	mean = 0;
	//cout << "Number of Windows Open: " << numWindows << endl;
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
	//cout << "FileQueue Length: " << fileReader->fileQueue->getSize() << endl;
	if (fileReader->fileQueue->getSize() == 0)
	{
		return;
		//throw runtime_error("end of file");
	}
	//cout << "Current Time: " << time << "\tFileQueue Peek: " << fileReader->fileQueue->peek() << endl;
	if (time == fileReader->fileQueue->peek())
	{
		int tempTime = fileReader->fileQueue->remove();
		//cout << "time: " << tempTime << endl;
		int numStudents = fileReader->fileQueue->remove();
		for (int i = 0; i < numStudents; ++i)
		{
			int rmStudent = fileReader->fileQueue->remove();
			Student* student = new Student(rmStudent);
			//Student* usedStudent = new Student(rmStudent);
			studentQueue.insert(student);
			//cout << "student queue: " << rmStudent << endl;
		}
		int studentSize = studentQueue.getSize();
		//cout << "studentQueue Size: " << studentSize << endl;
	}
}

//make a function to keep track of/ increment the time
void Registrar::nextMinute()
{
	//incriment the time for each individual window
	for (int i = 0; i < numWindows; ++i)
	{
		//cout << "Window " << i << " is occupied: " << to_string(windowArray[i].isAtWindow) << endl;
		windowArray[i].timeInterval();
		//check to make sure that there is someone at the window and if it is time for them to leave
		if (windowArray[i].isAtWindow == true)
		{
			if (windowArray[i].peekStudent()->windowTime == windowArray[i].windowTime)
			{
				//cout << "peek Student: " << windowArray[i].peekStudent()->windowTime << endl;
				//cout << "window time of window array: " << windowArray[i].windowTime << endl;
				Student* usedStudent = windowArray[i].removeStudent();
				//cout << "removed student: " << usedStudent << endl;

				//make a used student queue for metrics
				if (usedStudent == NULL)
					continue;
				usedStudentQueue.insert(usedStudent);
			}
		}
	}

	for (int i = 0; i < studentQueue.getSize(); ++i)
	{
		Student* newStudent = studentQueue.remove();
		newStudent->atWindowCheck();
		studentQueue.insert(newStudent);
	}

	//cout << "Makestudents" << endl;
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
	//cout << "Length of used students: " << usedStudentQueue.getSize() << endl;
	time++;
}

//calculate the statistics 
void Registrar::calcStats()
{
	//cout << "Entered calc stats" << endl;
	//calc the mean - total student wait time divided by the length of the used student queue
	int totalTime = 0;
	//cout << "Number of usedStudents: " << usedStudentQueue.getSize() << endl;
	for (int i = 0; i < usedStudentQueue.getSize(); ++i)
	{
		//cout << "entered for loop" << endl;
		Student* usedStudent = usedStudentQueue.remove();

		//cout << "Student Time needed at window: " << usedStudent->windowTime << endl;
		//cout << "after remove" << endl;
		totalTime += usedStudent->timeInLine;
		//cout << "total time: "<<totalTime << endl;
		usedStudentQueue.insert(usedStudent);
		//cout << "after insert" << endl;
	}
	mean = totalTime / usedStudentQueue.getSize();
	//cout << "total time: " << totalTime << " - usedStudent queue size: " << usedStudentQueue.getSize() << endl;
	
	//median - reorder the wait times from lowest to highest and then find the middle value (or the two middle values and them then divide by two)
	int* waitTimeArray = new int[usedStudentQueue.getSize()];
	for (int i = 0; i < usedStudentQueue.getSize(); ++i)
	{
		Student* usedStudent;
		usedStudent = usedStudentQueue.remove();
		waitTimeArray[i] = usedStudent->timeInLine;
		usedStudentQueue.insert(usedStudent);
	}
	//sort the array to reorder the values
	sort(waitTimeArray, waitTimeArray + usedStudentQueue.getSize());

	int middle = usedStudentQueue.getSize() / 2;
	median = waitTimeArray[middle];

	//get the wait time at the bottom for the longest wait time
	int last = usedStudentQueue.getSize()-1;
	longestStudentWait = waitTimeArray[last];

	//get the values in the list greater than 10 and return the students that belong to that object
	greaterTen =0;
	for (int i = 0; i < usedStudentQueue.getSize(); ++i)
	{
		if (waitTimeArray[i] > 10)
		{
			greaterTen++;
		}
	}

	//calc the mean window idle time - total window idle time/ number of windows
	int totalIdle;
	for (int i = 0; i < numWindows; ++i)
	{
		totalIdle = windowArray[i].windowIdle;
	}
	meanIdle = totalIdle / numWindows;

	longIdle = 0;
	//find the longest window idle time
	for (int i = 0; i < numWindows; ++i)
	{
		if (windowArray[i].windowIdle > longIdle)
		{
			longIdle = windowArray[i].windowIdle;
		}
	}


	//got through the queue of idle windows and count the ones idle for longer than 5 minutes and return that
	for (int i = 0; i < numWindows; ++i)
	{
		if (windowArray[i].windowIdle > 5)
		{
			windCount++;
		}
		
	}


}