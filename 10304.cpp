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

int N, f[250];
int dp[250][250][250];
int root[250][250];

int solve(int L, int R, int H)
{
	if(L > R) return 0;
	if(L == R) return H * f[L];
	if(dp[L][R][H] != -1) return dp[L][R][H];
	
	int &ret = dp[L][R][H] = INF;
	for(int i = L; i <= R; i++) ret = min(ret, solve(L, i - 1, H + 1) + solve(i + 1, R, H + 1) + H * f[i]);
	
	return ret;
}

int main()
{
	while(scanf("%d", &N) != EOF)
	{
		for(int i = 0; i < N; i++) scanf("%d", &f[i]);
		memset(dp, -1, sizeof(dp));
		
		printf("%d\n", solve(0, N-1, 0));
	}
	return 0;
}

