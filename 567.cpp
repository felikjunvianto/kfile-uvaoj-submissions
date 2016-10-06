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

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>

using namespace std;

vector<int> adjlist[25];
bool visited[25];
int t,x,y,z,a,b,cost;
queue<PII> q;

int main()
{
	t=0;
	while(scanf("%d",&x)!=EOF)
	{
		for(a=1;a<=20;a++) adjlist[a].clear();
		for(a=1;a<20;a++)
		{
			if(a!=1) scanf("%d",&x);
			for(y=0;y<x;y++)
			{
				scanf("%d",&b);
				adjlist[a].pb(b);
				adjlist[b].pb(a);
			}
		}
		
		scanf("%d",&z);
		printf("Test Set #%d\n",++t);
		while(z--)
		{
			scanf("%d %d",&a,&b);
			memset(visited,false,sizeof(visited));
			visited[a]=true;
			q.push(mp(a,0));
			
			do
			{
				if(q.front().fi==b) cost=q.front().se; else
				for(x=0;x<adjlist[q.front().fi].size();x++) 
					if(!visited[adjlist[q.front().fi][x]])
					{
						visited[adjlist[q.front().fi][x]]=true;
						q.push(mp(adjlist[q.front().fi][x],q.front().se+1));
					}
				q.pop();
			}while(!q.empty());
			printf("%2d to %2d: %d\n",a,b,cost);
		}
		printf("\n");
	}
	return 0;
}

