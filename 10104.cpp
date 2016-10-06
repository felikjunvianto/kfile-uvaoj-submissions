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

int A,B,D,X0,Y0;

void extendedEuclid(int a,int b)
{
	if(!b)
	{
		X0 = 1;
		Y0 = 0;
		D = a;
		return;
	}
	extendedEuclid(b, a%b);
	int X1 = Y0;
	int Y1 = X0 - (a/b)*Y0;
	X0 = X1;
	Y0 = Y1;
}

int main()
{
	while(scanf("%d %d",&A,&B)!=EOF)
	{
		extendedEuclid(A,B);
		printf("%d %d %d\n",X0,Y0,D);
	}
	return 0;
}

