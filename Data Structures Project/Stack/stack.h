#include <iostream>
#include <locale.h>
#pragma once
#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <cstring>

/*
Resul Emre Aygan - 1030520505
Metehan Altuntaþ - 1030520497
Batuhan Ýpek - 1030516168
*/

struct veri
{
	std::string evrak;
	std::string kelime;
	std::string frekans;
	
	veri *onceki;
};

class Stack
{		
	public:
		
		Stack();
		
		veri *top;
		veri *yeniEleman;
		
		void push(std::string _evrak, std::string _kelime, std::string _frekans);
		
		void pop();
		
		void listele();
};
