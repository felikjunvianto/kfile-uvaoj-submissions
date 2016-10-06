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

int testCase;
int N,E,T;
int i,j,k;
int edge;
int adjmat[111][111];

int main()
{
	scanf("%d",&testCase);
	while(testCase--)
	{
		scanf("%d",&N);
		scanf("%d",&E);
		scanf("%d",&T);
		scanf("%d",&edge);
		
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				adjmat[i][j]=(i==j?0:INF);
				
		while(edge--)
		{
			scanf("%d %d %d",&i,&j,&k);
			adjmat[i][j]=min(adjmat[i][j],k);
		}
		
		for(k=1;k<=N;k++)
			for(i=1;i<=N;i++)
				for(j=1;j<=N;j++)
					adjmat[i][j]=min(adjmat[i][j],adjmat[i][k]+adjmat[k][j]);
					
		int cnt=0;
		for(k=1;k<=N;k++) if(adjmat[k][E]<=T) cnt++;
		printf("%d\n",cnt);
		if(testCase) printf("\n");
	}
	return 0;
}

