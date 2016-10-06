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

int T,N,x;
int score[100010];
int smallest,diff;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(x=1;x<=N;x++) scanf("%d",&score[x]);
		
		smallest=min(score[N-1],score[N]);
		diff=score[N-1]-score[N];
		for(x=N-2;x;x--)
		{
			diff=max(diff,score[x]-smallest);
			smallest=min(smallest,score[x]);
		}
		printf("%d\n",diff);
	}
	return 0;
}

