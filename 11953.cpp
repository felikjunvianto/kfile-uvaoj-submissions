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

int dr[] = { 0, 1, 0,-1};
int dc[] = { 1, 0,-1, 0};

int T,N,r,c,ship;
char grid[111][111];
bool alive;

void ff(int r,int c)
{
	if(grid[r][c]=='x') alive = true;
	grid[r][c]='.';
	
	for(int i=0;i<4;i++)
	{
		int sr=r+dr[i],sc=c+dc[i];
		if(sr>=0 && sc>=0 && sr<N && sc<N && grid[sr][sc]!='.')
			ff(sr,sc);
	}
}

int main()
{
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&N);
		for(r=0;r<N;r++) scanf("%s",grid[r]);
		
		ship = 0;
		for(r=0;r<N;r++)
			for(c=0;c<N;c++) if(grid[r][c]!='.')
			{
				alive = false;
				ff(r,c);
				if(alive) ship++;
			}
			
		printf("Case %d: %d\n",i,ship);
	}
	return 0;
}

