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

int T,x;
int dp[1010][1010];
char kata[1010];

int solve(int a,int b)
{
	if(a>b) return(0);
	if(a==b) return(1);
	if(a+1==b) return(kata[a]==kata[b]?2:1);
	if(dp[a][b]!=-1) return(dp[a][b]);
	
	int &ret = dp[a][b] = 0;
	if(kata[a]==kata[b]) dp[a][b]=2+solve(a+1,b-1); else
		dp[a][b]=max(solve(a+1,b),solve(a,b-1));
		
	return(ret);
}

int main()
{
	scanf("%d",&T);getchar();
	while(T--)
	{
		gets(kata);
		x=strlen(kata);
		memset(dp,-1,sizeof(dp));
		printf("%d\n",solve(0,x-1));
	}
	return 0;
}

