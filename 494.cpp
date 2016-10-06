#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string kata;
int jumlah,x,y,z;

bool huruf(char t)
{
	if((((int)t >= 65)&&((int)t<=90))||(((int)t >=97)&&((int)t <= 122))) return true;
		else return false;
}

int main()
{
	while(getline(cin,kata))
	{
		jumlah=0;
		x=-1;
		do
		{
			x++;
			if(huruf(kata[x]))
			{
				y=x+1;
				while((huruf(kata[y]))&&(y<=kata.size()-1)) y++;
				y--;
				jumlah++;
				x=y;
			}
		} while(x<kata.size()-1);
		cout << jumlah << endl;
	}
	return 0;
}
