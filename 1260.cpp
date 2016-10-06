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

int T, N, sum, A;
int bit[5010];

int query(int A)
{
	int ret = 0;
	for(int i = A; i; i -= i & -i) ret += bit[i];
	return ret;
}

void update(int x)
{
	for(int i = x; i <= 5000; i += i & -i) bit[i]++;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		memset(bit,0,sizeof(bit));
		sum = 0;
		
		while(N--)
		{
			scanf("%d",&A);
			sum += query(A);
			update(A);
		}
		
		printf("%d\n",sum);
	}
	return 0;
}

