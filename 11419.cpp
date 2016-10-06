/**
 Algoritma : Buat 2 himpunan yang saling lepas: himpunan indeks seluruh baris dan himpunan indeks seluruh
             kolom. Jika ada musuh di koordinat (i, j), buat edge dari indeks baris i ke indeks kolom j.
			 
			 banyak tembakan terkecil yang perlu dilakukan = banyak elemen pada minimum vertex cover dari
			 bipartite graph yang terbentuk.
 */

#include <cstdio>
#include <cstdlib>
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
#include <set>

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

int R, C, N, r, c;
vector<int> adjlist[1010];
int par[1010];
bool visited[1010], reached[2010], used[2010];

int augment(int now)
{
	if(visited[now]) return 0;
	visited[now] = true;
	
	for(int i = 0; i < adjlist[now].size(); i++)
	{
		int next = adjlist[now][i] - R;
		if(par[next] == -1 || augment(par[next]))
		{
			par[next] = now;
			return 1;
		}
	}
	return 0;
}

void trace(int now)
{
	if(reached[now]) return;
	reached[now] = true;
	
	for(int i = 0; i < adjlist[now].size(); i++)
	{
		int next = adjlist[now][i] - R;
		if(par[next] != -1)
		{
			reached[next + R] = true;
			trace(par[next]);
		}
	}
}

int main()
{
	while(1)
	{
		scanf("%d %d %d", &R, &C, &N);
		if(!R && !C && !N) break;
		
		for(int i = 1; i <= R; i++) adjlist[i].clear();
		while(N--)
		{
			scanf("%d %d", &r, &c);
			adjlist[r].pb(c + R);
		}
		
		memset(par, -1, sizeof(par));
		for(int i = 1; i <= R; i++) 
		{
			memset(visited, false, sizeof(visited));
			augment(i);
		}
		
		memset(used, false, sizeof(used));
		for(int i = 1; i <= C; i++) if(par[i] != -1) 
			used[par[i]] = used[i + R] = true;
			
		memset(reached, false, sizeof(reached));
		for(int i = 1; i <= R; i++) if(!used[i]) trace(i);
		
		int ans = 0;
		for(int i = 1; i <= R; i++) if(!reached[i]) ans++;
		for(int i = 1; i <= C; i++) if(reached[i + R]) ans++;
		
		printf("%d", ans);
		for(int i = 1; i <= R; i++) if(!reached[i]) printf(" r%d", i);
		for(int i = 1; i <= C; i++) if(reached[i + R]) printf(" c%d", i);
		printf("\n");
	}
	return 0;
}

