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

int fac[2],temp;
int x,y,N,M,K,ans;

int main()
{
	while(scanf("%d %d",&N,&M)!=EOF)
	{
		for(x=0;x<2;x++) 
		{
			fac[x]=0;
			y=(!x?2:5);
			
			K=N;
			while(K)
			{
				K/=y;
				fac[x]+=K;
			}
			
			K=N-M;
			while(K)
			{
				K/=y;
				fac[x]-=K;
			}
		}
		temp=min(fac[0],fac[1]);
		fac[0]=fac[1]=temp;
		
		ans=1;
		for(x=N;x>=N-M+1;x--)
		{
			K=x;
			while(fac[0] && K%2==0) 
			{
				K/=2;
				fac[0]--;
			}
			
			while(fac[1] && K%5==0)
			{
				K/=5;
				fac[1]--;
			}
			
			ans=(ans*K)%10;
		}
		printf("%d\n",ans);
	}
	return 0;
}

