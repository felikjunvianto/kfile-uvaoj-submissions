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

int T;
int dp[21][21];
bool awal;

int solve(int a,int b)
{
	if(a==b) return 0; //only one person
	if(a>b) return 1; //no set of person created in this state
	if(a+1==b) return 1; //only one pair remains
	if(dp[a][b]!=-1) return dp[a][b]; //already calculated before
	
	int &ret = dp[a][b]=0;
	for(int i=a+1;i<=b;i++) ret+=solve(a+1,i-1)*solve(i+1,b);
	return ret;
}

int main()
{
	awal=true;
	memset(dp,-1,sizeof(dp));
	while(scanf("%d",&T)!=EOF)
	{
		if(!awal) printf("\n");
		awal=false;
		printf("%d\n",solve(1,2*T));
	}
	return 0;
}

