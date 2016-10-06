#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n,tot,x,y,z,bil[3600];
bool prime[33000];

int main()
{
	memset(prime,true,sizeof(prime));
	prime[0]=false;
	prime[1]=false;
	y=-1;
	for(x=2;x<33000;x++) if(prime[x])
	{
		y++;
		bil[y]=x;
		z=2;
		while(x*z<33000)
		{
			prime[x*z]=false;
			z++;
		}
	}

	do
	{
		scanf("%d",&n);
		if(n==0) break;
		
		tot=0;
		for(x=0;2*bil[x]<=n;x++) if(prime[n-bil[x]]) tot++;
		printf("%d\n",tot);
	} while(n>0);
	return 0;
}
