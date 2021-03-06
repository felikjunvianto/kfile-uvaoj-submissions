#include <cstdio>
#include <cstdlib>
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
#include <set>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int> 
#define pdd pair<double,double>
#define LL long long

#define PI 2*acos(0.0)
#define EPS 1e-9
#define INF 1000000000

using namespace std;

int T, N, M;

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &N, &M);
		int ans = 0;

		while(N >= M)
		{
			ans += N / M;
			N = (N / M) + (N % M);
		}

		if(N != 1) printf("cannot do this\n"); else printf("%d\n", ans);
	}
	return 0;
}

