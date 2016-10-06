#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>

using namespace std;

char masuk[100];
char alokasi[110][5];
int x,y,z,beda,terkecil,terbaik,kota;

int main()
{
	kota=-1;
	do
	{
		gets(masuk);
		if(masuk[0]=='#') break;
		
		if(masuk[0]=='e')
		{
			terbaik=terkecil=-1;
			for(x=0;x<=kota;x++)
			{
				beda=0;
				for(y=0;y<=kota;y++) if(y!=x)
					for(z=0;z<5;z++) if(alokasi[x][z]!=alokasi[y][z]) beda++;
					
				if((terbaik==-1)||(terkecil>beda))
				{
					terkecil=beda;
					terbaik=x;
				}
			}
			printf("%d\n",terbaik+1);
			kota=-1;
		} else
		{
			kota++;
			for(x=0;x<18;x+=4) switch(masuk[x])
			{
				case('r') : alokasi[kota][0]=masuk[x+2];break;
				case('o') : alokasi[kota][1]=masuk[x+2];break;
				case('y') : alokasi[kota][2]=masuk[x+2];break;
				case('g') : alokasi[kota][3]=masuk[x+2];break;
				case('b') : alokasi[kota][4]=masuk[x+2];break;
			}
		}
	}while(masuk[0]!='#');
	return 0;
}

