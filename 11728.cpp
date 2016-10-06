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

int ans[1010];
int sum,S,N,i;

int main()
{
	memset(ans,-1,sizeof(ans));
	N=0;
	while(N<=2000)
	{
		N++;
		sum=0;
		for(i=1;i*i<=N;i++) if(N%i==0)
		{
			sum+=i;
			if(i*i!=N) sum+=N/i;
		}
		
		if(sum<=1000) ans[sum]=N;
	}
	
	i=0;
	while(scanf("%d",&S)!=EOF)
	{
		if(!S) break;
		printf("Case %d: %d\n",++i,ans[S]);
	}
	return 0;
}

