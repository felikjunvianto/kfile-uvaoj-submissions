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

int D, G;
LL dp[2][40][40][40];

LL solve(int turn, int cons, int accuM, int accuG)
{
	if(accuG == D && accuM < D) return 0LL;
	if(accuM == D && accuG <= D) return 1LL;
	if(dp[turn][cons][accuM][accuG] != -1LL) return dp[turn][cons][accuM][accuG];
	
	LL &ret = dp[turn][cons][accuM][accuG] = 0LL;
	
	if(turn == 0)
	{
		if(accuG < D) ret += solve(1, 1, accuM, accuG + 1);
		if(accuM < D && cons < G) ret += solve(0, cons + 1, accuM + 1, accuG);
	} else
	{
		if(accuM < D) ret += solve(0, 1, accuM + 1, accuG);
		if(accuG < D && cons < G) ret += solve(1, cons + 1, accuM, accuG + 1);
	}
	
	return ret;
}

int main()
{
	int T = 0;
	while(1)
	{
		scanf("%d %d", &D, &G);
		if(D == -1 && G == -1) break;
		
		LL ans;
		memset(dp, -1LL, sizeof(dp));
		if(D == 0) ans = 1LL;
			else if(G == 0) ans = 0LL;
				else ans = 2LL * solve(0, 1, 1, 0);
		
		printf("Case %d: %lld\n", ++T, ans);
	}
	return 0;
}

