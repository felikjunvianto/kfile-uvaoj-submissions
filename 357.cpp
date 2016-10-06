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

int cent[]={1,5,10,25,50};
long long dp[30100];
int x,y,z,uang;

int main()
{
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(x=0;x<5;x++)
		for(y=cent[x];y<=30000;y++) dp[y]+=dp[y-cent[x]];
		
	while(scanf("%d",&uang)!=EOF)
	{
		if(dp[uang]==1) printf("There is only 1 way ");
			else printf("There are %lld ways ",dp[uang]);
		printf("to produce %d cents change.\n",uang);
	}
	return 0;
}

