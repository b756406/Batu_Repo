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
#include "binaryTree.h"

using namespace std;

int main()
{
	setlocale(LC_ALL,"Turkish");
	
	
	binaryTree bt;
	
	string line,w1,w2,w3;
	
	int b = 0;
	
	ofstream myfile("sonuc.binarytree.0505.0497.6168.csv");
    
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
			
			bt.firstInsert1(w1, w2, w3);
			b++;
		}
		
		myFile.close();
	}

	while (bt.root != NULL)
	{
		bt.secondInsert1(bt.root -> evrak, bt.root -> kelime, bt.root -> frekans);
		bt.root = bt.root -> Right;
	}
	bt.secondIntrav(bt.root2);	
		
	while (bt.root3 != NULL)
	{
		myfile << bt.root3 -> evrak3 << "," << bt.root3 -> kelime3 << "," << bt.root3 -> frekans3 << endl;
		bt.root3 = bt.root3 -> Right3;
	}
	
	myfile.close();
	
    return 0;
}
