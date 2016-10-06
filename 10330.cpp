#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define INF 1000000000
#define eps 1e-9
#define PII pair<int,int> 

using namespace std;

int S,F,N,E,B,D;
int x,y,z,mf,f;
int adjmat[250][250],par[250];
bool visited[250];
vector<int> adjlist[250];
queue<int> q;

void augment(int now,int v)
{
	if(now==S) f=v; else if(par[now]!=-1)
	{
		augment(par[now],min(v,adjmat[par[now]][now]));
		adjmat[par[now]][now]-=f;
		adjmat[now][par[now]]+=f;
	}
}

int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		S=0;
		F=2*N+1;
		memset(adjmat,0,sizeof(adjmat));
		for(x=S;x<=F;x++) adjlist[x].clear();
		
		for(x=1;x<=N;x++)
		{
			scanf("%d",&y);
			adjlist[x].pb(x+N);
			adjlist[x+N].pb(x);
			adjmat[x][x+N]=y;
		}
		
		scanf("%d",&E);
		while(E--)
		{
			scanf("%d %d %d",&x,&y,&z);
			adjlist[x+N].pb(y);adjlist[y].pb(x+N);
			adjlist[y+N].pb(x);adjlist[x].pb(y+N);
			adjmat[x+N][y]=z;
		}
		
		scanf("%d %d",&B,&D);
		while(B--)
		{
			scanf("%d",&x);
			adjlist[S].pb(x);
			adjlist[x+N].pb(S);
			adjmat[S][x]=INF;
		}
		
		while(D--)
		{
			scanf("%d",&x);
			adjlist[F].pb(x);
			adjlist[x+N].pb(F);
			adjmat[x+N][F]=INF;
		}		
		
		mf=0;
		do
		{
			f=0;
			memset(visited,false,sizeof(visited));
			memset(par,-1,sizeof(par));
			q.push(S);
			visited[S]=true;
			
			while(!q.empty())
			{
				x=q.front();q.pop();
				for(y=0;y<adjlist[x].size();y++)
				{
					z=adjlist[x][y];
					if(!visited[z] && adjmat[x][z]!=0)
					{
						visited[z]=true;	
						par[z]=x;
						q.push(z);
					}
				}
			}
			
			augment(F,INF);
			mf+=f;
		}while(f);
		printf("%d\n",mf);
	}
	return 0;
}

