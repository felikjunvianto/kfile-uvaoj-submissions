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
} e;

int T,N,x,y,z;
int par[510];
vector<string> node;
vector<e> edge;
char msk[10];

bool cf(e i,e j)
{
	if(i.c!=j.c) return(i.c<j.c);
	return(i.a<j.a);
}

int find(int i)
{
	if(par[i]==-1) par[i]=i; else
	{
		int ti=i;
		while(ti!=par[ti]) ti=par[ti];
		par[i]=ti;
	} return(par[i]);
}

bool setunion(int i,int j)
{
	if(find(i)!=find(j))
	{
		par[par[i]]=par[j];
		return(false);
	} return(true);
}

int kruskal()
{
	memset(par,-1,sizeof(par));
	int sum=0,now=0;
	for(int i=0;i<edge.size();i++) if(!setunion(edge[i].a,edge[i].b))
	{
		sum+=edge[i].c;
		now++;
		if(now+1==(int)edge.size()) break;
	}
	return(sum);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		edge.clear();
		node.clear();node.pb("0000");
		
		while(N--)
		{
			scanf("%s",msk);
			node.pb(msk);
		}
		
		int awal=INF;
		for(x=0;x+1<node.size();x++)
			for(y=x+1;y<node.size();y++)
			{
				int cost=0;
				for(z=0;z<5;z++)
				{
					int dis = abs((int)node[x][z]-(int)node[y][z]);
					cost+=min(dis,10-dis);
				}
				
				if(!x) awal=min(awal,cost);else edge.pb((e){x,y,cost});
			}
		sort(edge.begin(),edge.end(),cf);
		
		printf("%d\n",kruskal()+awal);
	}
	return 0;
}

