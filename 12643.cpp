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

int N, i, j;

int main()
{
	while(scanf("%d %d %d", &N, &i, &j) != EOF)
	{
		int round = 1;
		while((i + 1) >> 1 != (j + 1) >> 1)
		{
			i = (i + 1) >> 1;
			j = (j + 1) >> 1;
			round++;
		}
		
		printf("%d\n", round);
	}
	return 0;
}

