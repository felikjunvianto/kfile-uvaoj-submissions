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

LL N;

LL lowerbound(LL N)
{
	LL l = 10LL;
	LL r = 1111111111111111111LL;
	
	while(l<=r)
	{
		LL mid = (l+r)/2LL; 
		LL checknow  = mid-mid/10LL;
		LL checkprev = (mid-1LL)-(mid-1LL)/10LL;
		
		if(checknow==N)
		{
			if(checkprev<N) return mid;
				else r = mid-1;
		} else
			if(checknow>N) r = mid-1; else
				if(checknow<N) l = mid+1;
	}
}

int main()
{
	while(1)
	{
		scanf("%lld",&N);
		if(N==0LL) break;
		
		LL low = lowerbound(N);
		printf("%lld",low);
		if((low+1LL)-(low+1LL)/10LL==N) printf(" %lld",low+1LL);
		printf("\n");
	}
	return 0;
}

