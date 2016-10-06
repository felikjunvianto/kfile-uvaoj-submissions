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

bool prime[10000010];
vector<int> bil;
int x,y,z,last,divisor;
LL N;

int main()
{
	memset(prime,true,sizeof(prime));
	for(x=2;x*x<=10000000;x++) if(prime[x])
	{
		z=2;
		while(x*z<=10000000)
		{
			prime[x*z]=false;
			z++;
		}
	}
		
	for(x=2;x<=10000000;x++) if(prime[x]) bil.pb(x);
	
	while(1)
	{
		scanf("%lld",&N);
		if(!N) break;
		
		if(N<0) N*=-1LL;
		last=-1;
		divisor=0;
		for(x=0;(x<bil.size())&&((LL)bil[x]*(LL)bil[x]<=N);x++) if(N%(LL)bil[x]==0)
		{
			divisor++;
			last=x;
			while(N%(LL)bil[x]==0) N/=(LL)bil[x];
		}
		
		if(N!=1LL) divisor++;
		if(divisor<2) printf("-1\n"); else
			if(N!=1LL) printf("%lld\n",N); else
				printf("%d\n",bil[last]);
	}
	return 0;
}

