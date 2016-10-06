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

int N,T,x,y,a,b,node;
int grid[40][40];
vector<int> adjlist[40],stek;
bool cycle[40],visited[40];

void cek(int now)
{
	bool ada=false;
	int i,j;
	for(i=0;i<stek.size();i++) if((stek[i]==now)&&(i+1<(int)stek.size()))
	{
		ada=true;
		break;
	}
	
	if(ada) for(j=i;j<stek.size();j++) cycle[stek[j]]=true; else
		for(i=0;i<adjlist[now].size();i++)
		{
			j=adjlist[now][i];
			stek.pb(j);
			cek(j);
			stek.pop_back();
		}
}

void dfs(int now,int move,bool sirku)
{
	if(now==y)
	{
		if(sirku) grid[x][y]=-1; 
			else if((grid[x][y]!=-1)&&(move)) grid[x][y]++;
	} else
	
	for(int i=0;i<adjlist[now].size();i++)
	{
		int next=adjlist[now][i];
		if(!visited[next])
		{
			visited[next]=true;
			dfs(next,move+1,sirku|cycle[next]);
			visited[next]=false;
		}
	}
}

int main()
{
	T=0;
	memset(visited,false,sizeof(visited));
	while(scanf("%d",&N)!=EOF)
	{
		for(x=0;x<40;x++) adjlist[x].clear();
		node=-1;
		for(x=0;x<N;x++) 
		{
			scanf("%d %d",&a,&b);
			node=max(node,max(a,b));
			adjlist[a].pb(b);
		}
		
		memset(cycle,false,sizeof(cycle));
		for(x=0;x<=node;x++) if(!cycle[x]) 
		{
			stek.pb(x);
			cek(x);
			stek.pop_back();
		}
		
		memset(grid,0,sizeof(grid));
		for(x=0;x<=node;x++)
		{
			visited[x]=true;
			for(y=0;y<=node;y++) dfs(x,0,cycle[x]);
			visited[x]=false;
		}
			
		printf("matrix for city %d\n",T++);
		for(x=0;x<=node;x++)
			for(y=0;y<=node;y++) printf("%d%c",grid[x][y],y==node?'\n':' ');
	}
	return 0;
}

