#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define INF 1000000000
#define EPS 1e-9
#define PI 2*acos(0.0)
#define PII pair<int, int> 

using namespace std;

int N, M, K, a, b, c;
vector<int> adjlist[111];
bool visited[111], matched[111], inT[222];
int par[111];

int augment(int now)
{
	if(visited[now]) return 0;
	visited[now] = true;
	
	for(int i = 0; i < adjlist[now].size(); i++)
	{
		int next = adjlist[now][i];
		if(par[next - N] == -1 || augment(par[next - N]))
		{
			par[next - N] = now;
			return 1;
		}
	}
	
	return 0;
}

void traverse(int now)
{
	if(visited[now]) return;
	visited[now] = true;

	inT[now] = true;
	
	for(int i = 0; i < adjlist[now].size(); i++) 
	{
		int next = adjlist[now][i];
		inT[next] = true;
		
		if(par[next - N] != -1) traverse(par[next - N]);
	}
}

int main() 
{
	while(1)
	{
		scanf("%d", &N); if(!N) break;
		scanf("%d %d", &M, &K);
		
		for(int i = 1; i <= N; i++) adjlist[i].clear();
		memset(par, -1, sizeof(par));
		
		while(K--)
		{
			scanf("%d %d %d", &a, &b, &c);
			adjlist[b].pb(c + N);
		}	
		
		for(int i = 1; i <= N; i++)
		{
			memset(visited, false, sizeof(visited));
			augment(i);
		}
		
		memset(matched, false, sizeof(matched));
		for(int i = 1; i <= M; i++) if(par[i] != -1) matched[par[i]] = true;
		
		memset(inT, false, sizeof(inT));
		for(int i = 1; i <= N; i++) if(!matched[i]) 
		{
			memset(visited, false, sizeof(visited));
			traverse(i);
		}
		
		int ans = 0;
		for(int i = 1; i <= N; i++) if(!inT[i]) ans++;
		for(int i = 1 + N; i <= M + N; i++) if(inT[i]) ans++;
		
		printf("%d\n", ans);
	}
   return 0;
}


