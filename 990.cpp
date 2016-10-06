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

int T,W,N,x,y,z,cost;
int dp[1010],path[1010];
PII gold[35];

int main()
{
	z=0;
	while(scanf("%d %d",&T,&W)!=EOF)
	{
		scanf("%d",&N);
		for(x=0;x<N;x++) scanf("%d %d",&gold[x].fi,&gold[x].se);
		
		memset(dp,0,sizeof(dp));
		memset(path,0,sizeof(path));
		for(x=0;x<N;x++)
		{
			cost=3*W*gold[x].fi;
			for(y=T;y>=cost;y--) if(dp[y]<dp[y-cost]+gold[x].se)
			{
				dp[y]=dp[y-cost]+gold[x].se;
				path[y]=path[y-cost]|(1<<x);
			}
		}
		
		if(z++) printf("\n");
		y=0;
		for(x=0;x<N;x++) if((path[T]&(1<<x))>0) y++;
		printf("%d\n%d\n",dp[T],y);
		for(x=0;x<N;x++) if((path[T]&(1<<x))>0) 
			printf("%d %d\n",gold[x].fi,gold[x].se);
	}
	return 0;
}

