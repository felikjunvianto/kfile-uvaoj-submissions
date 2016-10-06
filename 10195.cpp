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

double a,b,c,s,r;

int main()
{
	while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
	{
		if((a<eps)||(b<eps)||(c<eps)) r=0; else
		{
			s=(a+b+c)/2;
			r=sqrt((s-a)*(s-b)*(s-c)/s);
		}
		printf("The radius of the round table is: %.3lf\n",r);
	}
	return 0;
}

