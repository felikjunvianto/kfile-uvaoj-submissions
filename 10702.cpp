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

int C,S,E,T,x,y;
int dp[1010][110];
int adjmat[110][110];
bool last[110];

int solve(int x,int now)
{
	if((x==T)&&(last[now])) return(0);
	if((x==T)&&(!last[now])) return(-INF);
	
	if(dp[x][now]==-1)
	{
		dp[x][now]=0;
		for(int y=1;y<=C;y++) if(now!=y)
			dp[x][now]=max(dp[x][now],adjmat[now][y]+solve(x+1,y));
	}
	return(dp[x][now]);
}

int main()
{
	while(1)
	{
		scanf("%d %d %d %d",&C,&S,&E,&T);
		if(C+S+E+T==0) break;
		
		for(x=1;x<=C;x++)
			for(y=1;y<=C;y++) scanf("%d",&adjmat[x][y]);
			
		memset(last,false,sizeof(last));
		while(E--)
		{
			scanf("%d",&x);
			last[x]=true;
		}
		memset(dp,-1,sizeof(dp));
		printf("%d\n",solve(0,S));
	}
	return 0;
}

