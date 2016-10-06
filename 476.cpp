#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct koordinat {double x,y;};
struct titik2 {double x1,x2,y1,y2;};

char kode[2];
titik2 rect[15];
koordinat masuk;
int x,y,z;
bool ada;

int main()
{
	z=-1;
	do
	{
		scanf("%s",&kode);
		if(kode[0]=='*') break;
		
		z++;
		scanf("%lf %lf %lf %lf",&rect[z].x1,&rect[z].y1,&rect[z].x2,&rect[z].y2);
	}while(kode[0]!='*');

	y=0;
	do
	{
		scanf("%lf %lf",&masuk.x,&masuk.y);
		if((masuk.x==9999.900000)&&(masuk.y==9999.900000)) break;
		
		ada=false;
		y++;
		for(x=0;x<=z;x++)
			if((masuk.x>rect[x].x1)&&(masuk.x<rect[x].x2)&&(masuk.y<rect[x].y1)&&(masuk.y>rect[x].y2))
			{
				ada=true;
				printf("Point %d is contained in figure %d\n",y,x+1);
			}
			
		if(!ada) printf("Point %d is not contained in any figure\n",y);
	}while((masuk.x!=9999.900000)&&(masuk.y!=9999.900000));
	return 0;
}
