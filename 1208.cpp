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
} e;

int T,N,x,y,z;
int par[30];
char dummy[5];
vector<e> edge,ans;

bool cf(e i,e j)
{
	if(i.cost!=j.cost) return(i.cost<j.cost);
	return(i.a<j.a);
}

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

bool setunion(int i,int j)
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
	ans.clear();
	int i,tot=0;
	
	for(i=0;i<edge.size();i++)
		if(!setunion(edge[i].a,edge[i].b))
		{
			ans.pb(edge[i]);
			tot++;
			if(tot+1==N) break;
		}
}

int main()
{
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&N);
		edge.clear();
		for(x=0;x<N;x++)
			for(y=0;y<N;y++)
			{
				scanf("%d",&z);
				if((x<y)&&(z)) edge.pb((e){x,y,z});
				if(y+1<N) scanf("%s",dummy);
			}
			
		sort(edge.begin(),edge.end(),cf);
		kruskal();
		
		printf("Case %d:\n",i);
		for(x=0;x<ans.size();x++) printf("%c-%c %d\n",ans[x].a+'A',ans[x].b+'A',ans[x].cost);
	}
	return 0;
}

