/**
 Algoritma : implementasi seperti yang diterangkan pada slide materi Minimum Path Cover
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

typedef struct
{
	int a, b, c, d, init, end;
} order;

int T, N;
int h, m, a, b, c, d;
order node[555];
vector<int> adjlist[555];
int par[555];
bool visited[555];

int augment(int now)
{
	if(visited[now]) return 0;
	visited[now] = true;
	
	for(int i = 0 ; i < adjlist[now].size(); i++)
	{
		int next = adjlist[now][i] - N;
		if(par[next] == -1 || augment(par[next]))
		{
			par[next] = now;
			return 1;
		}
	}
	return 0;
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d:%d %d %d %d %d", &h, &m, &a, &b, &c, &d);
			node[i] = (order){a, b, c, d, h * 60 + m, h * 60 + m + abs(c - a) + abs(d - b)};
		}
		
		for(int i = 0; i < N; i++) adjlist[i].clear();
		for(int i = 0; i < N; i++)
			for(int j = i + 1; j < N; j++)
				if(node[i].end + abs(node[j].a - node[i].c) + abs(node[j].b - node[i].d) + 1 <= node[j].init) 
					adjlist[i].pb(j + N);
			
		int MCBM = 0;
		memset(par, -1, sizeof(par));
		for(int i = 0; i < N; i++)
		{
			memset(visited, false, sizeof(visited));
			MCBM += augment(i);
		}
		
		printf("%d\n", N - MCBM);
	}
	return 0;
}

