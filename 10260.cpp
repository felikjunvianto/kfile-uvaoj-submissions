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

int bil[30];
int x,y,z,panjang;
char masuk[30];

int main()
{
	while(scanf("%s",masuk)!=EOF)
	{
		panjang=strlen(masuk);
		bil[0]=0;
		for(x=0;x<panjang;x++) switch(masuk[x])
		{
			case('B') : case('F') : case('P') : case('V') : bil[x+1]=1;break;
			case('C') : case('G') : case('J') : case('K') : 
			case('Q') : case('S') : case('X') : case('Z') : bil[x+1]=2;break;
			case('D') : case('T') : bil[x+1]=3;break;
			case('L') : bil[x+1]=4;break;
			case('M') : case('N') : bil[x+1]=5;break;
			case('R') : bil[x+1]=6;break;
			default : bil[x+1]=0;break;
		}
		for(x=1;x<=panjang;x++) if(bil[x]!=0)
			if(bil[x]!=bil[x-1]) printf("%d",bil[x]);
		printf("\n");
	}
	return 0;
}

