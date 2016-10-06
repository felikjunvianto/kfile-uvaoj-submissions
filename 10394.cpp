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

bool prime[20000100];
int twin[100010];
int x,z,T;

int main()
{
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(x=2;x*x<=20000000;x++) if(prime[x])
	{
		z=2;
		while(x*z<=20000000)
		{
			prime[x*z]=false;
			z++;
		}
	}
	
	T=1;
	for(x=2;x<=20000000;x++) 
	{
		if((prime[x])&&(prime[x+2])) twin[T++]=x;
		if(T-1==100000) break;
	}
	
	while(scanf("%d",&x)!=EOF) printf("(%d, %d)\n",twin[x],twin[x]+2);
	return 0;
}

