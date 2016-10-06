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

int lift,dest,x,y,len;
int t[6];
vector<pair<PII,int> > adjlist[6][111];
bool visit[6][111];
char msk[300];

int dijkstra()
{
	int i,dis[6][111];
	memset(dis,-1,sizeof(dis));
	priority_queue<pair<int,PII>,vector<pair<int,PII> >,greater<pair<int,PII> > > pq;
	
	for(i=1;i<=lift;i++) if(visit[i][0]) pq.push(mp(0,mp(i,0)));
		
	while(!pq.empty())
	{
		pair<int,PII> now = pq.top();pq.pop();
		if(dis[now.se.fi][now.se.se]==-1)
		{
			dis[now.se.fi][now.se.se]=now.fi;
			for(i=0;i<adjlist[now.se.fi][now.se.se].size();i++)
			{
				PII next = mp(adjlist[now.se.fi][now.se.se][i].fi.fi,adjlist[now.se.fi][now.se.se][i].fi.se);
				if(dis[next.fi][next.se]==-1)
					pq.push(mp(now.fi+adjlist[now.se.fi][now.se.se][i].se,mp(next.fi,next.se)));
			}
		}
	}
	
	int ret = INF;
	for(i=1;i<=lift;i++) 
		if(dis[i][dest]!=-1) ret = min(ret,dis[i][dest]);
		
	return(ret);
}

int main()
{
	while(scanf("%d %d",&lift,&dest)!=EOF)
	{
		for(x=1;x<=lift;x++) 
		{
			scanf("%d",&t[x]);
			for(y=0;y<=99;y++) adjlist[x][y].clear();
		} getchar();
		
		memset(visit,false,sizeof(visit));
		for(x=1;x<=lift;x++)
		{
			gets(msk);len=strlen(msk);
			int now = 0;
			for(y=0;y<=len;y++) if((msk[y]==' ')||(msk[y]=='\0'))
			{
				visit[x][now]=true;
				now = 0;
			} else now = now*10+(msk[y]-'0');
		}
		
		for(x=1;x<=lift;x++)
			for(int now = 0;now<=99;now++) if(visit[x][now])
			{
				for(y=1;y<=lift;y++) if((y!=x)&&(visit[y][now]))
					adjlist[x][now].pb(mp(mp(y,now),60));
					
				for(int next = 0;next<=99;next++) if((visit[x][next])&&(next!=now))
					adjlist[x][now].pb(mp(mp(x,next),abs(next-now)*t[x]));
			}
			
		int ans = dijkstra();
		if(ans==INF) printf("IMPOSSIBLE\n"); else printf("%d\n",ans);
	}
	return 0;
}

