#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string kata;
int awal,akhir,x,y;

int main()
{
	while(getline(cin,kata))
	{
		awal =-1;
		do
		{
			awal++;
			if(kata[awal] == ' ') printf(" "); else
			{
				akhir=awal+1;
				while((kata[akhir]!=' ')&&(akhir<kata.size())) akhir++;
				akhir--;
				for(x=akhir;x>=awal;x--) cout << kata[x];
				awal=akhir;
			}
		} while (awal<kata.size()-1);
		cout << "\n";
	}
	return 0;
}
