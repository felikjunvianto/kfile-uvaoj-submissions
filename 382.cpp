#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n,x,sum;

int main()
{
	printf("PERFECTION OUTPUT\n");
	do
	{
		scanf("%d",&n);
		if(n==0) break;
		if(n==1) sum=0; else sum=1;
		for(x=2;x*x<=n;x++) if(n%x==0)
		{
			sum+=x;
			if(((int)n/x)!=x) sum+=(int) n/x;
		}
		printf("%5.d  ",n);
		if(sum==n) printf("PERFECT\n");
			else if(sum<n) printf("DEFICIENT\n");
				else printf("ABUNDANT\n");
	} while(n!=0);
	printf("END OF OUTPUT\n");
	return 0;
}
