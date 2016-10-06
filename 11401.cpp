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

LL ans[1000010];
LL a,b;
int x;

int main()
{
	ans[3]=0LL;
	a=b=1LL;
	for(x=4;x<=1000000;x++) 
	{
		ans[x]=ans[x-1]+a;
		b+=(LL)x%2;
		a+=b;
	}
	
	while(1)
	{
		scanf("%d",&x);
		if(x<3) break;
		printf("%lld\n",ans[x]);
	}
	return 0;
}

