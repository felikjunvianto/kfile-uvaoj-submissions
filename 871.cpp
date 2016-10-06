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

int dr[] = { 0, 1, 1, 1, 0,-1,-1,-1};
int dc[] = { 1, 1, 0,-1,-1,-1, 0, 1};

int T, R, C;
char grid[50][50];

int ff(int r,int c)
{
	grid[r][c]='0';
	int ret = 1;
	for(int i = 0; i < 8; i++)
	{
		int sr = r + dr[i], sc = c + dc[i];
		if(sr>=0 && sc>=0 && sr<R && sc<C && grid[sr][sc]=='1')
			ret += ff(sr,sc);
	}
	return ret;
}

int main()
{
	scanf("%d",&T); getchar(); getchar();
	
	while(T--)
	{
		R = 0;
		while(gets(grid[R]))
		{
			if(!strlen(grid[R])) break;
			R++;
		} C = strlen(grid[0]);
		
		//for(int i=0;i<R;i++) printf("%s\n",grid[i]);
		
		int ans = 0;
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				if(grid[i][j]=='1')
					ans = max(ans, ff(i,j));
		
		printf("%d\n",ans);
		if(T) printf("\n");
	}
	return 0;
}

