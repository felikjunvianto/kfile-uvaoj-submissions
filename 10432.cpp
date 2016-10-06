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

double r,n;

int main()
{
	while(scanf("%lf %lf",&r,&n)!=EOF)
		printf("%.3lf\n",n*r*r*sin(2*pi/n)/2);
	return 0;
}

