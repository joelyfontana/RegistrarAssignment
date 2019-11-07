/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 4 - Registrar's Office*/

#pragma once
#include <iostream>
#include "window.h"
#include "GenQueue.h"
#include "student.h"
#include "readFile.h"
using namespace std;

class Registrar
{
public:
	Registrar(string fileName);
	~Registrar();

	//variables 
	int numWindows;
	ReadFile* fileReader;

	int time;
	int mean;

	//make a queue of students (make it a pointer)
	GenQueue<Student*> studentQueue;
	GenQueue<Student*> usedStudentQueue;
	Window* windowArray;

	//functions
	//void getTime();
	void makeWindows();
	void makeStudents();
	void nextMinute();
	void calcStats();
};