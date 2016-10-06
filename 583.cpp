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

using namespace std;

bool prime[50001];
int x,y,z,temp;

int main()
{
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(x=2;x*x<=50000;x++) if(prime[x])
	{
		z=2;
		while(x*z<=50000)
		{
			prime[x*z]=false;
			z++;
		}
	}
	
	do
	{
		scanf("%d",&x);
		if(x==0) break;
		
		printf("%d",x);
		if(x<0) 
		{
			y=1;
			printf(" = -1");
			x=-x;
		} else y=0;
		temp=x;
		
		for(z=2;(long long) z*z<=(long long) x;z++) if(prime[z])
		{
			while(temp%z==0)
			{
				y++;
				if(y==1) printf(" = %d",z); else printf(" x %d",z);
				temp/=z;
			}
		}
		if(temp>1) if(y==0) printf(" = %d",temp); else printf(" x %d",temp);
		printf("\n");
	}while(x!=0);
	return 0;
}

