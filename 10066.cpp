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

using namespace std;

int t1,t2,x,z;
int tow1[110],tow2[110];
int dp[110][110];

int lcs(int a,int b)
{
	if((a<t1)&&(b<t2))
	{
		if(dp[a][b]==-1)
		{
			if(tow1[a]==tow2[b]) dp[a][b]=1+lcs(a+1,b+1); 
				else dp[a][b]=max(lcs(a+1,b),lcs(a,b+1));
		}
		return(dp[a][b]);
	} else return(0);
}

int main()
{
	z=0;
	do
	{
		scanf("%d %d",&t1,&t2);
		if(t1+t2==0) break;
		
		for(x=0;x<t1;x++) scanf("%d",&tow1[x]);
		for(x=0;x<t2;x++) scanf("%d",&tow2[x]);
		memset(dp,-1,sizeof(dp));
		
		printf("Twin Towers #%d\n",++z);
		printf("Number of Tiles : %d\n\n",lcs(0,0));
	}while(t1+t2!=0);
	return 0;
}

