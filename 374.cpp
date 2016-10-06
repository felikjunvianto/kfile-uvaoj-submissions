#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

unsigned long long b,p,m;

unsigned long long bigmod(unsigned long long p)
{
	if(p==0) return (1); else
	if(p==1) return (b%m); else
	{
		unsigned long long bagi = bigmod(p/2);
		if(p%2==0) return((bagi*bagi)%m);
			else return((((bagi*bagi)%m)*b)%m);
	}
}

int main()
{
	//while(scanf("%I64d %I64d %I64d",&b,&p,&m) != EOF)
	while(scanf("%lld %lld %lld",&b,&p,&m) != EOF)
	{
		b %= m;
		printf("%lld\n",bigmod(p));
		//cout << bigmod(p) << endl;
	}
	return 0;
}
