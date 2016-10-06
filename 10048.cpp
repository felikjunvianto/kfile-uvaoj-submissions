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

int e,v,q;
int x,y,z,t;
int adjmat[110][110];

int main()
{
	t=0;
	while(1)
	{
		scanf("%d %d %d",&v,&e,&q);
		if(v+e+q==0) break;
		
		for(x=1;x<=v;x++)
			for(y=1;y<=v;y++) adjmat[x][y]=(x==y?0:INF);
			
		while(e--)
		{
			scanf("%d %d %d",&x,&y,&z);
			adjmat[x][y]=adjmat[y][x]=z;
		}
		
		for(z=1;z<=v;z++)
			for(x=1;x<=v;x++)
				for(y=1;y<=v;y++) 
					adjmat[x][y]=min(adjmat[x][y],max(adjmat[x][z],adjmat[z][y]));
		t++;
		if(t>1) printf("\n");
		printf("Case #%d\n",t);
		while(q--)
		{
			scanf("%d %d",&x,&y);
			if(adjmat[x][y]==INF) printf("no path\n"); else printf("%d\n",adjmat[x][y]);
		}
	}
	return 0;
}

