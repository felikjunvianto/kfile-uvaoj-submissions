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

int M,N,item[30];
int x,y,z,sum,len;
char msk[1000];
bool dp[5000];

int main()
{
	scanf("%d",&M);getchar();
	while(M--)
	{
		gets(msk);len=strlen(msk);
		N=sum=x=0;
		while((x<len)&&(msk[x]==' ')) x++;x--;
		while(x+1<len)
		{
			x++;
			y=x;
			while((y<len)&&(msk[y]!=' ')) y++;
			item[N]=0;
			for(z=x;z<y;z++) item[N]=item[N]*10+(msk[z]-'0');
			sum+=item[N];
			x=y;N++;
			while((x<len)&&(msk[x]==' ')) x++;x--;
		}
		
		if(sum&1) printf("NO\n"); else
		{
			memset(dp,false,sizeof(dp));
			dp[0]=true;
			for(x=0;x<N;x++)
				for(y=sum;y>=item[x];y--)
					if(dp[y-item[x]]) dp[y]=true;
			
			printf("%s\n",dp[sum/2]?"YES":"NO");
		}
	}
	return 0;
}

