#include "operations.h"
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

struct tree
{
    std::string evrak;
    std::string kelime;
    std::string frekans;
    
    tree *Left, *Right;
};

struct tree2
{
	std::string evrak2;
	std::string kelime2;
	std::string frekans2;
	
	tree2 *Left2, *Right2;
};

struct tree3
{
	std::string evrak3;
	std::string kelime3;
	std::string frekans3;
	
	tree3 *Left3, *Right3;
};

	
class binaryTree
{
	public:

        binaryTree();
        
		        	
		tree *root;
		tree2 *root2;
		tree3 *root3;
        
        void firstInsert1(std::string evrak, std::string kelime, std::string frekans);
        tree *firstInsert2(tree *, tree *);
        void firstIntrav(tree *);
        
        void secondInsert1(std::string evrak2, std::string kelime2, std::string frekans2);
        tree2 *secondInsert2(tree2 *, tree2 *);
        void secondIntrav(tree2 *);

        
        void thirdInsert1(std::string evrak3, std::string kelime3, std::string frekans3);
        tree3* thirdInsert2(tree3 *,tree3 *);
        void thirdIntrav(tree3 *);
};
