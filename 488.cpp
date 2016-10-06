#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

int t,x,y,z,frec,ampli,a;

int main()
{
	a=0;
	scanf("%d",&t);
	while(t--)
	{
		a++;
		scanf("%d",&ampli);
		scanf("%d",&frec);
		
		if(a>1) printf("\n");
		for(y=0;y<frec;y++)
		{
			for(z=1;z<=ampli;z++)
			{
				for(x=1;x<=z;x++) printf("%d",z);
				printf("\n");
			}
			
			for(z=ampli-1;z>=1;z--)
			{
				for(x=1;x<=z;x++) printf("%d",z);
				printf("\n");
			}
			if(y<frec-1) printf("\n");
		}
	}
	return 0;
}
