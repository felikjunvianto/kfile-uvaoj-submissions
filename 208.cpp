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

int N, V, T, P;
int i, j, k, tot, bit;
vector<int> adjlist[30];
int path[30];
bool dp[22][1 << 22], visited[22][1 << 22];

bool solve(int now, int state)
{
	if(now + 1 == N) return true;
	if(visited[now][state]) return dp[now][state];
	
	visited[now][state] = true;
	dp[now][state] = false;
	
	for(int x = 0; x < adjlist[now].size(); x++)
	{
		int next = adjlist[now][x];
		if(state & (1 << next)) continue;
		dp[now][state] = dp[now][state] | solve(next, state | (1 << next));
	}
	
	return dp[now][state];
}

void backtrack(int now)
{
	if(now+1 == N) 
	{
		tot++;
		for(int i = 0; i < P; i++) printf("%d%c",path[i]+1,i+1==P?'\n':' ');
		return;
	} 
	
	for(int i = 0; i < adjlist[now].size(); i++)
	{
		int next = adjlist[now][i];
		if(bit & (1 << next)) continue;
		
		if(solve(next, bit | (1 << next))) 
		{
			path[P++] = next;
			bit |= (1 << next);
			backtrack(next);
			
			bit ^= (1 << next);
			P--;
		}
	}
}

int main()
{
	T = 0;
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0;i<30;i++) adjlist[i].clear();
		V = 0;
		
		while(1)
		{
			scanf("%d %d",&i, &j);
			if(!i && !j) break;
			
			V = max(V, max(i, j));
			i--; j--;
			adjlist[i].pb(j);
			adjlist[j].pb(i);
		}
		
		for(i=0;i<V;i++) sort(adjlist[i].begin(), adjlist[i].end());
		
		tot = 0; P = 1; path[0] = 0; bit = 1;
		memset(visited,false,sizeof(visited));
		
		printf("CASE %d:\n",++T);
		backtrack(0);
		printf("There are %d routes from the firestation to streetcorner %d.\n",tot, N);
	}
	return 0;
}

