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

struct castle
{
	int minSoldier, casualties, defender;
};

int N, subtreeLoss[111], subtreeMaxNeeded[111];
castle node[111];
vector<int> child[111], adjlist[111];
queue<int> q;
bool visited[111];

bool test(int root, int val)
{
	stack<PII> s;
	s.push(mp(root, 0));
	
	while(!s.empty())
	{
		PII now = s.top(); s.pop();
		if(!now.se)
		{
			if(val < node[now.fi].minSoldier) return false;
			val -= node[now.fi].casualties + node[now.fi].defender;
		}
		
		if(now.se < child[now.fi].size())
		{
			s.push(mp(now.fi, now.se + 1));
			s.push(mp(child[now.fi][now.se], 0));
		}
	}
	
	if(val < 0) return false;
	return true;
}

int solve(int root, int L, int R)
{
	while(L <= R)
	{
		int now = (L + R) / 2, prev = now - 1;
		bool okenow = test(root, now), okeprev = test(root, prev);
		
		if(okenow && !okeprev) return now; else
			if(okenow && okeprev) R = now - 1; else
				if(!okenow) L = now + 1;
	}
	return R;
}

int findSubtreeLoss(int root)
{
	if(subtreeLoss[root] != -1) return subtreeLoss[root];
	
	int &ret = subtreeLoss[root] = node[root].casualties + node[root].defender;
	for(int i = 0; i < child[root].size(); i++)
		ret += findSubtreeLoss(child[root][i]);
		
	return ret;
}

int findSubtreeMaxNeeded(int root)
{
	if(subtreeMaxNeeded[root] != -1) return subtreeMaxNeeded[root];
	
	int &ret = subtreeMaxNeeded[root] = node[root].minSoldier;
	for(int i = 0; i < child[root].size(); i++)
		ret = max(ret, findSubtreeMaxNeeded(child[root][i]));
		
	return ret;
}

bool cf(int a, int b)
{
	if(subtreeMaxNeeded[a] != subtreeMaxNeeded[b]) return subtreeMaxNeeded[a] > subtreeMaxNeeded[b];
	return subtreeLoss[a] < subtreeLoss[b];
}

int main()
{
	int T = 0;
	while(1)
	{
		scanf("%d", &N);
		if(!N) break;
		
		int a, m, g;
		for(int i = 1; i <= N; i++)
		{
			scanf("%d %d %d", &a, &m, &g);
			node[i] = (castle) {a, m, g};
		}
		
		int b, c;
		for(int i = 1; i <= N; i++) adjlist[i].clear();
		for(int i = 0; i < N - 1; i++) 
		{
			scanf("%d %d", &b, &c);
			adjlist[b].pb(c);
			adjlist[c].pb(b);
		}
		
		int ans = INF;
		for(int root = 1; root <= N; root++)
		{
			for(int i = 1; i <= N; i++) child[i].clear();
			memset(visited, false, sizeof(visited));
			visited[root] = true;
			q.push(root);
			
			while(!q.empty())
			{
				int now = q.front(); q.pop();
				
				for(int i = 0; i < adjlist[now].size(); i++)
				{
					int next = adjlist[now][i];
					if(!visited[next])
					{
						child[now].pb(next);
						visited[next] = true;
						q.push(next);
					}
				}
			}
			
			memset(subtreeLoss, -1, sizeof(subtreeLoss));
			memset(subtreeMaxNeeded, -1, sizeof(subtreeMaxNeeded));
			for(int i = 1; i <= N; i++) 
			{
				findSubtreeLoss(i);
				findSubtreeMaxNeeded(i);
			}
			
			for(int i = 1; i <= N; i++) sort(child[i].begin(), child[i].end(), cf);
			
			int L = 0, R = 0;
			for(int i = 1; i <= N; i++) R += (node[i].minSoldier >= node[i].casualties + node[i].defender ?
												node[i].minSoldier : node[i].casualties + node[i].defender);
			
			int temp = solve(root, L, R);
			ans = min(ans, solve(root, L, R));
		}
		
		printf("Case %d: %d\n", ++T, ans);
	}
	return 0;
}

