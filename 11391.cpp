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

int dr[] = { 0, 1, 1, 1, 0,-1,-1,-1};
int dc[] = { 1, 1, 0,-1,-1,-1, 0, 1};

int T, R, C, N;
int dp[5][5][1 << 16];

int solve(int state)
{
	if(__builtin_popcount(state) == 1) return 1;
	if(dp[R][C][state] != -1) return dp[R][C][state];
	
	int &ret = dp[R][C][state] = 0;
	
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++) 
		{
			int offsetI = C * (R - i) - j - 1;
			
			if(state & (1 << offsetI))
				for(int k = 0; k < 8; k++)
				{
					int sr = i + dr[k], sc = j + dc[k];
					int nr = i + 2 * dr[k], nc = j + 2 * dc[k];
					int offsetS = C * (R - sr) - sc - 1;
					int offsetN = C * (R - nr) - nc - 1;
					
					if(sr >= 0 && sc >= 0 && sr < R && sc < C && (state & (1 << offsetS)))
						if(nr >= 0 && nc >= 0 && nr < R && nc < C && !(state & (1 << offsetN)))
							ret += solve(state - (1 << offsetI) - (1 << offsetS) + (1 << offsetN));
				}
		}	
	return ret;
}

int main()
{
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	
	for(int t = 1; t <= T; t++)
	{
		scanf("%d %d %d", &R, &C, &N);
		
		int r, c, start = 0;
		for(int i = 0; i < N; i++)
		{
			scanf("%d %d", &r, &c);
			r--; c--;
			start |= 1 << (C * (R - r) - c - 1);
		}

		printf("Case %d: %d\n", t, solve(start));
	}
	return 0;
}

