#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

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

int T,N,C,x,i,ans;

int main()
{
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&N);
		ans=0;
		while(N--)
		{
			scanf("%d",&x);
			ans=max(ans,x);
		}
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}

