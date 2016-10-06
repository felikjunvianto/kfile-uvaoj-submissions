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

int T,N;
int i,x,player[20];

int main()
{
	scanf("%d",&T);
	for(i = 1; i <= T; i++)
	{
		scanf("%d",&N);
		for(x=1;x<=N;x++) scanf("%d",&player[x]);
		printf("Case %d: %d\n",i,player[(N+1)/2]);
	}
	return 0;
}

