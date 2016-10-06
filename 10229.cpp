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

typedef struct
{
	LL a,b,c,d;
} cell;

int N,M;
LL mod;
int ans;

cell bigmod(int now)
{
	if(now==1) return((cell){0,1,1,1});
	cell ans,bagi=bigmod(now/2);
	ans.a=((bagi.a*bagi.a)%mod+(bagi.b*bagi.c)%mod)%mod;
	ans.b=((bagi.a*bagi.b)%mod+(bagi.b*bagi.d)%mod)%mod;
	ans.c=((bagi.c*bagi.a)%mod+(bagi.d*bagi.c)%mod)%mod;
	ans.d=((bagi.c*bagi.b)%mod+(bagi.d*bagi.d)%mod)%mod;
	
	if(now&1)
	{
		cell temp=ans;
		ans.a=temp.b;
		ans.b=(temp.a+temp.b)%mod;
		ans.c=temp.d;
		ans.d=(temp.c+temp.d)%mod;
	}
	return(ans);
}

int main()
{
	while(scanf("%d %d",&N,&M)!=EOF)
	{
		mod=1LL<<M;
		if(N<2) printf("%lld\n",(LL)N%mod); else
		{
			cell mat=bigmod(N-1);
			printf("%lld\n",mat.d%mod);
		}
	}
	return 0;
}

