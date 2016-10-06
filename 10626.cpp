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

int T, coke, ten, five, one, total;
int dp[160][260][60];

int solve(int cola, int lima, int sep)
{
	if(cola == coke) return 0;
	if(dp[cola][lima][sep] != -1) return dp[cola][lima][sep];
	
	int &ret = dp[cola][lima][sep] = INF;
	int satu = total - cola * 8 - lima * 5 - sep * 10;
	if(sep > 0) ret = min(ret, solve(cola + 1, lima, sep - 1) + 1);
	if(sep > 0 && satu >= 3) ret = min(ret, solve(cola + 1, lima + 1, sep - 1) + 4);
	if(lima >= 2) ret = min(ret, solve(cola + 1, lima - 2, sep) + 2);
	if(lima > 0 && satu >= 3) ret = min(ret, solve(cola + 1, lima - 1, sep) + 4);
	if(satu >= 8) ret = min(ret, solve(cola + 1, lima, sep) + 8);
	
	return ret;
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d %d", &coke, &one, &five, &ten);
		total = ten * 10 + five * 5 + one;
		
		memset(dp, -1, sizeof(dp));
		printf("%d\n", solve(0, five, ten));
	}
	return 0;
}

