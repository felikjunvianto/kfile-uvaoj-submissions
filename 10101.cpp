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

int coin[]={10000000,100000,1000,100};
string nama[]={"kuti","lakh","hajar","shata"};

int T,x;
LL num;

void konversi(LL now)
{
	for(int x=0;x<4;x++) if(now/(LL)coin[x])
	{
		konversi(now/(LL)coin[x]);
		printf(" %s",nama[x].c_str());
		now%=(LL)coin[x];
	}
	if(now) printf(" %lld",now);
}

int main()
{
	T = 0;
	while(scanf("%lld",&num)!=EOF)
	{
		printf("%4d.",++T);
		if(num==0LL) printf(" 0"); else konversi(num);
		printf("\n");
	}
	return 0;
}

