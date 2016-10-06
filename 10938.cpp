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
	int tipe,node,jump;
} cell;

int N,Q,x,a,b;
vector<int> adjlist[5010];
vector<PII> edgelist;
queue<cell> q;
int dis[2][5010];

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		edgelist.clear();
		for(x=1;x<=N;x++) adjlist[x].clear();
		for(x=1;x<N;x++)
		{
			scanf("%d %d",&a,&b);
			adjlist[a].pb(b);
			adjlist[b].pb(a);
			edgelist.pb(mp(a,b));
		}
		
		scanf("%d",&Q);
		while(Q--)
		{
			scanf("%d %d",&a,&b);
			for(x=1;x<=N;x++) dis[0][x]=dis[1][x]=-1;
			dis[0][a]=dis[1][b]=0;
			q.push((cell){0,a,0});
			q.push((cell){1,b,0});
			
			while(!q.empty())
			{
				cell now =q.front();q.pop();
				for(int x=0;x<adjlist[now.node].size();x++)
				{
					int next = adjlist[now.node][x];
					if(dis[now.tipe][next]==-1)
					{
						dis[now.tipe][next]=now.jump+1;
						q.push((cell){now.tipe,next,now.jump+1});
					}
				}
			}
		
			int earlier = -1;
			for(x=1;x<=N;x++) if(dis[0][x]==dis[1][x])
				if((earlier==-1)||(dis[0][earlier]>dis[0][x])) earlier = x;
		
			if(earlier!=-1)
			{
				printf("The fleas meet at %d.\n",earlier);
				continue;
			}
			
			earlier = INF;
			int ans = INF;
			for(x=0;x<edgelist.size();x++)
				if(dis[0][edgelist[x].fi] == dis[1][edgelist[x].se])
				{
					int temp = min(max(dis[0][edgelist[x].fi],dis[1][edgelist[x].se]),
								   max(dis[1][edgelist[x].fi],dis[0][edgelist[x].se]));
		
					if(ans > temp)
					{
						ans = temp;
						earlier = x;
					}
				}
						
			a = edgelist[earlier].fi;
			b = edgelist[earlier].se;
			if(a>b) swap(a,b);
			printf("The fleas jump forever between %d and %d.\n",a,b);
		}
	}
	return 0;
}

