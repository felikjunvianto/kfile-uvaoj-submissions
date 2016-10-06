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

int G,H,x,y,z,mf,f;
int S,T;
double s,v;
vector<int> adjlist[205];
int path[205],adjmat[205][205];
pair<double,double> koor[205];
bool visited[205];

void augment(int now)
{
	if(now==S) f = 1; else if(path[now]!=-1)
	{
		augment(path[now]);
		adjmat[path[now]][now]-=f;
		adjmat[now][path[now]]+=f;
	}
}

int main()
{
	while(scanf("%d %d %lf %lf",&G,&H,&s,&v)!=EOF)
	{
		S = 0;
		T = G+H+1;
		for(x=S;x<=T;x++) 
		{
			adjlist[x].clear();
			for(y=S;y<=T;y++) adjmat[x][y]=0;
		}
		
		for(x=1;x<=G;x++)
		{
			adjlist[S].pb(x);
			adjlist[x].pb(S);
			adjmat[S][x]=1;
		}
		
		for(x=G+1;x<=G+H;x++)
		{
			adjlist[T].pb(x);
			adjlist[x].pb(T);
			adjmat[x][T]=1;
		}
		
		for(x=1;x<=G;x++) scanf("%lf %lf",&koor[x].fi,&koor[x].se);
		for(x=1;x<=H;x++) scanf("%lf %lf",&koor[x+G].fi,&koor[x+G].se);
		
		for(x=1;x<=G;x++)
			for(y=1;y<=H;y++)
			{
				double dis = sqrt(pow(koor[x].fi-koor[y+G].fi,2)+pow(koor[x].se-koor[y+G].se,2));
				if(s*v-dis>=eps)
				{
					adjlist[x].pb(y+G);
					adjlist[y+G].pb(x);
					adjmat[x][y+G]=1;
				}
			}
			
		mf = 0;
		while(1)
		{
			for(x=S;x<=T;x++)
			{
				path[x]=-1;
				visited[x]=false;
			}
			
			queue<int> q;
			visited[S]=true;
			q.push(S);
			
			while(!q.empty())
			{
				int now =q.front();q.pop();
				for(x = 0;x<adjlist[now].size();x++)
				{
					int next= adjlist[now][x];
					if((!visited[next])&&(adjmat[now][next]!=0))
					{
						path[next]=now;
						visited[next]=true;
						q.push(next);
					}
				}
			}
			
			f = 0;
			augment(T);
			if(!f) break;
			mf+=f;
		}
		printf("%d\n",G-mf);
	}
	return 0;
}

