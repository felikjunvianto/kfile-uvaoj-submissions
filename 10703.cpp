#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int total,bawah,samping,n,x,y,z,kasus;
int x1,x2,y1,y2;
int peta[550][550];

int main()
{
	kasus=0;
	do
	{
		scanf("%d %d %d",&samping,&bawah,&n);
		if(samping == 0) break;
		scanf("\n");
		kasus++;
		total=samping*bawah;
		for(z=0;z<n;z++)
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			for(y=min(y1,y2);y<=max(y1,y2);y++)
				for(x=min(x1,x2);x<=max(x1,x2);x++) if(peta[x][y] != kasus)
				{
					peta[x][y] = kasus;
					total--;
				}
		}
		
		switch(total)
		{
			case 0: printf("There is no empty spots.\n");
					break;
			
			case 1: printf("There is one empty spot.\n");
					break;
			
			default:printf("There are %d empty spots.\n",total);
					break;
		}
	} while(samping != 0);
	return 0;
}

