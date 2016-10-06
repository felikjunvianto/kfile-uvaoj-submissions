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

double l,w,h,teta;
double missing;

int main()
{
	while(scanf("%lf %lf %lf %lf",&l,&w,&h,&teta)!=EOF)
	{
		double t = l*tan(teta*pi/180.0);
		if(t<= h) missing = w*0.5*l*t; else
		{
			double hh = (1-h/t)*l;
			missing = w*0.5*(l+hh)*h;
		}
		printf("%.3lf mL\n",l*w*h - missing);
	}
	return 0;
}

