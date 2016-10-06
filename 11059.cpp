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

int N,x,a,b,z;
int num[20];
LL temp,ans;

int main()
{
	z=1;
	while(scanf("%d",&N)!=EOF)
	{
		for(x=1;x<=N;x++) scanf("%d",&num[x]);
		
		ans=0LL;
		for(a=1;a<=N;a++)
			for(b=a;b<=N;b++)
			{
				temp=1LL;
				for(x=a;x<=b;x++) temp*=(LL)num[x];
				ans=max(ans,temp);
			}
		
		printf("Case #%d: The maximum product is %lld.\n\n",z++,ans);
	}
	return 0;
}

