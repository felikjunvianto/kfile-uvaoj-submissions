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

typedef struct
{
	int a,b,c;
} edge;

int T,V,E,a,b,c,now;
vector<edge> edgelist;
char kota1[20],kota2[20];
int par[2010];
map<string, int> idx;

bool cf(edge i, edge j)
{
	return i.c<j.c;
}

int find(int i)
{
	if(par[i]==-1) par[i]=i; else
	{
		int ti = i;
		while(ti!=par[ti]) ti=par[ti];
		par[i] = ti;
	} return par[i];
}

bool isunion(int i, int j)
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
	sort(edgelist.begin(),edgelist.end(),cf);
	
	int chosen=0,tot = 0;
	for(int i = 0;i<edgelist.size();i++)
		if(!isunion(edgelist[i].a,edgelist[i].b))
		{
			tot+=edgelist[i].c;
			chosen++;
			if(chosen==V-1) break;
		}
	return tot;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&V);
		scanf("%d",&E);
		
		idx.clear();
		edgelist.clear();
		now = 0;
		while(E--)
		{
			scanf("%s %s %d",kota1,kota2,&c);
			if(idx.find(kota1)==idx.end()) idx[kota1] = now++;
			if(idx.find(kota2)==idx.end()) idx[kota2] = now++;
			a = idx[kota1];
			b = idx[kota2];
			
			edgelist.pb((edge){a,b,c});
		}
		
		printf("%d\n",kruskal());
		if(T) printf("\n");
	}
	return 0;
}

