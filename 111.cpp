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

int t,x,y,z;
int dp[30];
int urutan[30],prior[30];

int main()
{
	scanf("%d",&t);
	for(x=1;x<=t;x++) scanf("%d",&prior[x]);
	
	while(scanf("%d",&y)!=EOF)
	{
		urutan[y]=1;
		for(x=2;x<=t;x++) 
		{
			scanf("%d",&y);
			urutan[y]=x;
		}
		
		int nilai=0;
		for(x=1;x<=t;x++)
		{
			dp[x]=1;
			for(y=x-1;y>=1;y--) if(prior[urutan[x]]>prior[urutan[y]])
				dp[x]=max(dp[x],dp[y]+1);
			nilai=max(nilai,dp[x]);
		}
		printf("%d\n",nilai);
	}
	return 0;
}

