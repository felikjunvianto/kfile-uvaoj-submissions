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

LL N, a, plus, dig;

int main()
{
	while(scanf("%lld",&N)!=EOF)
	{
		a = dig = 1LL;
		while(N> 9LL*a*dig)
		{
			N-= 9LL*a*dig;
			a*=10LL;
			dig++;
		} N--;
		
		a += N/dig;
		
		char temp[10]; sprintf(temp,"%lld",a);
		printf("%c\n",temp[N%dig]);
	}
	return 0;
}

