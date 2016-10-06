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

int N,x;

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		int ans = N;
		for(x=2;x*x<=N;x++) if(N%x==0)
		{
				ans-=ans/x;
				while(N%x==0) N/=x;
		}
		if(N!=1) ans-=ans/N;
		printf("%d\n",ans);
	}
	return 0;
}

