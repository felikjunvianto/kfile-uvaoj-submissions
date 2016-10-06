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
#define INF 10000

using namespace std;

int N,T,x,y,z;
bool vis[1010];
vector<int> adjlist[1010],child[1010];
int dp[1010][3];
queue<int> q;

int solve(int node,int state)
{
	if(dp[node][state]!=-1) return(dp[node][state]);
	int &ret = dp[node][state];
	
	switch(state)
	{
		case(0): ret=0;
				 for(int i=0;i<child[node].size();i++)
			     {
					int next=child[node][i];
					ret+=solve(next,1);
				 }break;
				 
		case(1): ret=1;
				 for(int i=0;i<child[node].size();i++)
			     {
					int next=child[node][i];
					ret+=min(solve(next,0),solve(next,1));
				 }break;
	}
	return(ret);
}

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		for(x=1;x<=N;x++)
		{
			adjlist[x].clear();child[x].clear();
			scanf("%d",&T);
			while(T--)
			{
				scanf("%d",&y);
				adjlist[x].pb(y);
			}
		}
		q.push(1);
		memset(vis,false,sizeof(vis));
		vis[1]=true;
		
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			for(y=0;y<adjlist[x].size();y++)
			{
				z=adjlist[x][y];
				if(vis[z]) continue;
				vis[z]=true;
				child[x].pb(z);
				q.push(z);
			}
		}
		
		if(N==1) printf("1\n"); else
		{
			memset(dp,-1,sizeof(dp));
			printf("%d\n",min(solve(1,0),solve(1,1)));
		}
	}
	return 0;
}

