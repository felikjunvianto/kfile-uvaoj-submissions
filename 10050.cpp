#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t,hari,n,h,x,y,z,sum;
char day[4000];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&hari);
		memset(day,'.',sizeof(day));
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&h);
			z=1;
			while(h*z<=hari)
			{
				day[h*z] = '@';
				z++;
			}
		}
		
		z=0;
		while(6+7*z<=hari)
		{
			day[6+7*z]='.';
			if(7*(z+1)<=hari) day[7*(z+1)]='.';
			z++;
		}
		
		sum=0;
		for(x=1;x<=hari;x++) if(day[x]=='@') sum++;
		printf("%d\n",sum);
	}
	return 0;
}
