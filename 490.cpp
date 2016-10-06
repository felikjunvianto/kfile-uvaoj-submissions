#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int x,y,z,maks;
string kata[150];

int main()
{
	x=0;
	maks=0;
	while(getline(cin,kata[x]))
	{
		if(maks<kata[x].size()) maks=kata[x].size();
		x++;
	}
	x--;
	
	for(z=0;z<maks;z++)
	{
		for(y=x;y>=0;y--) if(kata[y].size()-1<z) cout << " "; else cout << kata[y][z];
		cout << endl;
	}
	return 0;
}
