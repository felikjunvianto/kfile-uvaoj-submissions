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

typedef struct
{
	int dis,price;
} gas;

gas city[111];
int T,N,F,a,b;
int dp[111][211];
char msk[100];

int solve(int now, int tank)
{
	if(now==N) return 0;
	if(dp[now][tank]!=-1) return dp[now][tank];
	
	int &ret = dp[now][tank] = INF;
	int dis=city[now+1].dis-city[now].dis;
	
	if(!now && dis<=tank) ret = min(ret,solve(now+1,tank-dis)); else
		if(now) for(int isi = 0; tank+isi<=200;isi++)
		{
			int buy = isi*city[now].price;
			if(tank+isi>=dis) ret=min(ret,solve(now+1,tank+isi-dis)+buy);
		}
	return ret;
}

int main()
{
	scanf("%d",&T);
	
	city[0]=(gas){0,0};
	while(T--)
	{
		scanf("%d",&F);getchar();
		N=1;
		while(gets(msk))
		{
			if(strlen(msk)==0) break;
			
			sscanf(msk,"%d %d",&a,&b);
			if(a<=F) city[N++]=(gas){a,b};
		}
		
		city[N]=(gas){F+100,0};
		memset(dp,-1,sizeof(dp));
		int ans = solve(0,100);
		if(ans==INF) printf("Impossible\n"); else printf("%d\n",ans);
		if(T) printf("\n");
		N=1;
	}
	return 0;
}

