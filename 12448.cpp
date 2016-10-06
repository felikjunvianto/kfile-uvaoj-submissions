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

LL dp[11][11],tot;
int T,N,K,M;

LL solve(int now,int dis)
{
	if(now==M && dis==K) return 1LL;
	if(now==M && dis!=K) return 0LL;
	if(dp[now][dis]!=-1LL) return dp[now][dis];
	
	LL &ret = dp[now][dis] = 0LL;
	
	//taking already taken value
	if(dis) ret=ret+dis*solve(now+1,dis);
	
	//taking new value
	if(dis+1<=K) ret=ret+(N-dis)*solve(now+1,dis+1);
	return ret;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&N,&M,&K);
		memset(dp,-1LL,sizeof(dp));
		LL cnt = solve(0,0);
		LL tot = 1LL;
		for(int x=0;x<M;x++) tot*=(LL)N;
		
		LL GCD = __gcd(cnt,tot);
		cnt/=GCD;
		tot/=GCD;
		
		if(!cnt) printf("0\n"); else
		if(cnt==tot) printf("1\n"); else
		printf("%lld/%lld\n",cnt,tot);
	}
	return 0;
}

