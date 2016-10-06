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

int ukuran,x,y,z,banyak,t;
bool peta[30][30];
char masuk[30];

void ff(int x,int y)
{
	int ver,hor;
	
	peta[x][y]=false;
	for(ver=-1;ver<=1;ver++)
		for(hor=-1;hor<=1;hor++)
			if((ver!=0)||(hor!=0))
				if((x+hor>=0)&&(x+hor<ukuran)&&(y+ver>=0)&&(y+ver<ukuran))
					if(peta[x+hor][y+ver]==true) ff(x+hor,y+ver);
	return;
}

int main()
{
	t=0;
	while(scanf("%d",&ukuran)!=EOF)
	{
		getchar();
		for(y=0;y<ukuran;y++)
		{
			gets(masuk);
			for(x=0;x<ukuran;x++) peta[x][y]=masuk[x]-'0';
		}
		
		t++;
		banyak=0;
		for(y=0;y<ukuran;y++)
			for(x=0;x<ukuran;x++) if(peta[x][y]==true)
			{
				banyak++;
				ff(x,y);
			}
			
		printf("Image number %d contains %d war eagles.\n",t,banyak);
	}
	return 0;
}
