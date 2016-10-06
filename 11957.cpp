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

const int MOD = 1000007;
int dc[] = {-1, 1};

char board[111][111];
int T,N,dp[111][111];
int r,c,i;

int solve(int r, int c)
{
	if(!r) return 1;
	if(dp[r][c]!=-1) return dp[r][c];
	
	int &ret =dp[r][c]=0;
	for(int j=0;j<2;j++)
	{
		int sc=c+dc[j],sr=r-1;
		if(sr<0 || sc<0 || sr>=N || sc>=N) continue;
		
		if(board[sr][sc]=='.') ret=(ret+solve(sr,sc))%MOD; else
		{
			sc+=dc[j];
			sr--;
			if(sr>=0 && sc>=0 && sr<N && sc<N && board[sr][sc]=='.') 
				ret=(ret+solve(sr,sc))%MOD;
		}
	}
	return ret;
}

int main()
{
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&N);
		for(r=0;r<N;r++) scanf("%s",board[r]);
		
		for(r=0;r<N;r++)
		{
			for(c=0;c<N;c++) if(board[r][c]=='W') break;
			if(board[r][c]=='W') break;
		}
		
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %d\n",i,solve(r,c));
	}
	return 0;
}

