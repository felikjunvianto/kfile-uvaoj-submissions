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

int dp[4500];
int N,x,stat;
char masuk[15];

int solve(int now)
{
	if(dp[now]==-1)
	{
		dp[now]=0;
		int x;
		for(x=0;x<12;x++) if(now&(1<<x)) dp[now]++; 
		for(x=1;x<11;x++) if(now&(1<<x))
		{
			if(!(now&(1<<(x-1)))&&(now&(1<<(x+1)))) dp[now]=min(dp[now],solve(now+(1<<(x-1))-(1<<x)-(1<<(x+1))));
			if(!(now&(1<<(x+1)))&&(now&(1<<(x-1)))) dp[now]=min(dp[now],solve(now+(1<<(x+1))-(1<<x)-(1<<(x-1))));
		}
	}
	return(dp[now]);
}

int main()
{
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",masuk);
		memset(dp,-1,sizeof(dp));
		stat=0;
		for(x=0;x<12;x++)
		{
			stat*=2;
			if(masuk[x]=='o') stat++;
		}
		printf("%d\n",solve(stat));
	}
	return 0;
}

