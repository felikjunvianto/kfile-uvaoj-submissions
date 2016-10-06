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
#define pi acos(-1.0)
#define eps 1e-9

using namespace std;

typedef struct
{
	int a,b;
	double cost;
} jalan;

jalan edge[5000];
int t,n,x,y,banyak;
pair<double,double> koor[110];
int par[110];

bool cf(jalan a,jalan b)
{
	if(floor(a.cost*1000)!=floor(b.cost*1000)) return(floor(a.cost*1000)<floor(b.cost*1000)); else
	if(a.a!=b.a) return(a.a<b.a); else
	return(a.b<b.b);
}

int find_par(int i)
{
	if(par[i]==-1) par[i]=i; else
	{
		int u=i;
		while(par[u]!=u) u=par[u];
		par[i]=u;
	}
	return(par[i]);
}

bool uni(int i,int j)
{
	if(find_par(i)!=find_par(j))
	{
		par[par[i]]=par[j];
		return false;
	} else return true;
}

double kruskal()
{
	int x,y,z;
	double total=0.0;
	memset(par,-1,sizeof(par));
	for(x=0;x<banyak;x++) if(!uni(edge[x].a,edge[x].b)) total+=edge[x].cost;
	return(total);
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(x=0;x<n;x++) scanf("%lf %lf",&koor[x].fi,&koor[x].se);
		banyak=-1;
		for(x=0;x<n-1;x++)
			for(y=x+1;y<n;y++)
			{
				banyak++;
				edge[banyak].a=x;
				edge[banyak].b=y;
				edge[banyak].cost=sqrt((koor[x].fi-koor[y].fi)*(koor[x].fi-koor[y].fi)+
								       (koor[x].se-koor[y].se)*(koor[x].se-koor[y].se));
			}
		sort(edge,edge+banyak+1,cf);
		printf("%.2f\n",kruskal());
		if(t>0) printf("\n");
	}
	return 0;
}

