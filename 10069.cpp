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

vector<int> ONE (111,0),ZERO(111,0);

vector<int> dp[111][10010];
int T,lenpat,lenstr;
char str[10010],pat[111];

vector<int> solve(int ppat,int pstr)
{
	if(ppat==lenpat) return ONE;
	if(pstr==lenstr) return ZERO;
	if(dp[ppat][pstr].size()>0) return dp[ppat][pstr];
	
	vector<int> &ret = dp[ppat][pstr], addend;
	int x,carry;
	while(ret.size()<111) ret.pb(0);
	
	addend = solve(ppat,pstr+1);
	carry = 0;
	for(x=0;x<105;x++) 
	{
		ret[x] = ret[x]+addend[x]+carry;
		carry=ret[x]/10;
		ret[x]%=10;
	}
	
	if(pat[ppat]==str[pstr])
	{
		addend = solve(ppat+1,pstr+1);
		carry = 0;
		for(x=0;x<105;x++) 
		{
			ret[x] = ret[x]+addend[x]+carry;
			carry=ret[x]/10;
			ret[x]%=10;
		}
	}
	return ret;
}

int main()
{
	ONE[0] = 1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",str);lenstr=strlen(str);
		scanf("%s",pat);lenpat=strlen(pat);
		
		for(int i = 0; i<111;i++)
			for(int j=0;j<10010;j++)
				dp[i][j].clear();
			
		vector<int> ans = solve(0,0);
		
		int x,y;
		for(x=ans.size()-1;x>=0;x--) if(ans[x]) break;
		for(y=x;y>=0;y--) printf("%d",ans[y]);
		printf("\n");
	}
	return 0;
}

