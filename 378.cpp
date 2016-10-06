#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define eps 1e-9

using namespace std;

int t,xa,ya,xb,yb,xc,yc,xd,yd;
int det,A1,B1,C1,A2,B2,C2;
double x_pot,y_pot;

int main()
{
	scanf("%d",&t);
	printf("INTERSECTING LINES OUTPUT\n");
	while(t--)
	{
		scanf("%d %d %d %d %d %d %d %d",&xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd);
		A1=yb-ya;
		B1=xa-xb;
		C1=A1*xa+B1*ya;
		
		A2=yd-yc;
		B2=xc-xd;
		C2=A2*xc+B2*yc;
		
		det=A1*B2-A2*B1;
		if(det==0)
		{
			if((A1*xc+B1*yc==C1)&&(A1*xd+B1*yd==C1)) printf("LINE\n");
				else printf("NONE\n");
		} else
		{
			x_pot=(double)(C1*B2-C2*B1)/det;
			y_pot=(double)(C2*A1-C1*A2)/det;
			printf("POINT %.2f %.2f\n",x_pot,y_pot);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}

