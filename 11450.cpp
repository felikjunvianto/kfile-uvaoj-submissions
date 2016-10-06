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

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>

using namespace std;

int t,x,y,z,money,tipe,harga;
bool dp[2][210],bisa;
int now,prev;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		now=0;
		scanf("%d %d",&money,&tipe);
		memset(dp,false,sizeof(dp));
		dp[0][0]=dp[1][0]=true;
		while(tipe--)
		{
			prev=now;
			now^=1;
			for(x=0;x<=money;x++) dp[now][x]=false;
			scanf("%d",&z);
			while(z--)
			{
				scanf("%d",&harga);
				for(x=money;x>=harga;x--) if(dp[prev][x-harga]) dp[now][x]=true;
			}
		}
		for(x=money;x>=0;x--) if(dp[now][x]) break;
		if(x<1) printf("no solution\n"); else printf("%d\n",x);
	}
	return 0;
}

