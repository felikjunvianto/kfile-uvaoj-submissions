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

LL ord;
LL x,y,z;

int main()
{
	while(scanf("%lld",&ord)!=EOF)
	{
		x = (LL)floor((-1.0+sqrt(1.0+8.0*(double)ord))/2.0);
		y = x*(x+1LL)/2LL;
		if(y==ord) printf("1/%lld\n",x); else
		{
			z = x+1LL-(ord-y-1LL);
			printf("%lld/%lld\n",z,x+2LL-z);
		}
	}
	return 0;
}

