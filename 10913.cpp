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

const int kiri = 0;
const int kanan = 1;
const int atas = 2;

int i,N,k,x,y;
int grid[80][80];
int dp[80][80][7][3];
bool visited[80][80][7][3];

int solve(int r,int c,int left,int last)
{
	if((!r)||(!c)||(r>N)||(c>N)||(left<0)) return(-INF);
	if((r==N)&&(c==N)) return(grid[r][c]);
	if(visited[r][c][left][last]) return(dp[r][c][left][last]);
	
	visited[r][c][left][last]=true;
	int a,temp,&ret = dp[r][c][left][last] = -INF;
	switch(last)
	{
		case(kiri) : a = left;
					 if(grid[r][c+1]<0) a--;
					 temp=solve(r,c+1,a,kiri);
					 if(temp!=-INF) ret = max(ret,grid[r][c]+temp);
					 
					 a = left;
					 if(grid[r+1][c]<0) a--;
					 temp=solve(r+1,c,a,atas);
					 if(temp!=-INF) ret = max(ret,grid[r][c]+temp);
					 break;
		
		case(kanan) : a = left;
					  if(grid[r][c-1]<0) a--;
					  temp=solve(r,c-1,a,kanan);
					  if(temp!=-INF) ret = max(ret,grid[r][c]+temp);
						
					  a = left;
					  if(grid[r+1][c]<0) a--;
					  temp=solve(r+1,c,a,atas);
					  if(temp!=-INF) ret = max(ret,grid[r][c]+temp);
					  break;
		
		case(atas) : a = left;
					 if(grid[r][c+1]<0) a--;
					 temp=solve(r,c+1,a,kiri);
					 if(temp!=-INF) ret = max(ret,grid[r][c]+temp);
						
					 a = left;
					  if(grid[r][c-1]<0) a--;
					  temp=solve(r,c-1,a,kanan);
					  if(temp!=-INF) ret = max(ret,grid[r][c]+temp);
						
					  a = left;
					  if(grid[r+1][c]<0) a--;
					  temp=solve(r+1,c,a,atas);
					  if(temp!=-INF) ret = max(ret,grid[r][c]+temp);
					  break;
	}
	return (ret);
}

int main()
{
	i=1;
	memset(grid,0,sizeof(grid));
	while(1)
	{
		scanf("%d %d",&N,&k);
		if(N+k==0) break;
		
		for(y=1;y<=N;y++)
			for(x=1;x<=N;x++) scanf("%d",&grid[y][x]);
			
		memset(visited,false,sizeof(visited));
		if(grid[1][1]<0) k--;
		int ans=solve(1,1,k,kiri);
		
		printf("Case %d: ",i++);
		if(ans==-INF) printf("impossible\n"); else printf("%d\n",ans);
	}
	return 0;
}

