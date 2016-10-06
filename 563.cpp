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

int dx[]={ 1, 0,-1, 0};
int dy[]={ 0, 1, 0,-1};

int T,B,N,bawah,samping;
vector<int> adjlist[5010];
int adjmat[5010][5010];
int path[5010];
int s,t,x,y,z,f;
bool visited[5010];

void augment(int now)
{
	if(now==s) f=1; else if(path[now]!=-1)
	{
		augment(path[now]);
		adjmat[path[now]][now]-=f;
		adjmat[now][path[now]]+=f;
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&samping,&bawah,&B);
		N=samping*bawah;
		s=0,t=2*N+1;
		for(x=0;x<=t;x++) 
		{
			adjlist[x].clear();
			for(y=0;y<=t;y++) adjmat[x][y]=0;
		}
		
		for(x=1;x<=samping;x++)
			for(y=1;y<=bawah;y++)
			{
				int now = (y-1)*samping+x;
				adjlist[now].pb(N+now);
				adjlist[N+now].pb(now);
				adjmat[now][N+now] = adjmat[N+now][now] = 1;
				
				for(z=0;z<4;z++)
				{
					int sx=x+dx[z],sy=y+dy[z];
					if((!sx)||(!sy)||(sx>samping)||(sy>bawah))
					{
						adjlist[t].pb(now);
						adjlist[N+now].pb(t);
						adjmat[t][now]=adjmat[now+N][t]=1;
					} else
					
					{
						int next = (sy-1)*samping+sx;
						adjlist[N+now].pb(next);adjlist[next].pb(N+now);
						adjlist[N+next].pb(now);adjlist[now].pb(N+next);
						adjmat[N+now][next] = adjmat[N+next][now] = 1;
					}
				}
			}
			
		for(int i=0;i<B;i++)
		{
			scanf("%d %d",&x,&y);
			z=(y-1)*samping+x;
			adjlist[s].pb(z);
			adjlist[N+z].pb(s);
			adjmat[s][z]=adjmat[N+z][s]=1;
		}
		
		int mf = 0;
		while(1)
		{
			queue<int> q;
			for(x=0;x<=t;x++)
			{
				visited[x]=false;
				path[x]=-1;
			}
			visited[s]=true;
			q.push(s);
			
			while(!q.empty())
			{
				int now = q.front();q.pop();
				
				for(x=0;x<adjlist[now].size();x++)
				{
					int next=adjlist[now][x];
					if((!visited[next])&&(adjmat[now][next]>0))
					{
						visited[next]=true;
						path[next]=now;
						q.push(next);
					}
				}
			}
			
			f = 0;
			augment(t);
			if(!f) break;
			mf+=f;
		}
		
		printf("%s\n",mf==B?"possible":"not possible");
	}
	return 0;
}

