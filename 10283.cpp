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

int R,n;
double r,center,outer;

int main()
{
	while(scanf("%d %d",&R,&n)!=EOF)
	{
		if(n==1) r=(double)R; else r = R*sin(pi/n)/(1+sin(pi/n));
		if(n==1) center=0.0; else center=0.5*(R-r)*(R-r)*sin(2*pi/n)*n-2*n*pi*r*r*(90-180.0/n)/360.0;
		outer=pi*R*R-center-n*pi*r*r;
		printf("%.10lf %.10lf %.10lf\n",r,center,outer);
	}
	return 0;
}

