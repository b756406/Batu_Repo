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
#include "stack.h"

using namespace std;

int operation::StringLength(string StrName, int length)
{	
	length = strlen(StrName.c_str());
      
	return length;
}

bool operation::sorting(string kelime_1, string kelime_2, int m, int a, int paper, int paper1, int frek, int frek1)
{
	char alfabe[30] = {' ' , 'a', 'b', 'c', 'ç', 'd', 'e', 'f', 'g', 'ð', 'h', 'ý', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'ö', 'p', 'r', 's', 'þ', 't', 'u', 'ü', 'v', 'y', 'z'};
	int i,j,k,temp;
	
	char kontrol;
	char kontrol1;

	int kelime1deger;
	int kelime2deger;

	int yap1 = 0;
	int yap2 = 0;

	int sonuc = 0;
	int deger;
	
	if(m < a)
	{
		temp = m;
		m = a;
		a = temp;	
	}
		
	for( i = 0; i <= m; i++ )
	{	
		if( (kelime_1[i] != '\0') && (kelime_2[i] != '\0') ) 
		{			
			kontrol = kelime_1[i];
			kontrol1 = kelime_2[i];
			
			for( j = 0; j < 30; j++ )
			{
				if( sonuc == 0 )
				{
					if( alfabe[j] == kontrol )
					{
						kelime1deger = j;	
						yap1 = 1;	
					}
				
					if( (alfabe[j] == kontrol1) )
					{	
						kelime2deger = j;
						yap2 = 1;
					}
						
					if( (yap1 == 1) && (yap2 == 1) )
					{
								
						if ( kelime1deger < kelime2deger )
						{
							sonuc = 1;
							
							return true;
						}
					
						else if ( kelime1deger > kelime2deger )
						{
							sonuc = 1;
								
							return false;
						}
					
						else if ( kelime1deger == kelime2deger )
						{
							yap1 = 0;
							yap2 = 0;
							
							deger = 1;
						}		
					}	
				}
			
				else if (sonuc == 1)
				{
					break;
				}						
			}
		}
		
		else if ((kelime_1[i] == '\0') && (kelime_2[i] != '\0') && sonuc == 0)
		{
			sonuc = 1;
			
			return true;
		}
		else if ((kelime_1[i] != '\0') && (kelime_2[i] == '\0') && sonuc == 0)
		{
			sonuc = 1;
			
			return false;
		}
		
		else if ((kelime_1[i] == '\0') && (kelime_2[i] == '\0') && deger == 1 && sonuc == 0)
		{
			
			if(paper < paper1)
			{	
				return true;			
			}
			
			else if(paper > paper1)
			{
				return false;
			}
							
			else if(paper == paper1)
			{			
				if(frek < frek1)
				{
					return true;			
				}
								
				else if(frek > frek1)
				{
					return false;	
				}
				
				else if(frek == frek1)
				{
					//Böyle bir durum olamaz.
				}
			}
		}
	}
}


