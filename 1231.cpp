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

int best[2010];
int dp[2010][2010];
int N,t,h,f,x,y,z;

int main()
{
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d %d %d",&t,&h,&f);
		for(x=1;x<=t;x++)
			for(y=0;y<=h;y++) dp[x][y]=0;
			
		for(x=1;x<=t;x++)
		{
			scanf("%d",&z);
			while(z--)
			{
				scanf("%d",&y);
				dp[x][y]++;
			}
		}
		
		for(y=0;y<=h;y++)
		{
			best[y]=0;
			for(x=1;x<=t;x++)
			{
				int temp1=0,temp2=0;
				if(y-1>=0) temp1=dp[x][y]+dp[x][y-1];
				if(y-f>=0) temp2=dp[x][y]+best[y-f];
				dp[x][y]=max(dp[x][y],max(temp1,temp2));
				
				best[y]=max(best[y],dp[x][y]);
			}
		}
		printf("%d\n",best[h]);
	}
	return 0;
}

