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

int N,x,y,z,ans;
PII elep[1010];
int dp[1010],path[1010];

int solve(int now)
{
	if(dp[now]!=-1) return(dp[now]);
	
	int &ret = dp[now] = 1;
	for(int x=1;x<=N;x++) if(x!=now)
		if((elep[now].fi<elep[x].fi)&&(elep[now].se>elep[x].se))
		{		
			int temp=solve(x)+1;
			if(ret<temp)
			{
				ret=temp;
				path[now]=x;
			}
		}
			
	return(ret);
}

int main()
{
	N=0;
	while(scanf("%d %d",&x,&y)!=EOF) elep[++N]=mp(x,y);
	
	memset(dp,-1,sizeof(dp));
	ans=-1;
	for(x=1;x<=N;x++) if((ans==-1)||(solve(ans)<solve(x))) ans=x;
	z=solve(ans);
	printf("%d\n",z);
	while(z--)
	{
		printf("%d\n",ans);
		ans=path[ans];
	}
	return 0;
}

