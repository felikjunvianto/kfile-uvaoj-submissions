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

double a,b,c,s,area,r,R;

int main()
{
	while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
	{
		s=(a+b+c)/2;
		area=sqrt(s*(s-a)*(s-b)*(s-c));
		r=area/s;
		R=a*b*c/(4*area);
		printf("%.4lf %.4lf %.4lf\n",pi*R*R-area,area-pi*r*r,pi*r*r);
	}
	return 0;
}

