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

bool dp[10010][111],visited[10010][111];
int T,N,K,x,arr[10010];

bool solve(int now,int mod)
{
	if((now==N)&&(!mod)) return(true);
	if((now==N)&&(mod)) return(false);
	if(visited[now][mod]) return(dp[now][mod]);
	
	visited[now][mod]=true;
	int tambah=(mod+arr[now])%K,kurang=(mod-arr[now]+K)%K;
	
	dp[now][mod]=solve(now+1,tambah)|solve(now+1,kurang);
	return(dp[now][mod]);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&K);
		for(x=0;x<N;x++) 
		{
			scanf("%d",&arr[x]);
			arr[x]%=K;
			while(arr[x]<0) arr[x]+=K; 
		}
		
		memset(visited,false,sizeof(visited));
		printf("%s\n",solve(0,0)?"Divisible":"Not divisible");
	}
	return 0;
}

