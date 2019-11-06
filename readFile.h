/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 4 - Registrar's Office*/
#pragma once
#include <iostream>
#include "GenQueue.h"
using namespace std;

class ReadFile
{
public:
	ReadFile(string fileName);
	void readFile(string inputFileName);
	//make a int queue to store the file information
	GenQueue<int>* fileQueue;
};