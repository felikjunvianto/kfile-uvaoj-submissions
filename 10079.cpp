#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long bil,sum;

int main()
{
	do
	{
		scanf("%lld",&bil);//don't forget, UVa is using Linux, so you must use "%lld" instead of "I64d"
		if(bil<0) break;
		sum=(long long)((bil)*(1+bil)/2)+1;
		printf("%lld\n",sum);
	} while(bil>=0);
	return 0;
}
