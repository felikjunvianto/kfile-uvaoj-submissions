/*
	Algoritma: Alternate-DFS (bipartite matching).
 */

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

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>
#define LL long long

using namespace std;

int T, B, N, x;
vector<int> adjlist[1010];
int par[1010];
bool visited[505];

int augment(int now)
{
	if(visited[now]) return 0;
	visited[now] = true;
	
	for(int i = 0; i < adjlist[now].size(); i++)
	{
		int next = adjlist[now][i];
		if(par[next] == -1 || augment(par[next]))
		{
			par[next] = now;
			return 1;
		}
	}
	
	return 0;
}

int main()
{
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d %d", &B, &N);
		for(int i = 0; i < N + B; i++) adjlist[i].clear();
		
		for(int a = 0; a < B; a++) 
			for(int b = 0; b < N; b++)
			{
				scanf("%d", &x);
				if(x) 
				{
					adjlist[a].pb(b + B);
					adjlist[b + B].pb(a);
				}
			}
			
		int ans = 0;
		memset(par, -1, sizeof(par));
		for(int i = 0; i < B; i++)
		{
			memset(visited, false, sizeof(visited));
			ans += augment(i);
		}
		
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", t, ans);
	}
	return 0;
}

/* Alternatif dengan Dinic's Algorithm 

algorithm: Dinic's algorithm (level graph and blocking flow)

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

int T, nuts, bolts;
vector<int> adjlist[1010];
int cap[1010][1010], flow[1010][1010];
int path[1010], level[1010];

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
	bool visited[1010];
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
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d %d", &bolts, &nuts);
		for(int i = 1; i <= nuts + bolts + 2; i++) adjlist[i].clear();
		memset(cap, 0, sizeof(cap)); memset(flow, 0, sizeof(flow));
		
		for(int i = 2; i <= bolts + 1; i++)
			for(int j = 2 + bolts; j <= nuts + 1 + bolts; j++)
			{
				scanf("%d", &cap[i][j]);
				if(cap[i][j] == 1) 
				{
					adjlist[i].pb(j);
					adjlist[j].pb(i);
				}
			}
			
		for(int i = 2; i <= bolts + 1; i++)
		{
			adjlist[1].pb(i);
			adjlist[i].pb(1);
			cap[1][i] = 1;
		}
		
		int sink = bolts + nuts + 2;
		for(int i = 2 + bolts; i <= nuts + 1 + bolts; i++)
		{
			adjlist[i].pb(sink);
			adjlist[sink].pb(i);
			cap[i][sink] = 1;
		}
		
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", t, Dinic(1, nuts + bolts + 2));
	}
	return 0;
}*/

