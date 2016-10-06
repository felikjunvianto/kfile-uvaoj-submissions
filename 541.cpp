#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int row[150],column[150];
int bawah,samping,x,y,z,n;
bool bisa;

int main()
{
	do
	{
		scanf("%d",&n);
		if(n==0) break;
		
		memset(row,0,sizeof(row));
		memset(column,0,sizeof(column));
		for(y=0;y<n;y++)
			for(x=0;x<n;x++)
			{
				scanf("%d",&z);
				row[y] +=z;
				column[x] +=z;
			}
			
		bisa=true;
		x=0;
		y=0;
		
		for(z=0;z<n;z++)
		{
			if(row[z]%2==1) y++;
			if(column[z]%2==1) x++;
			if((x>1)||(y>1))
			{
				bisa=false;
				break;
			}
		}
		
		if(bisa)
		{
			if((x==1)&&(y==1))
			{
				for(x=0;x<n;x++) if(column[x]%2==1) break;
				for(y=0;y<n;y++) if(row[y]%2==1) break;
				printf("Change bit (%d,%d)\n",y+1,x+1);
			} else printf("OK\n");
		} else printf("Corrupt\n");
	} while(n>0);
	return 0;
}
