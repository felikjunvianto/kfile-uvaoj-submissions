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

int N,D,x,y,z;
int dp[35],path[35];
int box[35][15],indig[35];
vector<int> adjlist[35];

int solve(int now)
{
	if(dp[now]!=-1) return(dp[now]);
	
	int &ret = dp[now] = 1;
	for(int x=0;x<adjlist[now].size();x++) 
	{
		int temp = solve(adjlist[now][x])+1;
		if(ret<temp)
		{
			ret=temp;
			path[now]=adjlist[now][x];
		}
	}
	return(ret);
}

int main()
{
	while(scanf("%d %d",&N,&D)!=EOF)
	{
		for(x=1;x<=N;x++)
		{
			adjlist[x].clear();
			indig[x]=0;
			for(y=0;y<D;y++) scanf("%d",&box[x][y]);
			sort(box[x],box[x]+D);
		}
		
		for(x=1;x<=N;x++)
			for(y=1;y<=N;y++)
			{
				bool masuk=true;
				for(z=0;(z<D)&&masuk;z++) if(box[x][z]>=box[y][z]) masuk=false;
				if(masuk) 
				{
					adjlist[x].pb(y);
					indig[y]++;
				}
			}
			
		int ans=-1;
		memset(dp,-1,sizeof(dp));
		for(x=1;x<=N;x++) if(indig[x]==0)
			if((ans==-1)||(solve(ans)<solve(x))) ans=x;
			
		z=solve(ans);
		printf("%d\n",z);
		while(z--)
		{
			printf("%d",ans);
			ans=path[ans];
			if(z) printf(" "); else printf("\n");
		}
	}
	return 0;
}

