#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>

#define LL long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000000
#define EPS 1e-9
#define PII pair<int,int> 
#define PI 2*acos(0.0)

using namespace std;

int bit[200010], poten[200010];
int N, a, b;
char com[5];

void update(int x, int val)
{
	for(int i = x; i <= N; i += i & -i) bit[i] += val;
}

int query(int x)
{
	int ret = 0;
	for(int i = x; i; i -= i & -i) ret += bit[i];
	return ret;
}

int main()
{
	int T = 0;
	while(1)
	{
		scanf("%d", &N);
		if(!N) break;
		
		memset(bit, 0, sizeof(bit));
		for(int i = 1; i <= N; i++)
		{
			scanf("%d", &poten[i]);
			update(i, poten[i]);
		}
		
		if(T) printf("\n");
		printf("Case %d:\n", ++T);
		
		while(1)
		{
			scanf("%s", com);
			if(com[0] == 'E') break; else
			
			if(com[0] == 'M') 
			{
				scanf("%d %d", &a, &b);
				printf("%d\n", query(b) - query(a - 1));
			} else
			
			if(com[0] == 'S')
			{
				scanf("%d %d", &a, &b);
				update(a, -poten[a]);
				update(a, b);
				poten[a] = b;
			}
		}
	}
	return 0;
}


