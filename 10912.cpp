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

int dp[30][30][360];
int L,S,i;

int solve(int now,int start, int sum)
{
	if(now==L && sum==S) return 1;
	if(dp[now][start][sum]!=-1) return dp[now][start][sum];
	
	int &ret = dp[now][start][sum] = 0;
	for(int i=start;i<=26;i++) if(sum+i<=S)
		ret+=solve(now+1,i+1,sum+i);
	return ret;
}

int main()
{
	i=0;
	while(1)
	{
		scanf("%d %d",&L,&S);
		if(!L && !S) break;
		
		printf("Case %d: ",++i);
		if(S>351 || L>26) printf("0\n"); else
		{
			memset(dp,-1,sizeof(dp));
			printf("%d\n",solve(0,1,0));
		}
	}
	return 0;
}

