#include <cstdio>
#include <cstdlib>
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
#include <set>

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

vector<int> origin[111];
int dp[111];

int T, src, a, b;

int solve(int now)
{
	if(now == src) return 0;
	if(dp[now] != -1) return dp[now];
	
	int &ret = dp[now] = -INF;
	for(int i = 0; i < origin[now].size(); i++) ret = max(ret, solve(origin[now][i]) + 1);
	return ret;
}

int main()
{
	int t = 0;
	while(1)
	{
		scanf("%d", &T);
		if(!T) break;
		
		scanf("%d", &src);
		for(int i = 1; i <= T; i++) origin[i].clear();
		while(1)
		{
			scanf("%d %d", &a, &b);
			if(!a && !b) break;
			origin[b].pb(a);
		}
		
		memset(dp, -1, sizeof(dp));
		int dest = -1, ans = -INF;
		
		for(int i = 1; i <= T; i++)
		{
			int temp = solve(i);
			if(temp > ans) 
			{
				ans = temp;
				dest = i;
			}
		}
		
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++t, src, ans, dest);
	}
	return 0;
}

