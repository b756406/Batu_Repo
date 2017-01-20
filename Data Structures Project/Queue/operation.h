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
#include "stack.h"


class operation{
	public:

		char kelime_1[40];
		char kelime_2[40];
		int m;
		int a;
		int paper;
		int paper1;
		int frek;
		int frek1;	
		bool sorting(std::string kelime_1, std::string kelime_2, int m, int a, int paper, int paper1, int frek, int frek1);
		int StringLength(std::string StrName, int length);
		
	
};
