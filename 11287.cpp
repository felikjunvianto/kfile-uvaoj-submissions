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

LL p, a;

bool isPrime(LL num)
{
	for(LL i = 2LL; i * i <= num; i++) if(num % i == 0LL) return false;
	return true;
}

LL modExp(LL base, LL mod, LL exp)
{
	if(exp == 0LL) return 1LL;
	if(exp == 1LL) return base;

	LL halved = modExp(base, mod, exp / 2LL);
	LL ret = (halved * halved) % mod;
	if(exp & 1LL) ret = (ret * base) % mod;

	return ret;
}

int main()
{
	while(1)
	{
		scanf("%lld %lld", &p, &a);
		if(!p && !a) break;

		if(isPrime(p)) printf("no\n");
			else printf("%s\n", modExp(a, p, p) == a ? "yes" : "no");
	}
	return 0;
}

