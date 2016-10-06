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

char col[20];
LL dp[20][20];
int panjang;

int dec(char T)
{
	if(T<='9') return(T-'0');
	return(T-'A'+10);
}

LL solve(int y,int x)
{
	if(x+1==panjang) return(1);
	if(dp[y][x]==-1)
	{
		dp[y][x]=0;
		if(col[x+1]=='?') 
		{
			for(int z=1;z<=panjang;z++) 
				if(abs(z-y)>1) dp[y][x]+=solve(z,x+1);
		}
		
		else
		{
			int next=dec(col[x+1]);
			if(abs(next-y)>1) dp[y][x]+=solve(next,x+1);
		}
	}
	return(dp[y][x]);
}

int main()
{
	while(scanf("%s",col)!=EOF)
	{
		panjang=strlen(col);
		memset(dp,-1,sizeof(dp));
		LL ans=0;
		if(col[0]=='?') for(int x=1;x<=panjang;x++) ans+=solve(x,0); else
			ans=solve(dec(col[0]),0);
		printf("%lld\n",ans);
	}
	return 0;
}

