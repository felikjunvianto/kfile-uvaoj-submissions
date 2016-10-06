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

int E,N,x,y,z,ans;
bool exist[111][111];
vector<int> adjlist[111];
int adjmat[111][111];
int dis[111],path[111],maxflow;

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		for(x=1;x<=N;x++) adjlist[x].clear();
		memset(exist,false,sizeof(exist));
		scanf("%d",&E);
		while(E--)
		{
			scanf("%d %d %d",&x,&y,&z);
			exist[x][y]=exist[y][x]=true;
			adjmat[x][y]=adjmat[y][x]=z;
			adjlist[x].pb(y);
			adjlist[y].pb(x);
		}
		
		maxflow=ans=0;
		while(maxflow<2)
		{
			dis[1]=0;
			for(x=2;x<=N;x++) dis[x]=INF;
			memset(path,-1,sizeof(path));
			
			for(x=1;x<N;x++)
				for(y=1;y<=N;y++)
					for(z=0;z<adjlist[y].size();z++) 
					{	
						int next=adjlist[y][z];
						if(!exist[y][next]) continue;
						
						if(dis[y]+adjmat[y][next]<dis[next])
						{
							dis[next]=dis[y]+adjmat[y][next];
							path[next]=y;
						}
					}
					
			if(dis[N]==INF) break;
			maxflow++;
			
			int now=N;
			while(now!=1)
			{
				ans+=adjmat[path[now]][now];
				exist[path[now]][now]=false;
				
				adjmat[now][path[now]]=-adjmat[path[now]][now];
				adjmat[path[now]][now]=0;
				now=path[now];
			}
		}
		
		if(maxflow!=2) printf("Back to jail\n"); else printf("%d\n",ans);
	}
	return 0;
}

