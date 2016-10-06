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

vector<int> dp[12][30];
int C[30][30];
int N,D,x,y;

vector<int> solve(int N,int D)
{
	vector<int> tmp;
	while(tmp.size()<30) tmp.pb(0);
	
	if(!N) 
	{
		if(!D) tmp[0]=1;
		return tmp;
	}
	
	if(dp[N][D][0]==-1)
	{
		dp[N][D][0]=0;
		for(int i=0;i<=D;i++) 
		{
			tmp = solve(N-1,D-i);
			int x,carry = 0;
			for(x = 0; x < 30; x++)
			{
				tmp[x] = tmp[x]*C[D][i]+carry;
				carry = tmp[x]/10;
				tmp[x]%=10;
			}
			
			carry = 0;
			for(x = 0; x < 30; x++)
			{
				dp[N][D][x] = dp[N][D][x] + tmp[x] + carry;
				carry = dp[N][D][x]/10;
				dp[N][D][x]%=10;
			}
		}
	}
	return dp[N][D];
}

int main()
{
	for(x=0;x<30;x++)
	{
		C[x][0]=C[x][x]=1;
		for(y=1;y<x;y++) C[x][y]=C[x-1][y-1]+C[x-1][y];
	}
	
	for(x=0;x<12;x++)
		for(y=0;y<30;y++)
		{
			while(dp[x][y].size()<30) dp[x][y].pb(0);
			dp[x][y][0]=-1;
		}
	while(1)
	{
		scanf("%d %d",&N,&D);
		if(!N && !D) break;
		
		vector<int> ans = solve(N,D);
		
		for(y=29;y>=0;y--) if(ans[y]!=0) break;
		if(y==-1) printf("0");
			else for(x=y;x>=0;x--) printf("%d",ans[x]);
		printf("\n");
	}
	return 0;
}

