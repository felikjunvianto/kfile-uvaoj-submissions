#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int a,b,t,x;
int sum[110];

int main()
{
	sum[1]=1;
	for(x=3;x<=99;x+=2) sum[x]=sum[x-2]+x;
	
	scanf("%d",&t);
	for(x=1;x<=t;x++)
	{
		scanf("%d",&a);
		scanf("%d",&b);
		if(!(a%2)) a++;
		if(!(b%2)) b--;
		
		printf("Case %d: ",x);
		if(a==1) printf("%d\n",sum[b]); else printf("%d\n",sum[b]-sum[a-2]);
	}
	return 0;
}
