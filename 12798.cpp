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

int N, M, ans, numScore;
bool scoredAll;

int main()
{
	while(scanf("%d %d", &N, &M) != EOF)
	{
		ans = 0;
		while(N--)
		{
			scoredAll = true;
			for(int i = 0; i < M; i++)
			{
				scanf("%d", &numScore);
				scoredAll &= (numScore > 0);
			}
			
			if(scoredAll) ans++;
		}
		
		printf("%d\n", ans);
	}
	return 0;
}

