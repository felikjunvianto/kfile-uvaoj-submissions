#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

int t,x,y,z,p,w,total;
int dp[40];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d",&z);
		for(x=0;x<z;x++)
		{
			scanf("%d %d",&p,&w);
			for(y=35;y>=w;y--) dp[y]=max(dp[y],dp[y-w]+p);
		}
		
		scanf("%d",&z);
		total=0;
		for(x=0;x<z;x++) 
		{
			scanf("%d",&y);
			total+=dp[y];
		}
		printf("%d\n",total);
	}
	return 0;
}
