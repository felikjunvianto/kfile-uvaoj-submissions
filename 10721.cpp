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

LL dp[60][60];
int N,K,M;

LL solve(int bar,int left)
{
	if((!bar)&&(!left)) return(1LL);
	if((bar)&&(!left)) return(0LL);
	if((!bar)&&(left)) return(0LL);
	if(dp[bar][left]!=-1LL) return(dp[bar][left]);
	
	LL &ret = dp[bar][left] = 0LL;
	if(left) for(int i=1;(i<=M)&&(bar-i>=0);i++) ret+=solve(bar-i,left-1);
	return(ret);
}

int main()
{
	while(scanf("%d %d %d",&N,&K,&M)!=EOF) 
	{
		memset(dp,-1LL,sizeof(dp));
		printf("%lld\n",solve(N,K));
	}
	return 0;
}

