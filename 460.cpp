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

int t;
int xa,ya,xb,yb,xc,yc,xd,yd;
int xe,ye,xf,yf;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&xa,&yb,&xb,&ya);
		scanf("%d %d %d %d",&xc,&yd,&xd,&yc);
		xe=max(xa,xc);
		ye=min(ya,yc);
		xf=min(xb,xd);
		yf=max(yb,yd);
		if((yf>=ye)||(xf<=xe)) printf("No Overlap\n");
			else printf("%d %d %d %d\n",xe,yf,xf,ye);
		if(t>0) printf("\n");
	}
	return 0;
}

