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

int N, K, factor[5], fIdx;

int main()
{
	scanf("%d", &N);
	for(int n = 1; n <= N; n++)
	{
		scanf("%d", &K);
		fIdx = 0;

		for(int i = 2; i * i <= K && fIdx < 2; i++) if(K % i == 0) factor[fIdx++] = i;

		printf("Case #%d: %d = %d * %d = %d * %d\n", n, K, factor[0], K / factor[0], factor[1], K / factor[1]);
	}
	return 0;
}

