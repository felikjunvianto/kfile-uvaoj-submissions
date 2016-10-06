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
#define INF -1000000000

using namespace std;

int N,num[110],x,z;
int dp[110][110];

int solve(int a,int b)
{
	if(a>b) return(0);
	if(dp[a][b]!=INF) return(dp[a][b]);
	
	int x,&ret = dp[a][b];
	for(x=a;x<=b;x++) ret=max(ret,(num[x]-num[a-1])-solve(x+1,b));
	for(x=b;x>=a;x--) ret=max(ret,(num[b]-num[x-1])-solve(a,x-1));
	return(ret);
}

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(N==0) break;
		
		num[0]=0;
		for(x=1;x<=N;x++)
		{
			scanf("%d",&z);
			num[x]=num[x-1]+z;
		}
		
		for(x=1;x<=N;x++)
			for(z=1;z<=N;z++) dp[x][z]=INF;
		printf("%d\n",solve(1,N));
	}
	return 0;
}

