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

int T,x,z;
int dp[1010][1010];
char masuk[1010];

int solve(int a,int b)
{
	if(a==b) return(0);
	if(a+1==b) return(masuk[a]==masuk[b]?0:1);
	if(dp[a][b]!=-1) return(dp[a][b]);
	
	int &ret = dp[a][b];
	if(masuk[a]==masuk[b]) ret=solve(a+1,b-1); else
		ret=min(min(solve(a+1,b)+1,solve(a,b-1)+1),solve(a+1,b-1)+1);
		
	return(ret);
}

int main()
{
	scanf("%d",&T);
	for(z=1;z<=T;z++)
	{
		scanf("%s",masuk);
		x=strlen(masuk);
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %d\n",z,solve(0,x-1));
	}
	return 0;
}

