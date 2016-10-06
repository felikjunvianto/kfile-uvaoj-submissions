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
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>
#define LL long long
#define INF 1000000000

using namespace std;

int pira[15][15],T,x,y;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		for(y=1;y<=9;y+=2)
			for(x=1;x<=y;x+=2) scanf("%d",&pira[x][y]);
			
		for(y=1;y<=7;y+=2)
			for(x=1;x<=y;x+=2)
			{
				pira[x+1][y+2]=(pira[x][y]-pira[x][y+2]-pira[x+2][y+2])/2;
				pira[x][y+1]=pira[x][y+2]+pira[x+1][y+2];
				pira[x+1][y+1]=pira[x+2][y+2]+pira[x+1][y+2];
			}
			
		for(y=1;y<=9;y++)
			for(x=1;x<=y;x++)
				printf("%d%c",pira[x][y],x==y?'\n':' ');
	}
	return 0;
}

