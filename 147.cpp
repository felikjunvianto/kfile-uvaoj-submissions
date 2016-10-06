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
#define pi acos(-1.0)
#define eps 1e-9

using namespace std;

long long cent[]={1,2,4,10,20,40,100,200,400,1000,2000};
long long dp[6010];
int x,y,z,uang;

int main()
{
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(x=0;x<11;x++)
			for(y=cent[x];y<=6000;y++) dp[y]+=dp[y-cent[x]];
			
	do
	{
		scanf("%d.%d",&x,&y);
		uang=x*100+y;
		if(uang==0) break;
		
		uang/=5;
		double diprint=x+(double)y/100;
		
		
		printf("%6.2f%17lld\n",diprint,dp[uang]);
	} while(uang>0);
	return 0;
}

