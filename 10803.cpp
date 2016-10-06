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

int T,N,x,y,z;
PII koor[111];
double dis[111][111];


int main()
{
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&N);
		for(x=1;x<=N;x++) scanf("%d %d",&koor[x].fi,&koor[x].se);
		
		for(x=1;x<=N;x++) dis[x][x]=0;
		for(x=1;x<N;x++)
			for(y=x+1;y<=N;y++) dis[x][y]=dis[y][x]=INF;
		
		for(x=1;x<N;x++)
			for(y=x+1;y<=N;y++)
			{
				int dx=koor[x].fi-koor[y].fi,dy=koor[x].se-koor[y].se;
				z=dx*dx+dy*dy;
				if(z<=100) dis[x][y]=dis[y][x]=sqrt((double)z);
			}
			
		for(z=1;z<=N;z++)
			for(x=1;x<=N;x++)
				for(y=1;y<=N;y++) 
					dis[x][y]=min(dis[x][y],dis[x][z]+dis[z][y]);
			
		bool ada=true;
		double ans=0;
		for(x=1;x<N;x++)
			for(y=x+1;y<=N;y++) if(dis[x][y]==INF) ada=false; else
				ans=max(ans,dis[x][y]);
			
		printf("Case #%d:\n",i);
		if(ada) printf("%.4lf\n\n",ans); else printf("Send Kurdy\n\n");
	}
	return 0;
}

