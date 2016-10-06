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

int s=0,t=499,mf,f,T,N,x,y,z,item;
int adjmat[500][500],path[500];
bool visited[500],awal;
char msk[40];
vector<int> adjlist[500];
map<string,int> idx;

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
	awal=true;
	scanf("%d",&T);
	while(T--)
	{
		memset(adjmat,0,sizeof(adjmat));
		for(x=0;x<500;x++) adjlist[x].clear();
		idx.clear();z=1;
		
		scanf("%d",&N);
		while(N--)
		{
			scanf("%s",msk);
			if(idx.find(msk)==idx.end()) idx[msk]=z++;
			x=idx[msk];
			
			adjmat[x][t]=1;
			adjlist[t].pb(x);
			adjlist[x].pb(t);
		}
		
		scanf("%d",&N);item=N;
		while(N--)
		{
			scanf("%s",msk);if(idx.find(msk)==idx.end()) idx[msk]=z++;x=idx[msk];
			scanf("%s",msk);if(idx.find(msk)==idx.end()) idx[msk]=z++;y=idx[msk];
			adjmat[s][x]=adjmat[x][y]=1;
			adjlist[s].pb(x);adjlist[x].pb(s);
			adjlist[y].pb(x);adjlist[x].pb(y);
		}
		
		scanf("%d",&N);
		while(N--)
		{
			scanf("%s",msk);if(idx.find(msk)==idx.end()) idx[msk]=z++;x=idx[msk];
			scanf("%s",msk);if(idx.find(msk)==idx.end()) idx[msk]=z++;y=idx[msk];
			adjmat[x][y]=INF;
			adjlist[x].pb(y);
			adjlist[y].pb(x);
		}
		
		mf=0;
		while(1)
		{
			memset(visited,false,sizeof(visited));
			visited[s]=true;
			queue<int> q;
			q.push(s);
			
			while(!q.empty())
			{
				int now=q.front();q.pop();
				for(x=0;x<adjlist[now].size();x++)
				{
					int next=adjlist[now][x];
					if((!visited[next])&&(adjmat[now][next]!=0))
					{
						visited[next]=true;
						path[next]=now;
						q.push(next);
					}
				}
			}
			
			f=0;
			augment(t,INF);
			if(!f) break;
			mf+=f;
		}
		
		if(!awal) printf("\n");
		awal=false;
		printf("%d\n",item-mf);
	}
	return 0;
}

