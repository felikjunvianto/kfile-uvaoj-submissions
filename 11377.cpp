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

int T,i,x,a,b,N,E,K,Q;
bool airport[2020];
vector<int> adjlist[2020];

int dijkstra(int S,int D)
{
	if(S==D) return 0;
	int i,dis[N+1];
	memset(dis,-1,sizeof(dis));
	priority_queue<PII,vector<PII>,greater<PII> > pq;
	
	pq.push(mp(airport[S]?0:1,S));
	while(!pq.empty())
	{
		PII now = pq.top();pq.pop();
		if(dis[now.se]==-1)
		{
			dis[now.se]=now.fi;
			for(i=0;i<adjlist[now.se].size();i++)
			{
				int next =adjlist[now.se][i];
				if(dis[next]==-1)
				{
					int tambah = airport[next]?0:1;
					pq.push(mp(now.fi+tambah,next));
				}
			}
		}
	}
	return(dis[D]);
}

int main()
{
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d %d",&N,&E,&K);
		for(x=1;x<=N;x++) 
		{
			airport[x]=false;
			adjlist[x].clear();
		}
		
		while(K--)
		{
			scanf("%d",&x);
			airport[x]=true;
		}
		
		while(E--)
		{
			scanf("%d %d",&a,&b);
			adjlist[a].pb(b);
			adjlist[b].pb(a);
		}
		
		scanf("%d",&Q);
		printf("Case %d:\n",i);
		while(Q--)
		{
			scanf("%d %d",&a,&b);
			printf("%d\n",dijkstra(a,b));
		}
		printf("\n");
	}
	return 0;
}

