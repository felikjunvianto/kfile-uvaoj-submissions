#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n,m,x,y,titik_x,titik_y;

int main()
{
	do
	{
		scanf("%d",&n);
		if(n==0) break;
		
		scanf("%d %d",&titik_x,&titik_y);
		for(m=0;m<n;m++)
		{
			scanf("%d %d",&x,&y);
			if((x==titik_x)||(y==titik_y)) printf("divisa\n"); else
			if((x>titik_x)&&(y>titik_y)) printf("NE\n"); else
			if((x<titik_x)&&(y>titik_y)) printf("NO\n"); else
			if((x<titik_x)&&(y<titik_y)) printf("SO\n"); else
			if((x>titik_x)&&(y<titik_y)) printf("SE\n");
		}
	} while (n != 0);
	return 0;
}
