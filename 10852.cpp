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

bool prime[10010];
vector<int> num;
int x,y,z,T,N,temp,ans;

int main()
{
	memset(prime,true,sizeof(prime));
	for(x=2;x*x<=10000;x++) if(prime[x])
	{
		z=2;
		while(x*z<=10000)
		{
			prime[x*z]=false;
			z++;
		}
	}
	for(x=2;x<=10000;x++) if(prime[x]) num.pb(x);
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		temp=ans=-1;
		
		for(x=0;(x<num.size())&&(num[x]<=N);x++)
		{
			y=(N/num[x]);
			if(N-y*num[x]>temp)
			{
				temp=N-y*num[x];
				ans=num[x];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

