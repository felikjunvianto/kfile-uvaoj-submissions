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

int N,L;
double x;

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		for(L = 0; L <32;L++)
		{
			x = 1-N*exp(-L);
			if(fabs(x)<1) break;
		} 
		printf("%d %.8lf\n",L,x);
	}
	return 0;
}

