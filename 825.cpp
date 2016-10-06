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

int T,bawah,samping,x,y,a,b;
LL dp[200][200];
char masuk[1000];

LL solve(int x,int y)
{
	if(dp[x][y]!=-1) return(dp[x][y]);
	dp[x][y]=0LL;
	if(x+1<=samping) dp[x][y]+=solve(x+1,y);
	if(y+1<=bawah) dp[x][y]+=solve(x,y+1);
	return(dp[x][y]);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d\n",&bawah,&samping);
		memset(dp,-1,sizeof(dp));
		dp[samping][bawah]=1LL;
		for(x=1;x<=bawah;x++)
		{
			gets(masuk);
			bool kesatu=true;
			
			for(char *p=strtok(masuk," ");p;p=strtok(NULL," "))
			{
				int panjang=strlen(p);
				b=0;
				for(y=0;y<panjang;y++) b=(b*10)+(p[y]-'0');
				if(kesatu)
				{
					a=b;
					kesatu=false;
				} else dp[b][a]=0LL;
			}
		}
		printf("%lld\n",solve(1,1));
		if(T) printf("\n");
	}
	
	return 0;
}

