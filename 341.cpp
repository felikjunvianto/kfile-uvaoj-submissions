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
#define PIII pair<int,PII> 
#define PDD pair<double,double>
#define LL long long
#define INF 1000000000

using namespace std;

int N,x,y,z,i,cost,source,dest,ans;
int par[15],dis[15];
vector<PII> adjlist[15];
vector<int> path;
priority_queue<PIII,vector<PIII>,greater<PIII> > pq;

int dijkstra()
{
	int i,j;
	memset(par,-1,sizeof(par));
	for(i=1;i<=N;i++) dis[i]=INF;
	pq.push(mp(0,mp(source,-1)));
	
	while(!pq.empty())
	{
		int now=pq.top().se.fi;
		int from=pq.top().se.se;
		int cost=pq.top().fi;
		pq.pop();
		
		if(dis[now]==INF)
		{
			dis[now]=cost;
			par[now]=from;
			
			for(j=0;j<adjlist[now].size();j++)
			{
				int next=adjlist[now][j].fi;
				pq.push(mp(dis[now]+adjlist[now][j].se,mp(next,now)));
			}
		}
	}
	return(dis[dest]);
}

int main()
{
	i=0;
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		for(x=1;x<=N;x++)
		{
			adjlist[x].clear();
			scanf("%d",&y);
			while(y--)
			{
				scanf("%d %d",&z,&cost);
				adjlist[x].pb(mp(z,cost));
			}
		}
		scanf("%d %d",&source,&dest);
		
		ans=dijkstra();
		x=dest;
		do
		{
			path.pb(x);
			x=par[x];
		}while(par[x]!=-1); path.pb(source);
		
		printf("Case %d: Path =",++i);
		while(!path.empty())
		{
			printf(" %d",path.back());
			path.pop_back();
		}
		printf("; %d second delay\n",ans);
	}
	return 0;
}

