#include <iostream>
#include <fstream>
#include <locale.h>
#include <sstream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <cstring>
#include "operation.h"
#include "queue.h"


using namespace std;

int main(int argc, char** argv) 
{
	setlocale(LC_ALL, "Turkish");
	
	Queue queue;
	Queue queue2;
	operation s;
	
	int i = 0;
		
	ofstream myfile;
    myfile.open ("sonuc.queue.0505.0497.6168.csv");
    
	string w1,w2,w3;
	string line;
	string word;
	
	ifstream myFile("veriler.txt");
		
	if ( myFile.is_open() == false)
	{
		cout << "Can't Open The File" << endl;
		exit(EXIT_FAILURE);	
	}
	 
	else
	{
		while(getline(myFile, line))
		{
			stringstream ss(line);
			
		    int sayac = 0;
		    
			while (getline(ss,word, ','))
			{
				if( sayac == 0 )
				{
					w1 = word;
					sayac++;
				}
				else if( sayac == 1)
				{
					w2 = word;
					sayac++;
				}
				else if( sayac == 2 )
				{
					w3 = word;
					sayac=0;
				}		 
			}	
			
			queue.enqueue(w1, w2, w3); 
			i++;		
     	}
       		myFile.close();
		    //myfile.close();		    
	} 
	
	Queue kyrk;
	
	kyrk = s.algorithm(queue, queue2);
	

	if(kyrk.front != NULL)
	{
		while (kyrk.front != NULL)
		{
		myfile << kyrk.front -> evrak << ",";
		myfile << kyrk.front -> kelime << ",";
		myfile << kyrk.front -> frekans << endl;
		kyrk.dequeue();
		}
	}
	

	myfile.close();
	
	
	return 0;
}
