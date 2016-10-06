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

int C,T,S,E,D,x,a,b;
vector<int> adjlist[110];
int dp[110][210];

int solve(int city,int day)
{
	if((day==D)&&(city==E)) return(1);
	if((day==D)&&(city!=E)) return(0);
	
	if(dp[city][day]==-1)
	{
		dp[city][day]=0;
		for(int x=0;x<adjlist[city].size();x++)
		{
			int next=adjlist[city][x];
			dp[city][day]|=solve(next,day+1);
		}
	}
	return(dp[city][day]);
}

int main()
{
	while(1)
	{
		scanf("%d %d",&C,&T);
		if(C+T==0) break;
		
		for(x=1;x<=C;x++) adjlist[x].clear();
		while(T--)
		{
			scanf("%d %d",&a,&b);
			adjlist[a].pb(b);
			adjlist[b].pb(a);
		}
		scanf("%d %d %d",&S,&E,&D);
		memset(dp,-1,sizeof(dp));
		if(solve(S,0)) printf("Yes, Teobaldo can travel.\n");
			else printf("No, Teobaldo can not travel.\n");
	}
	return 0;
}

