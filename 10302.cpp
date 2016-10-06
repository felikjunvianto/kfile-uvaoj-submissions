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

using namespace std;

long long sum[50010];
int x,y,z;

int main()
{
	sum[0]=0;
	for(x=1;x<=50000;x++) sum[x]=sum[x-1]+(long long)x*x*x;
	while(scanf("%d",&x)!=EOF) printf("%lld\n",sum[x]);
	return 0;
}

