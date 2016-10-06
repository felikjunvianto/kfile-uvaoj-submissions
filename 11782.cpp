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
#define INF 2000000000

using namespace std;

struct node
{
	int val, l, r;
};

int H, K, now;
node tree[1 << 19];
int dp[1 << 19][22];
bool visited[1 << 19][22];

void readTree(int h)
{
	int v, idx = now++;
	scanf("%d", &v);
	tree[idx] = (node) {v, -1, -1};
	if(h < H) 
	{
		tree[idx].l = now; readTree(h + 1);
		tree[idx].r = now; readTree(h + 1);
	}
}

int solve(int root, int Krem)
{
	if(Krem == 0) return -INF;
	if(Krem == 1) return tree[root].val;
	if(visited[root][Krem]) return dp[root][Krem];
	
	int &ret = dp[root][Krem] = tree[root].val;
	if(tree[root].l != -1) for(int kiri = 1; kiri < Krem; kiri++)
		ret = max(ret, solve(tree[root].l, kiri) + solve(tree[root].r, Krem - kiri));
	
	return ret;
}

int main()
{
	while(true)
	{
		scanf("%d", &H);
		if(H == -1) break;
		
		scanf("%d", &K);
		now = 0;
		readTree(0);
		
		memset(visited, false, sizeof(visited));
		printf("%d\n", solve(0, K));
	}
	
	return 0;
}

