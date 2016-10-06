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

int N,M,x,y;
vector<int> after[111];
int ordo[111];
PII urutan[111];

int solve(int now)
{
	if(ordo[now]!=-1) return(ordo[now]);
	
	ordo[now]=0;
	for(int i=0;i<after[now].size();i++)
		ordo[now]=max(ordo[now],solve(after[now][i])+1);
		
	return ordo[now];
}

int main()
{
	while(1)
	{
		scanf("%d %d",&N,&M);
		if(!N && !M) break;
		
		for(x=1;x<=N;x++)
		{
			after[x].clear();
			ordo[x]=-1;
		}
		
		while(M--)
		{
			scanf("%d %d",&x,&y);
			after[y].pb(x);
		}
		
		for(x=1;x<=N;x++) urutan[x]=mp(solve(x),x);
		sort(urutan+1,urutan+1+N);
		
		for(x=1;x<=N;x++) printf("%d%c",urutan[x].se,x==N?'\n':' ');
	}
	return 0;
}

