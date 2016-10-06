/**
 Algoritma : cari berapa banyak elemen pada minimum vertex cover terhadap bipartite graph yang terbentuk.
             Tricky : elemen kedua himpunan bisa berupa nol (0).
 */
 
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

int N, A, B;
int num[222], par[111];
vector<int> adjlist[111];
bool used[111], visited[111], reachable[222];

int augment(int now)
{
	if(visited[now]) return 0;
	visited[now] = true;
	
	for(int i = 0; i < adjlist[now].size(); i++)
	{
		int next = adjlist[now][i];
		if(par[next - A] == -1 || augment(par[next - A]))
		{
			par[next - A] = now;
			return 1;
		}
	}
	return 0;
}

void dfs(int now)
{
	if(reachable[now]) return;
	reachable[now] = true;
	
	for(int i = 0; i < adjlist[now].size(); i ++)
	{
		int next = adjlist[now][i];
		if(par[next - A] != -1) 
		{
			reachable[next] = true;
			dfs(par[next - A]);
		}
	}
}

int main()
{
	scanf("%d", &N);
	for(int n = 1; n <= N; n++)
	{
		scanf("%d", &A);
		for(int i = 0; i < A; i++) 
		{
			scanf("%d", &num[i]);
			adjlist[i].clear();
		}
		
		scanf("%d", &B);
		for(int i = 0; i < B; i++) 
		{
			scanf("%d", &num[i + A]);
			par[i] = -1;
		}
		
		for(int i = 0; i < A; i++)
			for(int j = 0; j < B; j++)
				if(!num[j + A] || (num[i] && num[j + A] % num[i] == 0))
					adjlist[i].pb(j + A);
					
		for(int i = 0; i < A; i++)
		{
			memset(visited, false, sizeof(visited));
			augment(i);
		}
		
		memset(used, false, sizeof(used));
		for(int i = 0; i < B; i++) 
			if(par[i] != -1) used[par[i]] = true;
			
		memset(reachable, false, sizeof(reachable));
		for(int i = 0; i < A; i++) if(!used[i]) dfs(i);
		
		int ans = 0;
		for(int i = 0; i < A; i++) if(!reachable[i]) ans++;
		for(int i = 0; i < B; i++) if(reachable[i + A]) ans++;
		
		printf("Case %d: %d\n", n, ans);
	}
	return 0;
}

