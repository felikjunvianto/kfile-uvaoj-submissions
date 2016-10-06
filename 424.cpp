#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int awal[110],x,y,z,carry;
string masuk;

int main()
{
	memset(awal,0,sizeof(awal));
	cin >> masuk;
	for(x=0;x<masuk.size();x++) awal[x] = (int)(masuk[masuk.size()-x-1])-48;
	
	do
	{
		cin >> masuk;
		if(masuk=="0") break;
		
		carry=0;
		for(x=0;x<109;x++)
		{
			awal[x] += carry;
			if(x<masuk.size()) awal[x] += ((int)(masuk[masuk.size()-x-1])-48);
			if(awal[x]>9)
			{
				carry=awal[x]/10;
				awal[x] %= 10;
			} else carry=0;
		}
	} while(masuk !="0");

	for(x=109;x>=0;x--) if(awal[x]>0) break;
	for(y=x;y>=0;y--) printf("%d",awal[y]);
	printf("\n");
	return 0;
}
