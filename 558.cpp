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

int T,V,E;
int x,y,z;
int dis[1010];
vector<PII> adjlist[1010];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&V,&E);
		for(x=0;x<V;x++) 
		{
			adjlist[x].clear();
			dis[x]=INF;
		}
		dis[0]=0;
		
		while(E--)
		{
			scanf("%d %d %d",&x,&y,&z);
			adjlist[x].pb(mp(y,z));
		}
		
		for(x=0;x<V-1;x++)
			for(z=0;z<V;z++)
				for(y=0;y<adjlist[z].size();y++)
				{
					int t=adjlist[z][y].fi;
					dis[t]=min(dis[t],dis[z]+adjlist[z][y].se);
				}
				
		bool bisa=false;
		for(x=0;(x<V)&&!bisa;x++)
			for(y=0;y<adjlist[x].size();y++) 
			{
				int t=adjlist[x][y].fi;
				if(dis[t]>dis[x]+adjlist[x][y].se)
				{
					bisa=true;
					break;
				}
			}
			
		if(!bisa) printf("not ");
		printf("possible\n");
	}
	return 0;
}
