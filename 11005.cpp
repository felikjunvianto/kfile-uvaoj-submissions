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
#define pi acos(-1.0)
#define eps 1e-9

using namespace std;

int t,x,y,z,n,terkecil;
int biaya[40],cost[40];
int ubah;

int basis(int t)
{
	int temp=ubah;
	cost[t]=0;
	while(temp>0)
	{
		cost[t]+=biaya[temp%t];
		temp/=t;
	}
	return(cost[t]);
}

int main()
{
	scanf("%d",&t);
	for(x=1;x<=t;x++)
	{
		for(y=0;y<36;y++) scanf("%d",&biaya[y]);
		scanf("%d",&n);
		printf("Case %d:\n",x);
		while(n--)
		{
			scanf("%d",&ubah);
			printf("Cheapest base(s) for number %d:",ubah);
			terkecil=basis(2);
			for(y=3;y<=36;y++) terkecil=min(terkecil,basis(y));
			for(y=2;y<=36;y++) if(cost[y]==terkecil) printf(" %d",y);
			printf("\n");
		}
		if(x<t) printf("\n");
	}
	return 0;
}

