#include <iostream>
#include <locale.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include "stack.h"

/*
Resul Emre Aygan - 1030520505
Metehan Altuntaþ - 1030520497
Batuhan Ýpek - 1030516168
*/

using namespace std;

Stack::Stack()
{
	top = NULL;	
}

void Stack::push(string _evrak, string _kelime, string _frekans)
{	
	yeniEleman = new veri;

	(*yeniEleman).evrak = _evrak;
	(*yeniEleman).kelime = _kelime;
	(*yeniEleman).frekans = _frekans;
	(*yeniEleman).onceki = top;

	top = yeniEleman;	
}

void Stack::pop()
{
	veri *enusteki = new veri;
	enusteki = top;
	top = (*top).onceki;
	
	delete enusteki;
}

void Stack::listele()
{
	veri *referans = top;

	cout << "YIGINIMIZ :" << endl;

	while (referans != NULL)
	{		
		veri *referans = top;	
		if (referans == NULL)
		{
			break;
		}
		else
		{
			cout << (*referans).evrak << "," << (*referans).kelime << "," << (*referans).frekans << endl;
			top = (*top).onceki;
		}
	}
	
	cout << "--------------------" << endl;
}








