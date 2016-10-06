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

int dp[1130][20][190];
bool prime[1130];
vector<int> bil;
int N,K,x,y,z;

int solve(int sum,int used,int i)
{
	if((!sum)&&(!used)&&(i<=bil.size())) return(1);
	if(sum<0) return(0);
	if((!used)&&(sum)) return(0);
	if((!sum)&&(used)) return(0);
	if((i==bil.size())&&((used)||(sum))) return(0);
	
	if(dp[sum][used][i]==-1)
		dp[sum][used][i]=solve(sum,used,i+1)+solve(sum-bil[i],used-1,i+1);
	
	return(dp[sum][used][i]);
}

int main()
{
	memset(prime,true,sizeof(prime));
	memset(dp,-1,sizeof(dp));
	for(x=2;x*x<=1120;x++) if(prime[x])
	{
		z=2;
		while(x*z<=1120)
		{
			prime[x*z]=false;
			z++;
		}
	}
	for(x=2;x<=1120;x++) if(prime[x]) bil.pb(x);
	
	for(x=0;x<=1120;x++)
		for(y=0;y<=14;y++)
			for(z=0;z<=186;z++) N=solve(x,y,z);
			
	while(1)
	{
		scanf("%d %d",&N,&K);
		if(!(N|K)) break;
		
		printf("%d\n",solve(N,K,0));
	}
	return 0;
}

