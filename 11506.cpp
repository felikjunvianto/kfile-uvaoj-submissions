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

int N,E,x,y,z,f,mf;
int adjmat[111][111];
int path[111];
vector<int> adjlist[111];
bool visited[111];

void augment(int now,int v)
{
	if(now==1) f=v; else if(path[now]!=-1)
	{
		augment(path[now],min(v,adjmat[path[now]][now]));
		adjmat[path[now]][now]-=f;
		adjmat[now][path[now]]+=f;
	}
}

int main()
{
	while(1)
	{
		scanf("%d %d",&N,&E);
		if(N+E==0) break;
		
		memset(adjmat,0,sizeof(adjmat));
		for(x=1;x<=2*N;x++) adjlist[x].clear();
		
		adjlist[1].pb(1+N);adjlist[1+N].pb(1);
		adjmat[1][1+N]=INF;
		
		for(x=0;x<N-2;x++)
		{
			scanf("%d %d",&y,&z);
			adjlist[y].pb(y+N);
			adjlist[y+N].pb(y);
			adjmat[y][y+N]=adjmat[y+N][y]=z;
		}
		
		while(E--)
		{
			scanf("%d %d %d",&x,&y,&z);
			adjlist[x+N].pb(y);adjlist[y].pb(x+N);
			adjlist[y+N].pb(x);adjlist[x].pb(y+N);
			adjmat[x+N][y]=adjmat[y+N][x]=z;
		}
		
		mf=0;
		while(1)
		{
			queue<int> q;
			memset(visited,false,sizeof(visited));
			memset(path,-1,sizeof(path));
			visited[1]=true;
			q.push(1);
			
			while(!q.empty())
			{
				int now = q.front();q.pop();
				for(y=0;y<adjlist[now].size();y++)
				{
					int next = adjlist[now][y];
					if((!visited[next])&&(adjmat[now][next]!=0))
					{
						visited[next]=true;
						path[next]=now;
						q.push(next);
					}
				}
			}
			
			f=0;
			augment(N,INF);
			if(!f) break;
			mf+=f;
		}
		printf("%d\n",mf);
	}
	return 0;
}

