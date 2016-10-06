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

const int MAXN = 46345;

bool prime[MAXN];
int NPrime, num[4800], N, ans;

int main()
{
	memset(prime, true, sizeof(prime));
	for(int i = 2; i * i <= MAXN; i++) if(prime[i])
		for(int j = 2; i * j <= MAXN; j++) prime[i * j] = false;
	
	NPrime = 0;
	for(int i = 2; i < MAXN; i++) if(prime[i]) num[NPrime++] = i;
	
	while(scanf("%d", &N) != EOF)
	{
		ans = N;
		for(int i = 0; i < NPrime && num[i] * num[i] <= N; i++) if(N % num[i] == 0)
		{
			ans = ans / num[i] * (num[i] - 1);
			while(N % num[i] == 0) N /= num[i];
		}
		if(N > 1) ans = ans / N * (N - 1);
		
		printf("%d\n", (ans + 1) >> 1);
	}
	return 0;
}

