// algorithm: Kuhn Munkres. Answer = label of every vertex = byproduct of maximum weight problem

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

const int MAXN = 555;

int N, W[MAXN][MAXN], lx[MAXN], ly[MAXN];
int par[MAXN], slack[MAXN], num_match, flow;
bool S[MAXN], T[MAXN];

bool km_augment(int i)
{
	S[i] = true;
	for(int j = 0; j < N; j++) 
		if(!T[j]) slack[j] = min(slack[j], lx[i] + ly[j] - W[i][j]);
		
	for(int j = 0; j < N; j++)
		if(lx[i] + ly[j] == W[i][j] && !T[j])
		{
			T[j] = true;
			if(par[j] == -1 || km_augment(par[j]))
			{
				if(par[j] != -1) flow -= W[par[j]][j];
				par[j] = i;
				flow += W[i][j];
				return 1;
			}
		}
		
	return 0;
}

void km_update_labels() 
{
	int delta = INF;
	for(int j = 0; j < N; j++) 
		if(!T[j]) delta = min(delta, slack[j]);
		
	for(int i = 0; i < N; i++)
	{
		if(S[i]) lx[i] -= delta;
		if(T[i]) ly[i] += delta;
	}
}

void km_main()
{
	memset(lx, 0, sizeof(lx));
	memset(ly, 0, sizeof(ly));
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++) 
			lx[i] = max(lx[i], W[i][j]);
			
	memset(par, -1, sizeof(par));
	num_match = flow = 0;
	
	for(int i = 0; i < N && num_match < N; i++)
		while(true)
		{
			memset(slack, 127, sizeof(slack));
			memset(S, false, sizeof(S));
			memset(T, false, sizeof(T));
			
			if(km_augment(i))
			{
				num_match++;
				break;
			}
			
			km_update_labels();
		}
}

int main()
{
	while(scanf("%d", &N) != EOF)
	{
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				scanf("%d", &W[i][j]);
			
		km_main();
		for(int i = 0; i < N; i++) printf("%d%c",lx[i],i+1==N?'\n':' ');
		for(int i = 0; i < N; i++) printf("%d%c",ly[i],i+1==N?'\n':' ');
		printf("%d\n", flow);
	}
	return 0;
}

