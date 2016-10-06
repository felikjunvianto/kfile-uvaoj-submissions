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

int hitung[110];
int t,x,y,now;

int main()
{
	do
	{
		scanf("%d",&t);
		if(t==0) break;
		
		memset(hitung,0,sizeof(hitung));
		for(x=0;x<t;x++) 
		{
			scanf("%d",&y);
			hitung[y]++;
		}
		
		now=0;
		for(x=0;x<110;x++) if(hitung[x]>0)
		{
			now+=hitung[x];
			for(y=0;y<hitung[x];y++)
			{
				printf("%d",x);
				if(now<t) printf(" "); else
					if(y<hitung[x]-1) printf(" ");
			}
		}
		printf("\n");
	}while(t!=0);
	return 0;
}

