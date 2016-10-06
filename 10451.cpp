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
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>

using namespace std;

int n,x;
double polygon,bigcir,smallcir,R,r;

int main()
{
	x=1;
	do
	{
		scanf("%d %lf",&n,&polygon);
		if(n<3) break;
		
		R=sqrt(2*polygon/((double)n*sin((double)2*pi/n)));
		r=R*cos((double)pi/n);
		bigcir=pi*R*R;
		smallcir=pi*r*r;
		printf("Case %d: %.5lf %.5lf\n",x++,bigcir-polygon,polygon-smallcir);
	}while(n>2);
	return 0;
}

