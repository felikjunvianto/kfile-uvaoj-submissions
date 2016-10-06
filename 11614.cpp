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

int N, res;
LL K;

int main()
{
	scanf("%d",&N);
	while(N--)
	{
		scanf("%lld",&K);
		res=(int) floor((-1+sqrt(1LL+8LL*K))/2.0);
		printf("%d\n",res);
	}
	return 0;
}

