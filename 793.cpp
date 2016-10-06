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

int T, N, x, y;
int par[100010];
int yes,no;
char inp[50], c;

int find(int i)
{
	int ti = i;
	while(par[ti]!=ti) ti = par[ti];
	par[i] = ti;
	return par[i];
}

bool is_union(int i, int j) { return find(i)==find(j);}

void unify(int i,int j) { par[par[find(i)]] = find(j);}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		yes = no = 0;
		scanf("%d",&N);getchar();
		for(x=1;x<=N;x++) par[x]=x;
		
		while(gets(inp))
		{
			if(!strlen(inp)) break;
			sscanf(inp,"%c %d %d",&c,&x,&y);
			//printf("%c %d %d\n",c,x,y);
			switch(c)
			{
				case('q') : if(is_union(x,y)) yes++; else no++; break;
				case('c') : unify(x,y); break;
			}
		}
		
		printf("%d,%d\n",yes,no);
		if(T) printf("\n");
	}
	return 0;
}

