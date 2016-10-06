#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int bawah,samping,x,y,z,ver,hor;
char peta[150][150],masuk[150];

int main()
{
	z=0;
	do
	{
		scanf("%d %d",&bawah,&samping);
		if(bawah==0) break;
		
		z++;
		memset(peta,'.',sizeof(peta));
		for(y=0;y<bawah;y++)
		{
			scanf("%s",masuk);
			for(x=0;x<samping;x++)
			{
					peta[x][y]=masuk[x];
					if(peta[x][y]=='.') peta[x][y]='0';
			}
		}
			
		for(y=0;y<bawah;y++)
			for(x=0;x<samping;x++) if(peta[x][y]=='*')
				for(ver=-1;ver<=1;ver++)
					for(hor=-1;hor<=1;hor++)
						if(!((ver==0)&&(hor==0)))
							if((x+hor>=0)&&(x+hor<samping)&&(y+ver>=0)&&(y+ver<bawah))
								if(peta[x+hor][y+ver]!='*') peta[x+hor][y+ver]++;
		
		if(z>1) printf("\n");
		printf("Field #%d:\n",z);
		for(y=0;y<bawah;y++)
		{
			for(x=0;x<samping;x++) printf("%c",peta[x][y]);
			printf("\n");
		}
	}while(bawah!=0);
	return 0;
}
