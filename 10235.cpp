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

bool prime[1000001];
char temp[10];
int x,y,z;

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
	
	while(scanf("%d",&x)!=EOF)
	{
		if(prime[x])
		{
			sprintf(temp,"%d",x);
			z=strlen(temp);
			reverse(temp,temp+z);
			sscanf(temp,"%d",&z);
			if((z!=x)&&(prime[z])) printf("%d is emirp.\n",x);
				else printf("%d is prime.\n",x);
		} else printf("%d is not prime.\n",x);
	}
	return 0;
}

