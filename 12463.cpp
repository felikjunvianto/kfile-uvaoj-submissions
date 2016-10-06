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

int a,b,c,d,e;

int main()
{
	while(1)
	{
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		if(!a && !b && !c && !d && !e) break;
		
		printf("%d\n",a*b*c*d*d*e*e);
	}
	return 0;
}

