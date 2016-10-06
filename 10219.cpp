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
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>
#define LL long long
#define INF 1000000000

using namespace std;

int N, K;
double ans;

int main()
{
	while(scanf("%d %d", &N, &K) != EOF)
	{
		ans = 0;
		for(int i = N; i >= N - K + 1; i--) ans += log10(i);
		for(int i = K; i >= 1; i--) ans -= log10(i);
		
		printf("%d\n", (int)floor(ans + eps) + 1);
	}
	return 0;
}

