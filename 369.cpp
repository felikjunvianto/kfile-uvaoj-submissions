#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

double c;
int n,m,x;

int main()
{
	do
	{
		scanf("%d %d",&n,&m);
		if(n==0) break;
		
		c=1;
		for(x=2;x<=m;x++) c = (double)c/x;
		for(x=n;x>=(n-m+1);x--) c = (double) c*x;
		printf("%d things taken %d at a time is %.0f exactly.\n",n,m,c);
	} while(n!=0);
	return 0;
}
