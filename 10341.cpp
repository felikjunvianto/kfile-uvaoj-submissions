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
#define eps 1e-15
#define PII pair<int,int> 
#define PDD pair<double,double>
#define LL long long
#define INF 1000000000

using namespace std;

int p,q,r,s,t,u,code;
double f0,f1;

double calc(double x)
{
	return (double)p*exp(-x) + (double)q*sin(x) + (double)r*cos(x) + (double)s*tan(x) + (double)t*x*x + (double)u;
}

double binser(double l, double r)
{
	while(fabs(l-r)>eps)
	{
		double mid = (l+r)/2.0;
		double tes = calc(mid);
		
		if(tes>eps) l = mid; else
			if(tes<eps) r = mid;
	} return r;
}

int main()
{
	while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF)
	{
		if(calc(0)<0 || calc(1)>0) printf("No solution\n");
			else printf("%.4lf\n",binser(0,1));
	}
	return 0;
}

