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
	if (time == fileReader->fileQueue->peek())
	{
		int tempTime = fileReader->fileQueue->remove();
		cout << "time: " << tempTime << endl;
		int numStudents = fileReader->fileQueue->remove();
		for (int i = 0; i < numStudents; ++i)
		{
			int rmStudent = fileReader->fileQueue->remove();
			Student* student = new Student(rmStudent);
			studentQueue.insert(student);
			cout << "student queue: " << rmStudent << endl;
			//PUT STUDENTS IN A FINISHED QUEUE FOR METRICS AFTER!!!!
		}
		int studentSize = studentQueue.getSize();
		cout << "studentQueue Size: " << studentSize << endl;
	}
}

//make a function to keep track of/ increment the time
void Registrar::nextMinute()
{
	cout << "Num Windows: " << numWindows << endl;
	//incriment the time for each individual window
	for (int i = 0; i < numWindows; ++i)
	{
		cout << "Window num: " << i << " is occupied: " << to_string(windowArray[i].windowOccupied) << endl;
		if (windowArray[i].windowOccupied == false)
		{
			
			cout << "Window: " << i << endl;
			cout << "\tprint1" << endl;
			
			if (studentQueue.getSize() != 0)
			{
				cout << "\tprint2" << endl;
				windowArray[i].timeInterval();
				cout << "\tprint3" << endl;
				windowArray[i].getStudent(studentQueue.remove());
				
			}
		}
	}

	
	cout << "Makestudents" << endl;
	makeStudents();
	cout << "after make students" << endl;
	
	time++;
}
