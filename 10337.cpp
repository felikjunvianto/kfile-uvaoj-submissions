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

int T,N,x,y;
int wind[11][1010];
int dp[1010][11];

int solve(int now,int al)
{
	if((now==N)&&(!al)) return(0);
	if((now==N)&&(al)) return(INF);
	if(dp[now][al]!=-1) return(dp[now][al]);
	
	int &ret = dp[now][al] = 30+wind[al][now]+solve(now+1,al);
	if(al<9) ret=min(ret,60+wind[al][now]+solve(now+1,al+1));
	if(al) ret=min(ret,20+wind[al][now]+solve(now+1,al-1));
	return(ret);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);N/=100;
		for(y=9;y>=0;y--)
			for(x=0;x<N;x++)
			{
				scanf("%d",&wind[y][x]);
				wind[y][x]*=-1;
			}
			
		memset(dp,-1,sizeof(dp));
		printf("%d\n\n",solve(0,0));
	}
	return 0;
}


