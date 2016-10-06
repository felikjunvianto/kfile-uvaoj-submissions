#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string kata;
int x;

char konversi(char c)
{
	switch(c)
	{
		case 'A' : case 'B' : case 'C' : return('2');break;
		case 'D' : case 'E' : case 'F' : return('3');break;
		case 'G' : case 'H' : case 'I' : return('4');break;
		case 'J' : case 'K' : case 'L' : return('5');break;
		case 'M' : case 'N' : case 'O' : return('6');break;
		case 'P' : case 'Q' : case 'R' : case 'S' : return('7');break;
		case 'T' : case 'U' : case 'V' : return('8');break;
		case 'W' : case 'X' : case 'Y' : case 'Z' : return('9');break;
		default	: return(c);break;
	}
}

int main()
{
	while (cin >> kata) 
	{
		for(x=0;x<kata.size();x++) cout << konversi(kata[x]);
		cout <<"\n";
	}
	return 0;
}
