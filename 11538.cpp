#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

long long m,n,sum,x;

int main()
{
	do
	{
		scanf("%lld %lld",&m,&n);
		if((m==0)&&(n==0)) break;
		
		sum=m*n*(m+n-2);
		x=min(m,n);
		sum+=4*((x-1)*(m*n+m+n+1) + (m+n+2)*(-1)*(((x*(x+1))/2)-1)+((x*(x+1)*(2*x+1))/6)-1);
		//for(x=2;x<=min(m,n);x++) sum+=(n-x+1)*(m-x+1)*4;
		
		printf("%lld\n",sum);
	}while((m!=0)||(n!=0));
	return 0;
}
