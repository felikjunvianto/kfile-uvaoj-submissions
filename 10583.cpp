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

int N,M,x,a,b,z;
vector<int> adjlist[50010];
bool visited[50010];

void ff(int now)
{
	for(int t=0;t<adjlist[now].size();t++)
		if(!visited[adjlist[now][t]])
		{
			visited[adjlist[now][t]]=true;
			ff(adjlist[now][t]);
		}
}

int main()
{
	z=0;
	while(1)
	{
		scanf("%d %d",&N,&M);
		if(N+M==0) break;
		
		for(x=1;x<=N;x++) adjlist[x].clear();
		while(M--)
		{
			scanf("%d %d",&a,&b);
			adjlist[a].pb(b);
			adjlist[b].pb(a);
		}
		
		memset(visited,false,sizeof(visited));
		int ans=0;
		for(x=1;x<=N;x++) if(!visited[x])
		{
			ans++;
			visited[x]=true;
			ff(x);
		}
		printf("Case %d: %d\n",++z,ans);
	}
	return 0;
}

