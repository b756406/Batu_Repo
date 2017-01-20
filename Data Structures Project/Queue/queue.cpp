#include <iostream>
#include <locale.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string.h>
#include <cstring>
#include "queue.h"

using namespace std;

Queue::Queue()
{
	rear = NULL;
	front = NULL;
}

void Queue::enqueue(string _evrak, string _kelime, string _frekans)
{	
	node *temp = new node;
	
	temp -> evrak = _evrak;
	temp -> kelime = _kelime;
	temp -> frekans = _frekans;
	
	temp -> next = NULL;
	
	if ( front == NULL)
	{
		front = temp;
	}
	
	else
	{
		rear -> next = temp;
	}
	
	rear = temp;
}

void Queue::dequeue()
{
	node *temp = new node;
	
	if ( front == NULL)
	{
		cout << endl << "Queue is Empty" << endl;
	}
	
	else
	{
		temp = front;
		
		front = front -> next;

		delete temp;
	}
}

bool Queue::isEmpty()
{
	if( front == NULL ) 
	{
		//cout << "Queue is Empty" << endl;
		return true;
	}
	
	else 
	{
		//cout << "Queue is not Empty" << endl;
		return false;
	}
		
}

void Queue::display()
{
	node *p = new node;
	
	p = front;
	
	if ( front == NULL)
	{
		cout << "Nothing to Display" << endl;
	}
	
	else
	{
		while ( p != NULL )
		{
			cout << p -> evrak << " " << p -> kelime << " " << p -> frekans << endl;
			
			p = p ->next;
		}
	}
}
