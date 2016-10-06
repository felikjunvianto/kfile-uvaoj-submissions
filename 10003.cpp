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

int L, N, x;
int point[60];
int dp[60][60];

int solve(int L, int R)
{
	if(L+1==R) return 0;
	if(dp[L][R]!=-1) return dp[L][R];
	
	int &ret = dp[L][R] = INF;
	for(int i = L+1;i<R;i++) ret = min(ret, solve(L, i) + solve(i, R) + point[R] - point[L]);
	return ret;
}

int main()
{
	point[0] = 0;
	while(1)
	{
		scanf("%d",&L);
		if(!L) break;
		
		scanf("%d",&N);
		for(x=1;x<=N;x++) scanf("%d",&point[x]); N++;
		point[N] = L;
		memset(dp,-1,sizeof(dp));
		
		printf("The minimum cutting is %d.\n",solve(0, N));
	}
	return 0;
}

