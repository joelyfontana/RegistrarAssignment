/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 4 - Registrar's Office*/

//to solve the redefining errors (when the class is being called multiple times)
#pragma once
#include <iostream>
#include "doubleLinkList.h"
using namespace std;

//make the GenQueue class 
template <class T>
class GenQueue
{
public: 
	GenQueue();
	~GenQueue();

	//basic functions

	void insert(T d);
	T remove();
	T peek();
	bool isEmpty();
	int getSize();	
	DoublyLinkedList<T>* listQueue;
};

//GenQueue implementation
//constructor
template <class T>
GenQueue<T>::GenQueue()
{
	listQueue = new DoublyLinkedList<T>();
}

//destructor
template <class T>
GenQueue<T>::~GenQueue()
{
	delete listQueue;
}

template <class T>
void GenQueue<T>::insert(T d)
{
	//insert the element into the back of the queue
	listQueue->insertBack(d);
}

template <class T>
T GenQueue<T>::remove()
{
	//remove the front element in the queue
	return listQueue->removeFront();
}

template <class T>
T GenQueue<T>::peek()
{
	//return the first item in the list
	return listQueue->front->data;
}

template <class T>
bool GenQueue<T>::isEmpty()
{
	if (listQueue->getSize() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
int GenQueue<T>::getSize()
{
	return listQueue->getSize();
}

