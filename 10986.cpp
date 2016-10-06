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

int T,N,E,S,D;
int a,b,cost,x;
vector<PII> adjlist[20010];

int dijkstra()
{
	int m,dis[20010];
	for(m=0;m<N;m++) dis[m]=-1;
	priority_queue<PII,vector<PII>,greater<PII> > pq;
	pq.push(mp(0,S));
	
	while(!pq.empty())
	{
		PII now = pq.top();pq.pop();
		if(dis[now.se]==-1)
		{
			dis[now.se]=now.fi;
			for(m=0;m<adjlist[now.se].size();m++)
			{
				int next = adjlist[now.se][m].fi;
				if(dis[next]==-1) pq.push(mp(now.fi+adjlist[now.se][m].se,next));
			}
		}
	}
	return(dis[D]);
}

int main()
{
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d %d %d %d",&N,&E,&S,&D);
		for(x=0;x<N;x++) adjlist[x].clear();
		while(E--)
		{
			scanf("%d %d %d",&a,&b,&cost);
			adjlist[a].pb(mp(b,cost));
			adjlist[b].pb(mp(a,cost));
		}
		
		int ans=dijkstra();
		printf("Case #%d: ",i);
		if(ans==-1) printf("unreachable\n"); else printf("%d\n",ans);
	}
	return 0;
}

