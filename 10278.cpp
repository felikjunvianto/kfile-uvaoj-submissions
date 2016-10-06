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

int T,F,N,x,y,z,len;
vector<int> station;
vector<PII> adjlist[555];
bool built[555];
char msk[30];
int dis[555];

int dijkstra(int newstat)
{
	int i;
	for(i=1;i<=N;i++) dis[i]=-1;
	
	priority_queue<PII,vector<PII>,greater<PII> > pq;
	for(i=0;i<station.size();i++) pq.push(mp(0,station[i]));
	pq.push(mp(0,newstat));
	
	while(!pq.empty())
	{
		PII now = pq.top();pq.pop();
		if(dis[now.se]==-1)
		{
			dis[now.se]=now.fi;
			for(i=0;i<adjlist[now.se].size();i++)
			{
				int next=adjlist[now.se][i].fi;
				if(dis[next]==-1) pq.push(mp(dis[now.se]+adjlist[now.se][i].se,next));
			}
		}
	}
	
	int greatest = 0;
	for(i=1;i<=N;i++) greatest = max(greatest,dis[i]);
	return(greatest);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&F,&N);
		
		station.clear();
		for(x=1;x<=N;x++) 
		{
			adjlist[x].clear();
			built[x]=false;
		}
		
		while(F--)
		{
			scanf("%d",&x);
			if(built[x]) continue;
			built[x]=true;
			station.pb(x);
		} getchar();
		
		while(gets(msk))
		{
			len=strlen(msk);
			if(!len) break;
			
			int a=0,b=0,cost=0;
			for(x=0;x<len;x++) if(msk[x]==' ') break;
			for(y=0;y<x;y++) a=a*10+(msk[y]-'0');
			
			for(x=y+1;x<len;x++) if(msk[x]==' ') break;
			for(z=y+1;z<x;z++) b=b*10+(msk[z]-'0');
			for(z=x+1;z<len;z++) cost=cost*10+(msk[z]-'0');
			
			adjlist[a].pb(mp(b,cost));
			adjlist[b].pb(mp(a,cost));
		}
		
		int ans=1,temp=INF;
		for(x=1;x<=N;x++) if(!built[x])
		{
			y=dijkstra(x);
			if(y<temp)
			{
				ans=x;
				temp=y;
			}
		}
		
		printf("%d\n",ans);
		if(T) printf("\n");
	}
	return 0;
}

