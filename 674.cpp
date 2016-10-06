#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int x,y,n;
int coin[5];
unsigned int dp[7500];

int main()
{
	coin[0]=1;
	coin[1]=5;
	coin[2]=10;
	coin[3]=25;
	coin[4]=50;
	dp[0]=1;
	for(x=0;x<5;x++)
		for(y=coin[x];y<=7489;y++)
			dp[y] +=dp[y-coin[x]];
				
	while(scanf("%d",&n) != EOF) printf("%d\n",dp[n]);
	return 0;
}
