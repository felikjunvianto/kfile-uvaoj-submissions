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

int N,C,T,E,z,x,y,cost,kasus;
char masuk[30];
map<string,int> city;
vector<PII> adjlist[110];
int adjmat[110][110];
int dp[110][110];

int solve(int now,int day)
{
	if((day<=T)&&(now==C)) return(0);
	if((day==T)&&(now!=C)) return(INF);
	
	if(dp[now][day]==-1)
	{
		dp[now][day]=INF;
		for(int x=0;x<adjlist[now].size();x++) 
			dp[now][day]=min(dp[now][day],adjlist[now][x].se+solve(adjlist[now][x].fi,day+1));
	}return(dp[now][day]);
}

int main()
{
	scanf("%d",&N);
	for(z=1;z<=N;z++)
	{
		city.clear();
		scanf("%d",&C);
		for(x=1;x<=C;x++)
		{
			scanf("%s",masuk);
			city[masuk]=x;
			adjlist[x].clear();
		}
		
		memset(adjmat,-1,sizeof(adjmat));
		scanf("%d",&E);
		while(E--)
		{
			scanf("%s",masuk);x=city[masuk];
			scanf("%s",masuk);y=city[masuk];
			scanf("%d",&cost);
			if((adjmat[x][y]==-1)||(adjmat[x][y]>cost)) adjmat[x][y]=cost;
		}
		
		for(x=1;x<=C;x++)
			for(y=1;y<=C;y++) if(adjmat[x][y]!=-1)
				adjlist[x].pb(mp(y,adjmat[x][y]));
		
		scanf("%d",&kasus);
		printf("Scenario #%d\n",z);
		while(kasus--)
		{
			scanf("%d",&T);T++;
			memset(dp,-1,sizeof(dp));
			int ans=solve(1,0);
			if(ans>=INF) printf("No satisfactory flights\n"); else
				printf("Total cost of flight(s) is $%d\n",ans);
		}
		if(z<N) printf("\n");
	}
	return 0;
}

