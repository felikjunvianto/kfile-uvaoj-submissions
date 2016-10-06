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

LL dig;
int i;

int main()
{
	i=0;
	while(1)
	{
		scanf("%lld",&dig);
		if(!dig) break;
		
		printf("Case %d: %lld\n",++i,(LL)ceil((3.0+sqrt(9LL+8LL*dig))/2.0));
	}
	return 0;
}

