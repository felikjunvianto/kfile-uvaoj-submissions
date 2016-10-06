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

const LL MOD1 = 1000000007LL;
const LL MOD2 = 1000000009LL;

set<pair<LL, LL> > hashed;
LL base1[107], base2[107];
char msk[107];

int main()
{
	base1[0] = base2[0] = 1LL;
	for(int i = 1; i <= 100; i++)
	{
		base1[i] = (base1[i-1] * 256LL) % MOD1;
		base2[i] = (base2[i-1] * 256LL) % MOD2;
	}

	while(gets(msk))
	{
		int len = strlen(msk), smallestBug = INF;

		for(int wSize = 1; wSize <= len; wSize++)
		{
			hashed.clear();
			LL now1 = 0LL, now2 = 0LL;

			for(int i = 0; i < wSize; i++)
			{
				now1 = ((now1 * 256LL) % MOD1 + (LL) msk[i]) % MOD1;
				now2 = ((now2 * 256LL) % MOD2 + (LL) msk[i]) % MOD2;
			}

			hashed.insert(mp(now1, now2));
			for(int i = wSize; i < len; i++)
			{
				now1 = (now1 - (((LL) msk[i - wSize] * base1[wSize - 1]) % MOD1)) % MOD1;
				while(now1 < 0) now1 += MOD1;
				now1 = (((now1 * 256LL) % MOD1) + (LL) msk[i]) % MOD1;

				now2 = (now2 - (((LL) msk[i - wSize] * base2[wSize - 1]) % MOD2)) % MOD2;
				while(now2 < 0) now2 += MOD2;
				now2 = (((now2 * 256LL) % MOD2) + (LL) msk[i]) % MOD2;

				hashed.insert(mp(now1, now2));
				if(hashed.size() > wSize + 1) 
				{
					smallestBug = min(smallestBug, i + 1);
					break;
				}
			}
		}

		if(smallestBug != INF) printf("NO:%d\n", smallestBug);
			else printf("YES\n");
	}
	return 0;
}

