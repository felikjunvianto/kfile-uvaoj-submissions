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

int T, N, x, y, X, Y, all;
PII pos[15];
int dis[15][15];
int dp[15][1<<15];

int solve(int now, int state)
{
	if(state==all) return dis[now][0];
	if(dp[now][state]!=-1) return dp[now][state];
	
	int &ret = dp[now][state] = INF;
	for(int i = 1; i <= N ; i++)
		if(!(state&(1<<i))) ret = min(ret, solve(i, state|(1<<i)) + dis[now][i]);
	return ret;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&X, &Y);
		scanf("%d %d",&pos[0].fi, &pos[0].se);
		
		scanf("%d",&N);
		for(x=1;x<=N;x++) scanf("%d %d",&pos[x].fi, &pos[x].se);
		for(x=0;x<=N;x++)
			for(y=x;y<=N;y++)
				dis[x][y] = dis[y][x] = abs(pos[x].fi-pos[y].fi) + abs(pos[x].se-pos[y].se);
		
		memset(dp,-1,sizeof(dp));
		all = (1<<(N+1))-1;
		printf("The shortest path has length %d\n",solve(0,1));
	}
	return 0;
}

