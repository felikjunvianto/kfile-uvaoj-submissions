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

using namespace std;

int dp[110][110];
char dad[110],mom[110];
int p_dad,p_mom;
int t;

int lcs(int a,int b)
{
	if((a<p_dad)&&(b<p_mom))
	{
		if(dp[a][b]==-1)
			if(dad[a]==mom[b]) dp[a][b]=1+lcs(a+1,b+1);
				else dp[a][b]=max(lcs(a,b+1),lcs(a+1,b));
		return(dp[a][b]);
	} else return(0);
}

int main()
{
	t=0;
	do
	{
		gets(dad);
		if(dad[0]=='#') break;
		
		gets(mom);
		p_dad=strlen(dad);
		p_mom=strlen(mom);
		memset(dp,-1,sizeof(dp));
		printf("Case #%d: you can visit at most %d cities.\n",++t,lcs(0,0));
	}while(dad[0]!='#');
	return 0;
}

