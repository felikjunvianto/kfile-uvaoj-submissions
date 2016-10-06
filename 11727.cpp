#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n,t,a,b,c;

int main()
{
	scanf("%d",&n);
	for(t=0;t<n;t++)
	{
		scanf("%d %d %d",&a,&b,&c);
		printf("Case %d: %d\n",t+1,a+b+c-max(max(a,b),max(b,c))-min(min(a,b),min(b,c)));
	}
	return 0;
}
