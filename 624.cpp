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

pair<bool,int> dp[5100];
int cd[30];
int N,track,x,y,z;

int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		scanf("%d",&track);
		for(x=0;x<=N;x++) dp[x]=mp(false,0);
		dp[0]=mp(true,0);
		
		for(x=0;x<track;x++) scanf("%d",&cd[x]);
		for(x=0;x<track;x++)
			for(y=N;y>=cd[x];y--) if(dp[y-cd[x]].fi) 
				dp[y]=mp(1,dp[y-cd[x]].se|(1<<x));			
		
		for(x=N;x>=0;x--) if(dp[x].fi) break;
		for(y=0;y<track;y++) if((dp[x].se&(1<<y))>0) printf("%d ",cd[y]);
		printf("sum:%d\n",x);
	}
	return 0;
}

