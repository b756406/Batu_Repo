#include "binaryTree.h"
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

using namespace std;

operations o;

binaryTree::binaryTree()
{
    root = NULL;
    root2 = NULL;
    root3 = NULL;
}

tree2* binaryTree::secondInsert2(tree2 *tmp, tree2 *newnod)
{
	int m, a, length, paper, paper1, frek, frek1;
	int value3, value4, value5, value6;
	
	std::string temp1,temp2,temp3,temp4,temp5,temp6;
	
	char kelime_1[40];
	char kelime_2[40];
	
	bool back;
	
	
	if ( tmp == NULL)
	{
		tmp = newnod;
	}
	
	else
	{
		temp3 = tmp -> evrak2;
		temp1 = tmp -> kelime2;
		temp5 = tmp -> frekans2;
		
		temp4 = newnod -> evrak2;
		temp2 = newnod -> kelime2;
		temp6 = newnod -> frekans2;
		
		m = o.StringLength(temp1, length);
		a = o.StringLength(temp2, length);
	
		strncpy(kelime_1, temp1.c_str(), sizeof(kelime_1));
		strncpy(kelime_2, temp2.c_str(), sizeof(kelime_2));
		
		value3 = atoi(temp3.c_str());
		value4 = atoi(temp4.c_str());
		value5 = atoi(temp5.c_str());
		value6 = atoi(temp6.c_str());
		
		back = o.sorting(kelime_1, kelime_2, m, a, value3, value4, value5, value6);
		
		if ( back == true )
		{
        	if ( tmp -> Right2 == NULL )
        	{
        		 tmp -> Right2 = newnod;
			}
			else
				secondInsert2(tmp -> Right2, newnod);
		}
		
		else if ( back == false )
		{
			if ( tmp -> Left2 == NULL )
			{
				tmp -> Left2 = newnod;
			}
			else
				secondInsert2(tmp -> Left2, newnod);
		}
	}
	
	return tmp;
}

void binaryTree::secondInsert1(string evrak2, string kelime2, string frekans2)
{
	tree2 *tmp = root2, *newnod;
	newnod = new tree2;
	
	newnod -> Right2 = NULL;
	newnod -> Left2 = NULL;
	
    newnod -> evrak2 = evrak2;
    newnod -> kelime2 = kelime2;
    newnod -> frekans2 = frekans2;
    
	root2 = secondInsert2(tmp, newnod);
}

void binaryTree::secondIntrav(tree2 *t2)
{
	root2 = t2;
	if ( root2 == NULL)
	{
		//bos
	}
	
	else
	{
		if ( t2 != NULL)
		{
			secondIntrav(t2 -> Left2);
		//	cout << t2 -> evrak2 << " " << t2 -> kelime2 << " " << t2 -> frekans2 << " " << endl;
			std::string a = t2 -> evrak2, b = t2 -> kelime2, c = t2 -> frekans2;
			thirdInsert1(a, b, c);
	       	secondIntrav(t2 -> Right2);
		}
	}
}

tree* binaryTree::firstInsert2(tree *temp,tree *newnode)
{
    if(temp == NULL)
	{
        temp = newnode;
    }
    
    else
	{
        firstInsert2(temp -> Right, newnode);
        
        if( temp -> Right == NULL )
        {
        	 temp -> Right = newnode;
		}
    }
    
    return temp;
}

void binaryTree::firstInsert1(string evrak, string kelime, string frekans)
{
    tree *temp = root,*newnode;
    
	newnode = new tree;
    
    newnode -> Right = NULL;
    newnode -> evrak = evrak;
    newnode -> kelime = kelime;
    newnode -> frekans = frekans;
    
	root = firstInsert2(temp, newnode);
}

void binaryTree::firstIntrav(tree *t)
{
	root=t;
    if ( root == NULL )
	{
        cout << "Nothing to display"<<endl;
    }
	
	else
    {
		if ( t != NULL )
		{
			cout << t -> evrak << " " << t -> kelime << " " << t -> frekans << " " << endl;
        	firstIntrav(t -> Right);
    	}
	}
}

void binaryTree::thirdInsert1(string evrak3, string kelime3, string frekans3)
{
    tree3 *tmp3 = root3,*newnod3;
    
	newnod3 = new tree3;
    
    newnod3 -> Right3 = NULL;
    newnod3 -> evrak3 = evrak3;
    newnod3 -> kelime3 = kelime3;
    newnod3 -> frekans3 = frekans3;
    
	root3 = thirdInsert2(tmp3, newnod3);
}

tree3* binaryTree::thirdInsert2(tree3 *tmp3,tree3 *newnod3)
{
    if(tmp3 == NULL)
	{
        tmp3 = newnod3;
    }
    
    else
	{
        thirdInsert2(tmp3 -> Right3, newnod3);
        
        if( tmp3 -> Right3 == NULL )
        {
        	 tmp3 -> Right3 = newnod3;
		}
    }
    
    return tmp3;
}

void binaryTree::thirdIntrav(tree3 *t3)
{
	root3=t3;
    if ( root3 == NULL )
	{
        cout << "Nothing to display"<<endl;
    }
	
	else
    {
		if ( t3 != NULL )
		{
        	cout << t3 -> evrak3 << "," << t3 -> kelime3 << "," << t3 -> frekans3 << "," << endl;
        	thirdIntrav(t3 -> Right3);
    	}
	}
}
