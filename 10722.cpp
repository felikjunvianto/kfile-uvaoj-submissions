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

const int LIM_DGT = 500;

int N, B;
vector<int> dp[111][130][2], ONE, ZERO;;

vector<int> multiply(int a, vector<int> b)
{
	vector<int> c; c.resize(LIM_DGT, 0);
	int carry = 0;
	
	for(int i = 0; i < LIM_DGT; i++)
	{
		c[i] = b[i] * a + carry;
		carry = c[i] / 10;
		c[i] %= 10;
	}
	
	return c;
}

vector<int> add(vector<int> a, vector<int> b)
{
	vector<int> c; c.resize(LIM_DGT, 0);
	int carry = 0;
	
	for(int i = 0; i < LIM_DGT; i++)
	{
		c[i] = a[i] + b[i] + carry;
		carry = c[i] / 10;
		c[i] %= 10;
	}
	
	return c;
}

vector<int> solve(int now, int base, bool aman)
{
	if(now == 1 && !aman) return ONE;
	if(now == 1 && aman) return multiply(base-2, ONE);
	if(dp[now][base][aman].size() == 0)	
	{
		dp[now][base][aman].resize(LIM_DGT, 0);
		if(!aman) dp[now][base][aman] = add(solve(now-1, base, true), solve(now-1, base, false));
			else dp[now][base][aman] = add(multiply(base-1, solve(now-1, base, true)), multiply(base-2, solve(now-1, base, false)));
	}
	
	return dp[now][base][aman];
	
	/*int &ret = dp[now][base][aman] = 0;
	if(!aman) ret += solve(now-1, base, true) + solve(now-1, base, false);
		else ret += (base-1) * solve(now-1, base, true) + (base-2) * solve(now-1, base, false);
	
	return ret;*/
}

int main()
{	
	ONE.resize(LIM_DGT, 0); ONE[0] = 1;
	ZERO.resize(LIM_DGT, 0);
	
	for(int i = 0; i < 111; i++)
		for(int j = 0; j < 130; j++) 
			for(int k = 0; k < 2; k++)
				dp[i][j][k].clear();
	
	while(1)
	{
		scanf("%d %d", &B, &N);
		if(!N && !B) break;
		
		vector<int> ans = add(solve(N, B, true), solve(N, B, false));
		
		int st;
		for(st = ans.size() - 1; st >= 0; st--) if(ans[st] > 0) break;
		for(int i = st; i >= 0; i--) printf("%d", ans[i]);
		printf("\n");
	}
	return 0;
}

