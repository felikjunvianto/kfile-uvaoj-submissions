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

int T,L,N,x;
int early,late;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&L,&N);
		early=late=0;
		while(N--)
		{
			scanf("%d",&x);
			early=max(min(x,L-x),early);
			late=max(max(x,L-x),late);
		}
		printf("%d %d\n",early,late);
	}
	return 0;
}

