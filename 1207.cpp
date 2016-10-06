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

int A,B;
char stra[1010],strb[1010];
int dp[1010][1010];

int solve(int pa,int pb)
{
	if(pa==A && pb==B) return 0;
	if(pa==A) return B - pb;
	if(pb==B) return A - pa;
	if(dp[pa][pb]!=-1) return dp[pa][pb];
	
	int &ret = dp[pa][pb];
	if(stra[pa]==strb[pb]) ret = solve(pa+1,pb+1);
		else ret = min(min(solve(pa+1,pb),solve(pa,pb+1)),solve(pa+1,pb+1))+1;
		
	return ret;
}

int main()
{
	while(scanf("%d %s",&A,stra)!=EOF)
	{
		scanf("%d %s",&B,strb);
	
		memset(dp,-1,sizeof(dp));
		printf("%d\n",solve(0,0));
	}
	return 0;
}

