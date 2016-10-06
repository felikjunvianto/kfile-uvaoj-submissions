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

int T,N;
char ang[210];
LL dp[210];
LL batas=2147483647LL;

LL solve(int x)
{
	if(x==N) return(0);
	if(dp[x]!=-1) return(dp[x]);
	
	dp[x] = 0;
	LL ans = 0;
	for(int y=x;y<N;y++)
	{
		ans=(ans*10LL)+(LL)(ang[y]-'0');
		if(ans>batas) break;
		dp[x]=max(dp[x],ans+solve(y+1));
	}
	return(dp[x]);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",ang);
		N=strlen(ang);
		memset(dp,-1,sizeof(dp));
		printf("%lld\n",solve(0));
	}
	return 0;
}

