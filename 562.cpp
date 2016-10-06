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

int t,x,y,banyak,koin,selisih,total;
bool dp[50100];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,false,sizeof(dp));
		dp[0]=true;
		scanf("%d",&banyak);
		total=0;
		while(banyak--)
		{
			scanf("%d",&koin);
			total+=koin;
			for(x=50000;x>=koin;x--) if(dp[x-koin]) dp[x]=true;
		}
		
		selisih=total;
		for(x=0;x<=total;x++) if(dp[x]) selisih=min(selisih,abs(total-2*x));
		printf("%d\n",selisih);
	}
	return 0;
}

