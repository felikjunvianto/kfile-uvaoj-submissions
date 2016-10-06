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

int T;
double r1,r2,r3;
double t1,t2,t3;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf %lf %lf",&r1, &r2, &r3);
		
		double a = r1+r2;
		double b = r1+r3;
		double c = r2+r3;
		
		t1 = acos((a*a+b*b-c*c)/(2.0*a*b));
		t2 = acos((a*a+c*c-b*b)/(2.0*a*c));
		t3 = acos((b*b+c*c-a*a)/(2.0*b*c));
		
		double area = 0.5*a*b*sin(t1) - 0.5*(t1*r1*r1 + t2*r2*r2 + t3*r3*r3);
		printf("%.6lf\n",area);
	}
	return 0;
}

