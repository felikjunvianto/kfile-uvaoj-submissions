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

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>

using namespace std;

bool prime[1000002];
int dipri[1000002];
int t,a,b,x,y,z;

int main()
{
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(x=2;x*x<=1000000;x++) if(prime[x])
	{
		z=2;
		while(x*z<=1000000)
		{
			prime[x*z]=false;
			z++;
		}
	}
	
	dipri[0]=dipri[1]=0;
	for(x=2;x<=1000000;x++) 
	{
		dipri[x]=dipri[x-1];
		if(prime[x])
		{
			z=x;
			y=0;
			while(z>0)
			{
				y+=z%10;
				z/=10;
			}
		
		if(prime[y]) dipri[x]++; 
		}
	}
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",dipri[b]-dipri[a-1]);
	}
	return 0;
}

