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

int T,N,P,Q,x;
int weight,tot;
int egg[40];

int main()
{
	scanf("%d",&T);
	for(int i =1;i<=T;i++)
	{
		scanf("%d %d %d",&N,&P,&Q);
		for(x=0;x<N;x++) scanf("%d",&egg[x]);
		
		weight=tot=0;
		x=0;
		while(x<N && tot+1<=P && weight+egg[x]<=Q)
		{
			tot++;
			weight+=egg[x++];
		}
		printf("Case %d: %d\n",i,tot);
	}
	return 0;
}

