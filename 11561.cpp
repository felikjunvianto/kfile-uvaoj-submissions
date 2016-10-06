#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct koordinat {int x,y;};

char peta[60][60];
koordinat queue[1000000];
int bawah,samping,x,y,z,sum,ver,hor,a,b;
bool aman;

int main()
{
	while(scanf("%d %d",&samping,&bawah) != EOF)
	{
		for(y=0;y<bawah;y++)
			for(x=0;x<samping;x++)
			{
				cin >> peta[x][y];
				if(peta[x][y]=='P')
				{
					queue[0].x = x;
					queue[0].y = y;
					peta[x][y] = '#';
				}
			}
		
		sum=0;
		aman=true;
		for(ver=-1;ver<=1;ver++)
			for(hor=-1;hor<=1;hor++)
				if((ver==0)^(hor==0))
					if(peta[queue[0].x+hor][queue[0].y+ver] == 'T')
					{
						aman=false;
						break;
					}
		
		if(aman)
		{
			x=-1;
			y=0;
			do
			{
				x=(x+1)%1000000;
				for(ver=-1;ver<=1;ver++)
					for(hor=-1;hor<=1;hor++)
						if((ver==0)^(hor==0))
							if(peta[queue[x].x+hor][queue[x].y+ver] != '#')
							{
								if(peta[queue[x].x+hor][queue[x].y+ver] == 'G') sum++;
								aman=true;
								for(a=-1;a<=1;a++)
								{
									for(b=-1;b<=1;b++)
										if((a==0)^(b==0))
											if(peta[queue[x].x+hor+b][queue[x].y+ver+a] == 'T')
											{
												aman=false;
												break;
											}
									if(!aman) break;
								}
								if(aman)
								{
									y=(y+1)%1000000;
									queue[y].x=queue[x].x+hor;
									queue[y].y=queue[x].y+ver;
								}
								peta[queue[x].x+hor][queue[x].y+ver] = '#';
							}
			} while(x!=y);
		}
	
		printf("%d\n",sum);
	}
	return 0;
}
