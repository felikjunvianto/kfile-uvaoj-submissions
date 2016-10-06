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
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>
#define LL long long
#define INF 1000000000

using namespace std;

int xA,yA,xB,yB,n;
double dx,dy,dia,r,teta;

int main()
{
	while(scanf("%d %d %d %d %d",&xA,&yA,&xB,&yB,&n)!=EOF)
	{
		if(!xA && !yA && !xB && !yB && !n) break;
		
		dx = xA - xB;
		dy = yA - yB;
		dia = sqrt(dx*dx+dy*dy);
		teta = 2*pi/(double)n;
		
		if(n&1) r = dia*sin(teta/4.0)/sin(teta/2.0);
			else r = dia/2.0;
			
		printf("%.6lf\n",0.5*r*r*sin(teta)*n);
	}
	return 0;
}

