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
#define pi acos(-1.0)
#define eps 1e-9

using namespace std;

bool prime[1101];
char masuk[30];
int x,y,z,panjang,bil;

int main()
{
	memset(prime,true,sizeof(prime));
	prime[0]=false;
	for(x=2;x<=1100;x++) if(prime[x])
	{
		z=2;
		while(x*z<=1100)
		{
			prime[x*z]=false;
			z++;
		}
	}
	
	while(gets(masuk))
	{
		panjang=strlen(masuk);
		bil=0;
		for(x=0;x<panjang;x++) if((masuk[x]>='a')&&(masuk[x]<='z')) bil+=masuk[x]-'a'+1;
			else bil+=masuk[x]-'A'+27;
		if(prime[bil]) printf("It is a prime word.\n");
			else printf("It is not a prime word.\n");
	}
	return 0;
}

