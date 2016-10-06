#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int current,maks;
int n,m,c,x,y,nomor;
int i[30];
bool on[30],meledak;

int main()
{
	y=0;
	do
	{
		scanf("%d %d %d",&n,&m,&c);
		if(n != 0)
		{
			y++;
			for(x=0;x<n;x++)
			{
				scanf("%d",&i[x]);
				on[x]=false;
			}
		
			current=0;
			maks=0;
			meledak=false;
			
			for(x=0;x<m;x++)
			{
				scanf("%d",&nomor);
				nomor--;

				if (!(meledak))
					if(on[nomor])
					{
						on[nomor]=false;
						current -= i[nomor];
					} else
					{
						current += i[nomor];
						if(current>c) meledak=true;
							else if(current>maks) maks=current;
						on[nomor]=true;
					}
			}

			printf("Sequence %d\n",y);
			if(meledak) printf("Fuse was blown.\n"); 
				else
				{
					printf("Fuse was not blown.\n");
					printf("Maximal power consumption was %d amperes.\n",maks);
				}
			printf("\n");
		}
	} while(n != 0);
	return 0;
}
