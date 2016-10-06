/*
	Algoritma : Straight-forward Edmond Karp's Max Flow implementation.
 */

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

int adjmat[111][111];
int s,t,edge,N,x,y,z,mf,f,i;
int path[111];
bool visited[111];

void augment(int now,int v)
{
	if(now==s) f=v; else if(path[now]!=-1)
	{
		augment(path[now],min(v,adjmat[path[now]][now]));
		adjmat[path[now]][now]-=f;
		adjmat[now][path[now]]+=f;
	}
}

int main()
{
	i=1;
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		scanf("%d %d %d",&s,&t,&edge);
		memset(adjmat,0,sizeof(adjmat));
		while(edge--)
		{
			scanf("%d %d %d",&x,&y,&z);
			adjmat[x][y]+=z, adjmat[y][x]+= z;
		}
		
		mf=0;
		while(1)
		{
			queue<int> q;
			memset(visited,false,sizeof(visited));
			memset(path,-1,sizeof(path));
			q.push(s),visited[s]=true;
			
			f=0;
			while(!q.empty())
			{
				int now=q.front();q.pop();
				if(now==t) break;
				
				for(x=1;x<=N;x++) if((adjmat[now][x])&&(!visited[x]))
				{
					visited[x]=true;
					q.push(x);
					path[x]=now;
				}
			}
			
			augment(t,INF);
			if(!f) break;
			mf+=f;
		}
		
		printf("Network %d\n",i++);
		printf("The bandwidth is %d.\n\n",mf);
	}
	return 0;
}

/* Implementasi dengan Dinic's

// algorithm: Dinic's algorithm (level graph and blocking flow)

#include <cstdio>
#include <cstdlib>
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
#include <set>

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

int N, S, T, E, a, b, c;
vector<int> adjlist[111];
int cap[111][111], flow[111][111];
int level[111], path[111];

bool buildLevelGraph(int &source, int &sink)
{
	memset(level, 0, sizeof(level));
	queue<int> q;
	q.push(source); level[source] = 1;
	
	while(!q.empty())
	{
		int now = q.front(); q.pop();
		for(int i = 0; i < adjlist[now].size(); i++)
		{
			int next = adjlist[now][i];
			if((cap[now][next] - flow[now][next] > 0 || flow[next][now] > 0) && !level[next])
			{
				q.push(next);
				level[next] = level[now] + 1;
			}
		}
	}
	
	return level[sink];
}

int findBlockingFlow(int &source, int &sink)
{
	bool visited[111];
	stack<int> s;
	int ret = 0;
	
	memset(visited, false, sizeof(visited));
	s.push(source);
	
	while(!s.empty())
	{
		int now = s.top();
		if(now != sink)
		{
			for(int i = 0; i < adjlist[now].size(); i++)
			{
				int next = adjlist[now][i];
				if(visited[next] || level[next] != level[now] + 1) continue;
				
				if(cap[now][next] - flow[now][next] > 0) { s.push(next); path[next] = now; } else
					if(flow[next][now] > 0) { s.push(next); path[next] = -now; };
			}
			
			if(s.top() == now) 
			{
				s.pop();
				visited[now] = true;
			}
		} 
		
		else
		{
			int f = INF, bottleneck;
			for(int cur = sink; cur != source; cur = abs(path[cur]))
			{
				if(path[cur] > 0) f = min(f, cap[path[cur]][cur] - flow[path[cur]][cur]);
					else f = min(f, flow[cur][-path[cur]]);
			}
			
			for(int cur = sink; cur != source; cur = abs(path[cur]))
			{
				if(path[cur] > 0) 
				{
					flow[path[cur]][cur] += f;
					if(cap[path[cur]][cur] - flow[path[cur]][cur] == 0) bottleneck = path[cur];
				} 
				
				else 
				{
					flow[cur][-path[cur]] -= f;
					if(!flow[cur][-path[cur]]) bottleneck = -path[cur];
				}
			}
			
			while(!s.empty() && s.top() != bottleneck) s.pop();
			ret += f;
		}
	}
	
	return ret;
}

int Dinic(int source, int sink)
{
	int maxflow = 0;
	while(buildLevelGraph(source, sink))
		maxflow += findBlockingFlow(source, sink);
		
	return maxflow;
}

int main()
{
	int t = 0;
	while(1)
	{
		scanf("%d", &N);
		if(!N) break;
		
		scanf("%d %d %d", &S, &T, &E);
		for(int i = 1; i <= N; i++) adjlist[i].clear();
		memset(cap, 0, sizeof(cap)); memset(flow, 0, sizeof(flow));
		
		while(E--)
		{
			scanf("%d %d %d", &a, &b, &c);
			if(cap[a][b] == 0)
			{
				adjlist[a].pb(b);
				adjlist[b].pb(a);
				cap[a][b] = cap[b][a] = c;
			} else 
			{
				cap[a][b] += c;
				cap[b][a] += c;
			}
		}
		
		printf("Network %d\nThe bandwidth is %d.\n\n", ++t, Dinic(S, T));
	}
	return 0;
}

*/