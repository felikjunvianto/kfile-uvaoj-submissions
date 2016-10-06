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

pair<PII,PII> path[20][20];
PII mat[20]; //fi=row,se=column;
int dp[20][20];
int N,x,z,i;

int solve(int a,int b)
{
	if(a==b) return 0;
	if(dp[a][b]!=-1) return(dp[a][b]);
	
	int i,&ret = dp[a][b] = INF;
	for(i=a;i<b;i++)
	{
		int temp=mat[a].fi*mat[i].se*mat[b].se+solve(a,i)+solve(i+1,b);
		if(temp<ret)
		{
			ret=temp;
			path[a][b].fi=mp(a,i);
			path[a][b].se=mp(i+1,b);
		}
	}
	return ret;
}

void cetak(int a,int b)
{
	if(a==b)
	{
		printf("A%d",a);
		return;
	}
	printf("(");
	cetak(path[a][b].fi.fi,path[a][b].fi.se);
	printf(" x ");
	cetak(path[a][b].se.fi,path[a][b].se.se);
	printf(")");
}

int main()
{
	i=0;
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		for(x=1;x<=N;x++) scanf("%d %d",&mat[x].fi,&mat[x].se);
		memset(dp,-1,sizeof(dp));
		z=solve(1,N);
		
		printf("Case %d: ",++i);
		cetak(1,N);
		printf("\n");
	}
	return 0;
}

