#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define INF 1000000000
#define eps 1e-9
#define PII pair<int,int> 

using namespace std;

int T,N,P,K;

int main()
{
	scanf("%d",&T);
	for(int i = 1;i<=T;i++)
	{
		scanf("%d %d %d",&N,&K,&P);
		P%=N;
		K=(K-1+P)%N;
		printf("Case %d: %d\n",i,K+1);
	}
	return 0;
}

