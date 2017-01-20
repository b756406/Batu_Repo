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

class operations
{
	public:
		
		std::string StrName, kelime_1, kelime_2;
		int m, a, paper, paper1, frek, frek1, length;
		
		int StringLength(std::string StrName, int length);
		bool sorting(std::string kelime_1, std::string kelime_2, int m, int a, int paper, int paper1, int frek, int frek1);
};


