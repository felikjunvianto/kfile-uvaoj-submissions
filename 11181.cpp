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

int N, R, T;
double AB, B, prob[25];

void solve(int now, int left, int state, double &res)
{
	if(now == N)
	{
		if(left) return;
	
		double temp = 1;
		for(int j = 0; j < N; j++) 
			if(state & (1 << j)) temp *= prob[j]; else temp *= (1 - prob[j]);
	
		res += temp;
		return;		
	}
	
	if(left > N - now) return;
	if(state & (1 << now)) solve(now + 1, left, state, res); else
	{
		solve(now + 1, left, state, res);
		solve(now + 1, left - 1, state + (1 << now), res);
	}
}

int main()
{
	T = 0;
	while(1)
	{
		scanf("%d %d", &N, &R);
		if(!N && !R) break;
		
		for(int i = 0; i < N; i++) scanf("%lf", &prob[i]);
		
		printf("Case %d:\n", ++T);
		for(int x = 0; x < N; x++)
		{
			AB = B = 0;
			solve(0, R-1, 1 << x, AB);
			solve(0, R, 0, B);
			//printf("%.6lf %.6lf\n", AB, B);
			printf("%.6lf\n", AB / B);
		}
	}
	return 0;
}
