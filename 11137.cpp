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

int N,K,x,y;
LL dp[10010];

int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(x=1;x<=21;x++)
		{
			K=x*x*x;
			if(K>N) break;
			for(y=K;y<=N;y++) dp[y]+=dp[y-K];
		}
		printf("%lld\n",dp[N]);
	}
	return 0;
}

