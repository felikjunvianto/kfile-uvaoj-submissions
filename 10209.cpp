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

double a,x,y,z;

int main()
{
	while(scanf("%lf",&a)!=EOF)
	{
		x=a*a*(1-sqrt(3)/4.00-pi/6.00);
		y=a*a*(1-pi/4.00)-2*x;
		z=a*a-4*(x+y);
		printf("%.3lf %.3lf %.3lf\n",z,4*y,4*x);
	}
	return 0;
}

