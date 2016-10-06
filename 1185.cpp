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

int T,x;
double dig[10000010];

int main()
{
	dig[1]=0;
	for(x=2;x<=10000000;x++) dig[x]=dig[x-1]+log10(x)+eps;
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&x);
		printf("%d\n",(int)floor(dig[x])+1);
	}
	return 0;
}

