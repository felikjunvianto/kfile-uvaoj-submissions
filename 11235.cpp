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

using namespace std;

int N,Q,x,y,z;
int arr[100100],dp[100100][20];
pair<int,PII> reg[100100];

int bs(int cari)
{
	int kiri=1,kanan=z;
	while(kiri<=kanan)
	{
		int pivot=(kiri+kanan)/2;
		if(reg[pivot].fi==cari) return(pivot); else
			if(reg[pivot].fi>cari) kanan=pivot-1; else
				kiri=pivot+1;
	}
}

int solve(int a,int b)
{
	if(a>b) return(0);
	int x,range=b-a+1;
	for(x=0;x<20;x++) if((1<<x)>range) break;x--;
	return(max(dp[a][x],dp[b-(1<<x)+1][x]));
}

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(N==0) break;
		
		scanf("%d",&Q);
		for(x=1;x<=N;x++) scanf("%d",&arr[x]);
		
		x=z=0;
		do
		{
			x++;
			y=x+1;
			while((arr[y]==arr[x])&&(y<=N)) y++;y--;
			reg[++z]=mp(arr[x],mp(x,y));
			x=y;
		}while(x<N);
		
		for(x=1;x<=z;x++) dp[x][0]=reg[x].se.se-reg[x].se.fi+1;
		
		for(x=1;(1<<x)<=z;x++)
			for(y=1;y+(1<<x)-1<=z;y++)
				dp[y][x]=max(dp[y][x-1],dp[y+(1<<(x-1))][x-1]);
		
		while(Q--) 
		{
			scanf("%d %d",&x,&y);
			int regx=bs(arr[x]),regy=bs(arr[y]);
			if(regx==regy) printf("%d\n",y-x+1); else
			{
				int kiri=reg[regx].se.se-x+1;
				int kanan=y-reg[regy].se.fi+1;
				printf("%d\n",max(max(kiri,kanan),solve(regx+1,regy-1)));
			}
		}
	}
	return 0;
}

