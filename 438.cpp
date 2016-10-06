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

using namespace std;

double xa,ya,xb,yb,xc,yc,r,area,a,b,c;

int main()
{
	while(scanf("%lf %lf %lf %lf %lf %lf",&xa,&ya,&xb,&yb,&xc,&yc)!=EOF)
	{
		a=sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
		b=sqrt((xc-xb)*(xc-xb)+(yc-yb)*(yc-yb));
		c=sqrt((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc));
		area=fabs(xa*(yb-yc)+xb*(yc-ya)+xc*(ya-yb))/2;
		r=a*b*c/(4*area);
		printf("%.2f\n",2*pi*r);
	}
	return 0;
}

