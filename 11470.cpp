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

int N,i,r,c,x;
int sum[15][15];

int num(int ra,int ca, int rb, int cb)
{
	if((ra>rb)||(ca>cb)) return 0;
	return(sum[rb][cb]-sum[ra-1][cb]-sum[rb][ca-1]+sum[ra-1][ca-1]);
}

int main()
{
	i=0;
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		memset(sum,0,sizeof(sum));
		for(r=1;r<=N;r++)
			for(c=1;c<=N;c++)
			{
				scanf("%d",&x);
				sum[r][c]=sum[r-1][c]+sum[r][c-1]+x-sum[r-1][c-1];
			}
			
		printf("Case %d:",++i);
		int ra=1,ca=1,rb=N,cb=N;
		
		while((ra<=rb)&&(ca<=cb))
		{
			printf(" %d",num(ra,ca,rb,cb)-num(ra+1,ca+1,rb-1,cb-1));
			ra++,ca++;
			rb--,cb--;
		}
		printf("\n");
	}
	return 0;
}

