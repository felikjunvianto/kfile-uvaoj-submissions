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

double D,V,A,d;

int main()
{
	while(1)
	{
		scanf("%lf %lf",&D,&V);
		if((D<eps)&&(V<eps)) break;
		
		A=pi*pow(D,3)/4.00-V;
		d=pow((12.0*A-pi*pow(D,3))/(2.00*pi),1/3.00);
		printf("%.3lf\n",d);
	}
	return 0;
}

