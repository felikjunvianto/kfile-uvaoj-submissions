#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t,m,n,x,y,z,panjang;
char masuk[50];

int gcd(int m,int n)
{
	int r;
	if(n>m) return gcd(n,m); else
	{
		r=m%n;
		if(r==0) return n;
			else return gcd(n,r);
	}
}

int main()
{
	scanf("%d",&t);
	for(y=1;y<=t;y++)
	{
		scanf("%s",&masuk);
		panjang=strlen(masuk);
		m=0;
		for(x=0;x<panjang-1;x++) m = (m+masuk[x]-'0')*2;
		m+=(masuk[panjang-1]-'0');
		
		scanf("%s",&masuk);
		panjang=strlen(masuk);
		n=0;
		for(x=0;x<panjang-1;x++) n = (n+masuk[x]-'0')*2;
		n+=(masuk[panjang-1]-'0');
		
		if((m>0)&&(n>0)) z=gcd(m,n);
		printf("Pair #%d: ",y);
		if((m==0)||(n==0)||(z==1)) printf("Love is not all you need!\n");
			else printf("All you need is love!\n");
	}
	return 0;
}
