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

int T, L;
double R, W, circle;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d", &L);
		W = L * 0.6;
		R = L * 0.2;
		circle = pi * R * R;
		
		printf("%.2lf %.2lf\n", circle, W * L - circle);
	}
	return 0;
}

