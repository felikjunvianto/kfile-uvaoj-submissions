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

using namespace std;

int N,K,M;
vector<pair<int,PII> > edgelist;
int a,b,cost,total,z,x;
int par[1000010];

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
		return(false);
	}return(true);
}

int kruskal()
{
	memset(par,-1,sizeof(par));
	sort(edgelist.begin(),edgelist.end());
	
	int num=0,mst=0;
	for(int x=0;x<edgelist.size();x++)
		if(!is_union(edgelist[x].se.fi,edgelist[x].se.se))
		{
			mst+=edgelist[x].fi;
			num++;
			if(num+1==N) break;
		}
	return(mst);
}

int main()
{
	z=0;
	while(scanf("%d",&N)!=EOF)
	{
		edgelist.clear();
		total=0;
		
		for(x=1;x<N;x++)
		{
			scanf("%d %d %d",&a,&b,&cost);
			total+=cost;
			edgelist.pb(mp(cost,mp(a,b)));
		}
		
		scanf("%d",&K);
		for(x=0;x<K;x++)
		{
			scanf("%d %d %d",&a,&b,&cost);
			edgelist.pb(mp(cost,mp(a,b)));
		}
		
		scanf("%d",&M);
		while(M--) scanf("%d %d %d",&a,&b,&cost);
		
		z++;
		if(z>1) printf("\n");
		printf("%d\n%d\n",total,kruskal());
	}
	return 0;
}

