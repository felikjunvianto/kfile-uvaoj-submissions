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

unsigned int dp[77][77];
int N,T,P,C;

unsigned int solve(int now, int left)
{
	if((now==N)&&(left==0)) return 1u;
	if((now==N)&&(left!=0)) return 0u;
	if(dp[now][left]!=-1) return dp[now][left];
	
	unsigned int &ret = dp[now][left] = 0u;
	for(int x=0;x<=left;x++) ret+=solve(now+1,left-x);
	return ret;
}

int main()
{
	scanf("%d",&C);
	while(C--)
	{
		scanf("%d %d %d",&N,&T,&P);
		T-=N*P;
		if(T<0) printf("0\n"); else
		{
			memset(dp,-1,sizeof(dp));
			printf("%u\n",solve(0,T));
		}
	}
	return 0;
}

