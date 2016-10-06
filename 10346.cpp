#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long n,k,sisa,sum;

int main()
{
	while(scanf("%lld %lld",&n,&k) != EOF)
	{
		sum=n;
		sisa=0;
		while(n>0)
		{
			sisa+=n;
			n=(int)sisa/k;
			sisa=sisa%k;
			sum+=n;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
