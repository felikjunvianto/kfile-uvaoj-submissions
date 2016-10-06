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

int N,x,y,z,jml,visited[111];
vector<int> adjlist[111];

void ff(int now)
{
	jml--;
	for(int i=0;i<adjlist[now].size();i++)
	{
		int next=adjlist[now][i];
		if(!visited[next])
		{
			visited[next]=true;
			ff(next);
		}
	}
}

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		for(x=1;x<=N;x++) adjlist[x].clear();
		while(1)
		{
			scanf("%d",&x);
			if(!x) break;
			while(1)
			{
				scanf("%d",&y);
				if(!y) break;
				adjlist[x].pb(y);
			}
		}
		
		scanf("%d",&z);
		while(z--)
		{
			scanf("%d",&x);
			jml=N+1;
			memset(visited,false,sizeof(visited));
			ff(x);
			printf("%d",jml);
			for(x=1;x<=N;x++) if(!visited[x]) printf(" %d",x);
			printf("\n");
		}
	}
	return 0;
}

