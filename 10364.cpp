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

int T,N,x,len;
int arr[30];
bool dp[4][1<<20],visited[4][1<<20];

bool solve(int now, int state)
{
	if(now==4) return(true);
	if(visited[now][state]) return(dp[now][state]);
	
	visited[now][state]=true;
	bool &ret = dp[now][state] = false;
	
	int i,panjang = 0;
	for(i=0;i<N;i++) if(state&(1<<i)) panjang+=arr[i];
	panjang-=now*len;
	
	for(i=0;(i<N)&&(!ret);i++) if(!(state&(1<<i)))
	{
		if(panjang+arr[i]<len) ret=ret|solve(now,state|(1<<i)); else
		if(panjang+arr[i]==len) ret=ret|solve(now+1,state|(1<<i));
	}
	return(ret);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{	
		scanf("%d",&N);
		len=0;
		for(x=0;x<N;x++)
		{
			scanf("%d",&arr[x]);
			len+=arr[x];
		} 
		
		if(len%4) printf("no\n"); else
		{
			len = (len >> 2);
		
			for(x=0;x<4;x++)
				for(int y=0;y<(1<<N);y++) visited[x][y]=false;
			
			printf("%s\n",solve(0,0)?"yes":"no");
		}
	}
	return 0;
}

