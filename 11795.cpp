#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>

#define fi first
#define se second
#define pii pair<int, int> 
#define pb push_back
#define mp make_pair
#define ll long long
#define PI 2*acos(0.0)
#define EPS 1e-9
#define INF 1000000000

using namespace std;

int T, N, final;
ll dp[1 << 17];
char msk[20];
bool mat[20][20];

ll solve(int state)
{
	if(state == final) return 1LL;
	if(dp[state] != -1LL) return dp[state];
	
	ll &ret = dp[state] = 0LL;
	for(int i = 1; i <= N; i++) 
		if(!(state & (1 << i)))
		{
			for(int j = 0; j <= N; j++) 
				if((state & (1 << j)) && mat[j][i])
				{
					ret += solve(state + (1 << i));
					break;
				}	
		}
	return ret;
}

int main()
{
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		final = (1 << (N + 1)) - 1;
		for(int i = 0; i <= N; i++)
		{
			scanf("%s", msk + 1);
			for(int j = 1; j <= N; j++) mat[i][j] = msk[j] - '0';
		}
		
		memset(dp, -1LL, sizeof(dp));
		printf("Case %d: %lld\n", t, solve(1));
	}
	return 0;
}