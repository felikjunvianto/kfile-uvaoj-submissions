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

int M,N,price,puas,x;
int ans;
int dp[10300];

int main()
{
	while(scanf("%d %d",&M,&N)!=EOF)
	{
		for(x=0;x<=M+200;x++) dp[x]=-1;
		dp[0]=0;
		
		while(N--)
		{
			scanf("%d %d",&price,&puas);
			for(x=M+200;x>=price;x--) if(dp[x-price]!=-1)
				dp[x]=max(dp[x],dp[x-price]+puas);
		}
		
		ans=0;
		//for(x=0;x<=M+200;x++) printf("%d %d\n",x,dp[x]);
		for(x=1;x<=M+200;x++) if((x<M)||((x>2000)&&(x<=M+200)))
			if(ans<dp[x]) ans=dp[x];
		
		printf("%d\n",ans);
	}
	return 0;
}

