#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000000
#define eps 1e-9
#define LL long long
#define PII pair<int,int> 

int N,x,y,carry;
int dp[1010][1010];

int main()
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	dp[1][0]=2;
	dp[2][0]=5;
	for(x=3;x<=1000;x++)
	{
		carry=0;
		for(y=0;y<=1000;y++)
		{
			dp[x][y]=dp[x-1][y]+dp[x-1][y]+dp[x-2][y]+dp[x-3][y]+carry;
			carry=dp[x][y]/10;
			dp[x][y]%=10;
		}
	}
	
	while(scanf("%d",&N)!=EOF)
	{
		for(y=1000;y>=0;y--) if(dp[N][y]!=0) break;
		for(x=y;x>=0;x--) printf("%d",dp[N][x]);
		printf("\n");
	}
	return 0;
}
