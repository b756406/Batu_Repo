#include <iostream>
#include <locale.h>
#pragma once
#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string.h>
#include <cstring>


struct node
{
	std::string evrak;
	std::string kelime;
	std::string frekans;
	
	struct node *next;
};

class Queue
{		
	public:
		
		Queue();
		
		node *rear;
		node *front;
		
		void enqueue(std::string _evrak, std::string _kelime, std::string _frekans);
		
		void dequeue();
		
		void display();
		
		bool isEmpty();
};
