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

int T,x,y,n;

int solve(int p)
{
	if(p==0) return 1;
	if(p==1) return x;
	
	int halved = solve(p/2);
	int ret = (halved*halved)%n;
	if(p&1) ret = (ret*x)%n;
	return ret;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&x,&y,&n);
		x%=n;
		printf("%d\n",solve(y));
	}
	return 0;
}

