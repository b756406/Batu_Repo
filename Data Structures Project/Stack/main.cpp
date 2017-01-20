#include <iostream>
#include <fstream>
#include <locale.h>
#include <sstream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include "stack.h"
#include "operations.h"

/*
Resul Emre Aygan - 1030520505
Metehan Altuntaþ - 1030520497
Batuhan Ýpek - 1030516168
*/

using namespace std;

int main(int argc, char** argv) 
{
	setlocale(LC_ALL, "Turkish");
	
	string line, w1, w2, w3;
	int b = 0;
	
	Stack v1, v2, v3;
	operations o;
	
	ofstream myfile("sonuc.stack.0505.0497.6168.csv");
	ifstream myFile("vya2016veriler.csv");
	
	if ( myFile.is_open() == false )
	{
		cout << "Can't Open The File" << endl;
		exit(EXIT_FAILURE);
	}
	
	else
	{
		while ( getline(myFile, line) )
		{
			string word;
			
			stringstream stream(line);
			
			int sayac = 0;
			
			while ( getline(stream, word, ',') )
			{
				if ( sayac == 0 )
				{
					w1 = word;
					sayac++;
				}
				else if ( sayac == 1 )
				{
					w2 = word;
					sayac++;
				}
				else if ( sayac == 2 )
				{
					w3 = word;
					sayac = 0;
				}
			}
			
			v1.push(w1, w2, w3);

			b++;
		}
		
		myFile.close();
	}
	
	v3 = o.algorithm(v1, v2);
	
	//v3.listele();
	
	while ( v3.top != NULL )
	{
		myfile << v3.top -> evrak << "," << v3.top -> kelime << "," << v3.top -> frekans << endl;
		v3.pop();
	}
	
	myfile.close();
	
	return 0;
}
