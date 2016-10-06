#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n,m,x,y,sum;
int dragon[20100],knight[20100];

int main()
{
	do
	{
		scanf("%d %d",&n,&m);
		if(n==0) break;
		for(x=0;x<n;x++) scanf("%d",&dragon[x]);
		for(x=0;x<m;x++) scanf("%d",&knight[x]);
		if(n>m) printf("Loowater is doomed!\n"); else
		{
			sort(dragon,dragon+n);
			sort(knight,knight+m);
		
			x=-1;
			y=0;
			sum=0;
			do
			{
				x++;
				while((dragon[x]>knight[y])&&(y<m)) y++;
				if(dragon[x]<=knight[y]) sum += knight[y];
				y++;
			} while((x<n-1)&&(y<m));
			
			if((x==n-1)&&(y<=m)) printf("%d\n",sum); else
				printf("Loowater is doomed!\n");
		}
	} while(n != 0);
	return 0;
}
