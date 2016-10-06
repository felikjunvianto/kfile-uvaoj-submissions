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

int dp[10010];
int t,x,y,bur[2];

int main()
{
	while(scanf("%d %d %d",&bur[0],&bur[1],&t)!=EOF)
	{
		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		for(y=0;y<2;y++)
			for(x=bur[y];x<=t;x++) if(dp[x-bur[y]]!=-1) 
				dp[x]=max(dp[x],dp[x-bur[y]]+1);

		for(x=t;x>=0;x--) if(dp[x]!=-1) break;
		printf("%d",dp[x]);
		if(x!=t) printf(" %d",t-x);
		printf("\n");
	}
	return 0;
}

