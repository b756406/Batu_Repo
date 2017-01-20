#include <iostream>
#include <fstream>
#include <locale.h>
#include <sstream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include "operations.h"
#include "stack.h"

/*
Resul Emre Aygan - 1030520505
Metehan Altuntaþ - 1030520497
Batuhan Ýpek - 1030516168
*/

using namespace std;

int operations::StringLength(string StrName, int length)
{	
	length = strlen(StrName.c_str());
      
	return length;
}

bool operations::sorting(string kelime_1, string kelime_2, int m, int a, int paper, int paper1, int frek, int frek1)
{
	char alfabe[30] = {' ', 'a', 'b', 'c', 'ç', 'd', 'e', 'f', 'g', 'ð', 'h', 'ý', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'ö', 'p', 'r', 's', 'þ', 't', 'u', 'ü', 'v', 'y', 'z'};
	
	int i, j, k, temp, kelime1deger, kelime2deger, yap1 = 0, yap2 = 0, sonuc = 0, deger;
	
	char kontrol, kontrol1;

	if ( m < a )
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
			
				else if ( sonuc == 1 )
				{
					break;
				}						
			}
		}
		
		else if ( (kelime_1[i] == '\0') && (kelime_2[i] != '\0') && sonuc == 0 )
		{
			sonuc = 1;
			return true;
		}
		else if ( (kelime_1[i] != '\0') && (kelime_2[i] == '\0') && sonuc == 0 )
		{
			sonuc = 1;
			return false;
		}
		
		else if ( (kelime_1[i] == '\0') && (kelime_2[i] == '\0') && deger == 1 && sonuc == 0 )
		{
			
			if ( paper < paper1 )
			{	
				return true;			
			}
			
			else if ( paper > paper1 )
			{
				return false;
			}
							
			else if ( paper == paper1 )
			{			
				if ( frek < frek1 )
				{
					return true;			
				}
								
				else if ( frek > frek1 )
				{
					return false;	
				}
				
				else if ( frek == frek1 )
				{
					//Böyle bir durum olamaz.
				}
			}
		}
	}
}

Stack operations::algorithm(Stack v1, Stack v2)
{
	
		
	char kelime_1[40], kelime_2[40];
	
	int m, a, length, paper, paper1, frek, frek1, value3, value4, value5, value6;
	
	string temp1,temp2,temp3,temp4,temp5,temp6;
	
	bool back;
	
	while ( v1.top != NULL )
	{
		if ( v2.top == NULL )
		{
			temp3 = v1.top -> evrak;
			temp1 = v1.top -> kelime;
			temp5 = v1.top -> frekans;
						
			v2.push(temp3, temp1, temp5);
			
			v1.pop();
		}
		
		else if ( v2.top != NULL )
		{
			temp3 = v1.top -> evrak;
			temp1 = v1.top -> kelime;
			temp5 = v1.top -> frekans;
			
			v1.pop();

			temp4 = v2.top -> evrak;
			temp2 = v2.top -> kelime;
			temp6 = v2.top -> frekans;

			v2.pop();

			m = StringLength(temp1, length);
			a = StringLength(temp2, length);
	
			strncpy(kelime_1, temp1.c_str(), sizeof(kelime_1));
			strncpy(kelime_2, temp2.c_str(), sizeof(kelime_2));
		
			value3 = atoi(temp3.c_str());
			value4 = atoi(temp4.c_str());
			value5 = atoi(temp5.c_str());
			value6 = atoi(temp6.c_str());
			
			back = sorting( kelime_1, kelime_2, m, a, value3, value4, value5, value6 );
			
			if ( back == false )
			{
				v2.push(temp4, temp2, temp6);
				
				v2.push(temp3, temp1, temp5);
			}
			
			else if ( back == true )
			{
				v1.push(temp4, temp2, temp6);
				
				v1.push(temp3, temp1, temp5);
			}
		}
	}
		
	return v2;
}
