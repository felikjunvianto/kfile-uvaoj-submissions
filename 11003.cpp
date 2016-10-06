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

int N;
int w[1010], mload[1010];
int dp[1010][3010];

int solve(int now, int thres)
{
	if(now >= N) return 0;
	if(dp[now][thres] != -1) return dp[now][thres];
	
	int &ret = dp[now][thres] = 0;
	ret = max(ret, solve(now + 1, thres)); //leave
	if(w[now] <= thres) ret = max(ret, solve(now + 1, min(thres - w[now], mload[now])) + 1); // take
	
	return ret;
}

int main()
{
	while(1)
	{
		scanf("%d", &N);
		if(!N) break;
		
		for(int i = 0; i < N; i++) scanf("%d %d", &w[i], &mload[i]);
		memset(dp, -1, sizeof(dp));
		
		int ans = 0;
		for(int i = 0; i < N; i++) ans = max(ans, 1 + solve(i + 1, mload[i]));
		printf("%d\n", ans);
	}
	return 0;
}

