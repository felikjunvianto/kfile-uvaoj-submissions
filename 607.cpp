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

int dp[1111][1111],N,L,tot,C,x,y,z,i;
int lec[1111];

int solve(int T,int now)
{
	if(T==N) return(0);
	if(now==tot) return(INF);
	if(dp[T][now]!=-1) return(dp[T][now]);
	
	int free,i,temp,&ret = dp[T][now];
	temp=0,ret=INF;
	
	for(i=T;i<N;i++) if(temp+lec[i]>L) break; else
	{
		temp+=lec[i];
		free=L-temp;
		if(!free) ret=min(ret,solve(i+1,now+1)); else
			if((free)&&(free<11)) ret=min(ret,solve(i+1,now+1)-C); else
				ret=min(ret,solve(i+1,now+1)+(free-10)*(free-10));
	}
	return(ret);
}

int main()
{
	i=0;
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		scanf("%d %d",&L,&C);
		for(x=0;x<N;x++) scanf("%d",&lec[x]);
		memset(dp,-1,sizeof(dp));
		
		x=-1;tot=0;
		do
		{
			x++;z=0;y=x;
			while((y<N)&&(z+lec[y]<=L)) 
			{
				z+=lec[y];
				y++;
			}
			tot++;
			x=y-1;
		}while(x+1<N);
		
		if(i) printf("\n");i++;
		printf("Case %d:\n",i);
		printf("Minimum number of lectures: %d\n",tot);
		printf("Total dissatisfaction index: %d\n",solve(0,0));
	}
	return 0;
}

