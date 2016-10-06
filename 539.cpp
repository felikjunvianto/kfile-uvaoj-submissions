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

int V,E,x,y,z,ans;
vector<int> adjlist[30];
bool exist[30][30];

void traverse(int now,int temp)
{
	for(int i=0;i<adjlist[now].size();i++)
	{
		int next=adjlist[now][i];
		if(exist[now][next])
		{
			exist[now][next]=exist[next][now]=false;
			traverse(next,temp+1);
			exist[now][next]=exist[next][now]=true;
		}
	}
	ans=max(ans,temp);
}

int main()
{
	while(1)
	{
		scanf("%d %d",&V,&E);
		if(!V && !E) break;
		
		//reset
		for(x=0;x<V;x++)
		{
			adjlist[x].clear();
			for(y=0;y<V;y++) exist[x][y]=false;
		}
		
		while(E--)
		{
			scanf("%d %d",&x,&y);
			adjlist[x].pb(y);
			adjlist[y].pb(x);
			exist[x][y]=exist[y][x]=true;
		}
		
		ans=0;
		for(x=0;x<V;x++) traverse(x,0);
		printf("%d\n",ans);
	}
	return 0;
}

