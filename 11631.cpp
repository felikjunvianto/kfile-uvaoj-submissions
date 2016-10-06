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

int node,edge,x,total;
int par[200100];
pair<int,PII> edgelist[200100];

int find(int i)
{
	if(par[i]==-1) par[i]=i; else
	{
		int ti=i;
		while(par[ti]!=ti) ti=par[ti];
		par[i]=ti;
	}
	return(par[i]);
}

bool is_union(int a,int b)
{
	if(find(a)!=find(b))
	{
		par[par[a]]=par[b];
		return false;
	}
	return true;
}

int kruskal()
{
	memset(par,-1,sizeof(par));
	sort(edgelist,edgelist+edge);
	int cost=0;
	for(int x=0;x<edge;x++) if(!is_union(edgelist[x].se.fi,edgelist[x].se.se))
		cost+=edgelist[x].fi;
	return(cost);
}

int main()
{
	do
	{
		scanf("%d %d",&node,&edge);
		if(node+edge==0) break;
		
		total=0;
		for(x=0;x<edge;x++) 
		{
			scanf("%d %d %d",&edgelist[x].se.fi,&edgelist[x].se.se,&edgelist[x].fi);
			total+=edgelist[x].fi;
		}
		
		printf("%d\n",total-kruskal());
	}while(node+edge!=0);
	return 0;
}

