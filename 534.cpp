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

int N,T,i,j,k;
PII koor[205];
double adjmat[205][205];

int main()
{
	T = 0;
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		for(i=1;i<=N;i++) scanf("%d %d",&koor[i].fi,&koor[i].se);
		for(i=1;i<=N;i++)
			for(j=i;j<=N;j++) 
				if(i==j) adjmat[i][j]=0; else
				{
					double dx = koor[i].fi-koor[j].fi;
					double dy = koor[i].se-koor[j].se;
					adjmat[i][j]=adjmat[j][i]=sqrt(dx*dx+dy*dy);
				}
				
		for(k=1;k<=N;k++)
			for(i=1;i<=N;i++)
				for(j=1;j<=N;j++)
					adjmat[i][j]=min(adjmat[i][j],max(adjmat[i][k],adjmat[k][j]));
					
		printf("Scenario #%d\n",++T);
		printf("Frog Distance = %.3lf\n\n",adjmat[1][2]);
	}
	return 0;
}

