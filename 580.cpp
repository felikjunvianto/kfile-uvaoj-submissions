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

int dp[33][2][33][2];
int N;

int solve(int now, int tipe, int stak, int critical)
{
	if(now==N && !critical) return 0;
	if(now==N && critical) return 1;
	if(dp[now][tipe][stak][critical]!=-1) return dp[now][tipe][stak][critical];
	
	int &ret = dp[now][tipe][stak][critical] = 0;
	if(!tipe) // last is U
	{
		if(stak+1>2) ret+=solve(now+1,tipe,stak+1,1);
			else ret+=solve(now+1,tipe,stak+1,critical);
		ret+=solve(now+1,1,1,critical);
	} else // last is L
	{
		ret+=solve(now+1,0,1,critical);
		ret+=solve(now+1,tipe,stak+1,critical);
	}
	return ret;
}

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		memset(dp,-1,sizeof(dp));
		printf("%d\n",solve(1,0,1,0)+solve(1,1,1,0));
	}
	return 0;
}

