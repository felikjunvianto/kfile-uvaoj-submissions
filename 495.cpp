#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int t,x,y,z,fibo[5010][1051],carry;

int main()
{
	fibo[0][0]=0;
	fibo[1][0]=1;

	for(x=2;x<=5000;x++)
	{
		carry=0;
		for(y=0;y<=1050;y++)
		{
			fibo[x][y]=fibo[x-1][y]+fibo[x-2][y]+carry;
			if(fibo[x][y]>9)
			{
				carry=fibo[x][y]/10;
				fibo[x][y]%=10;
			} else carry=0;
		}
	}
	
	while(scanf("%d",&t)!=EOF)
	{
		printf("The Fibonacci number for %d is ",t);
		for(z=1050;z>=0;z--) if(fibo[t][z]>0) break;
		for(y=z;y>=0;y--) printf("%d",fibo[t][y]);
		if(t==0) printf("0");
		printf("\n");
	}
	return 0;
}
