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
#define pi 2*acos(0.0)
#define PII pair<int,int> 

using namespace std;

typedef struct
{
	int a,b,cost;
} edge;

int T,V,E,x,a,b,c,tot;
int par[10010];
vector<edge> edgeList;

bool cf(edge i,edge j)
{
	return(i.cost>j.cost);
}

int find(int i)
{
	if(par[i]==-1) par[i]=i; else
	{
		int ti = i;
		while(par[ti]!=ti) ti=par[ti];
		par[i]=ti;
	} return par[i];
}

bool is_union(int i,int j)
{
	if(find(i)!=find(j))
	{
		par[par[i]]=par[j];
		return false;
	} else return true;
}

int kruskal()
{
	memset(par,-1,sizeof(par));
	sort(edgeList.begin(),edgeList.end(),cf);
	
	int chosen=0,ret=0;
	for(int i = 0;i<edgeList.size();i++)
		if(!is_union(edgeList[i].a,edgeList[i].b)) 
		{
			ret+=edgeList[i].cost;
			chosen++;
			if(chosen+1==V) break;
		}
	
	return ret;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&V,&E);
		edgeList.clear();
		tot=0;
		
		while(E--)
		{
			scanf("%d %d %d",&a,&b,&c);
			edgeList.pb((edge){a,b,c});
			tot+=c;
		}
		printf("%d\n",tot-kruskal());
	}
	
	return 0;
}

