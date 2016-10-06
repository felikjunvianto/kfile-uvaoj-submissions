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
#define pi 2*acos(0.0)
#define PII pair<int,int> 

using namespace std;

int dp[5000010], S;
int L,H,temp,V;

int calc(LL N)
{
	int ret = 0;
	while(N>1LL)
	{
		ret++;
		if(N&1LL) N = N*3LL+1LL;
			else N/=2LL;
	} return ret;
}

int solve(LL N)
{
	if(N>=5000000LL) return calc(N);
	if(N==1LL) return 0;
	if(dp[(int)N]!=-1) return dp[N];
	
	int &ret = dp[(int)N] = 0;
	if(N&1LL) ret = 1 + solve(N*3LL+1LL);
		else ret = 1 + solve(N/2LL);
		
	return ret;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	while(1)
	{
		scanf("%d %d",&L,&H);
		if(!L && !H) break;
		
		if(L>H) swap(L,H);
		V=-1;
		S=0;
		
		for(int i = L; i <=H;i++)
		{
			temp = solve((LL)i);
			if(i==1) temp = 3;
			
			if(V==-1 || S<temp) 
			{
				V = i;
				S = temp;
			}
		}
		
		printf("Between %d and %d, %d generates the longest sequence of %d values.\n",L,H,V,S);
	}
	return 0;
}

