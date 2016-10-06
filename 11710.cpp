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

using namespace std;

map<string,int> kode;
pair<int,PII> elist[80000];
int par[500];
int edge,node,x,cost;
char satu[15],dua[15];
bool terhubung;

int find(int i)
{
	if(par[i]==-1) par[i]=i; else
	{
		int ti=i;
		while(ti!=par[ti]) ti=par[ti];
		par[i]=ti;
	}
	return(par[i]);
}

bool is_union(int i,int j)
{
	if(find(i)!=find(j))
	{
		par[par[i]]=par[j];
		return false;
	}
	return true;
}

int kruskal()
{
	memset(par,-1,sizeof(par));
	sort(elist,elist+edge);
	int total=0;
	for(int x=0;x<edge;x++) if(!is_union(elist[x].se.fi,elist[x].se.se))
		total+=elist[x].fi;
	return(total);
}

int main()
{
	do
	{
		scanf("%d %d",&node,&edge);
		if(node+edge==0) break;
		
		kode.clear();
		for(x=0;x<node;x++)
		{
			scanf("%s",satu);
			kode[satu]=x;
		}
		
		for(x=0;x<edge;x++)
		{
			scanf("%s %s %d",satu,dua,&elist[x].fi);
			elist[x].se.fi=kode[satu];
			elist[x].se.se=kode[dua];
		}
		scanf("%s",satu);
		
		cost=kruskal();
		terhubung=true;
		for(x=0;x<node;x++) if(find(x)!=find(0))
		{
			terhubung=false;
			break;
		}
		
		if(!terhubung) printf("Impossible\n"); else printf("%d\n",cost);
	}while(node+edge!=0);
	return 0;
}

