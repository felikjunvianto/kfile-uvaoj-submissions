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

int cow,car,show;

int main()
{
	while(scanf("%d %d %d",&cow,&car,&show)!=EOF)
	{
		printf("%.5lf\n",(cow*car+car*(car-1))/(double)((cow+car)*(cow+car-1-show)));
	}
	return 0;
}

