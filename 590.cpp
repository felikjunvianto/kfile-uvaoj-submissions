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

int N,K,a,b,x,ans,z;
int adjmat[15][15][35];
int p[15][15];
int dp[15][1010];

int solve(int x,int day)
{
	if((day==K)&&(x==N)) return(0);
	if((day==K)&&(x!=N)) return(INF);
	if(dp[x][day]!=-1) return(dp[x][day]);
	
	int &ret = dp[x][day] = INF;
	int z,urut;
	
	for(z=1;z<=N;z++) if(z!=x)
	{
		urut=day%p[x][z];
		if(adjmat[x][z][urut]!=0)
			ret = min(ret,adjmat[x][z][urut]+solve(z,day+1));
	}
	return(ret);
}

int main()
{
	z=1;
	while(1)
	{
		scanf("%d %d",&N,&K);
		if(N+K==0) break;
		memset(adjmat,-1,sizeof(adjmat));
		
		for(a=1;a<=N;a++)
			for(b=1;b<=N;b++) if(b!=a)
			{
				scanf("%d",&p[a][b]);
				for(x=0;x<p[a][b];x++) scanf("%d",&adjmat[a][b][x]);
			}
		
		memset(dp,-1,sizeof(dp));
		ans=solve(1,0);
		printf("Scenario #%d\n",z++);
		if(ans==INF) printf("No flight possible.\n\n"); else
			printf("The best flight costs %d.\n\n",ans);
	}
	return 0;
}

