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
	int a,b,cost;
} jalan;

int T,N,M,A,x,y,z,i;
int par[10010];
int airport,total;
vector<jalan> edge;

int find(int i)
{
	if(par[i]==-1) par[i]=i; else
	{
		int ti=i;
		while(ti!=par[ti]) ti=par[ti];
		par[i]=ti;
	} return(par[i]);
}

bool unionset(int i,int j)
{
	if(find(i)!=find(j))
	{
		par[par[i]]=par[j];
		return(false);
	} return(true);
}

void kruskal()
{
	memset(par,-1,sizeof(par));
	int i,now=0;
	for(i=0;i<edge.size();i++) if(!unionset(edge[i].a,edge[i].b))
	{
		now++;
		if(!edge[i].a) airport++;
		total+=edge[i].cost;
		if(now==N) break;
	}
}

bool cf(jalan i,jalan j)
{
	if(i.cost!=j.cost) return(i.cost<j.cost);
	return(i.a<j.a);
}

int main()
{
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		edge.clear();
		scanf("%d %d %d",&N,&M,&A);
		for(x=1;x<=N;x++) edge.pb((jalan){0,x,A});
		
		while(M--)
		{
			scanf("%d %d %d",&x,&y,&z);
			if(x>y) swap(x,y);
			edge.pb((jalan){x,y,z});
		}
		sort(edge.begin(),edge.end(),cf);
		
		airport=total=0;
		kruskal();
		
		printf("Case #%d: %d %d\n",i,total,airport);
	}
	return 0;
}

