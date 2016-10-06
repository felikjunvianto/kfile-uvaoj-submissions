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

int T,x,y,z,cnt,len;
char ma[1100];
int dp[1010][1010];
vector<int> a,b;
map<string,int> idx;

bool huruf(char C)
{
	if((C>='A')&&(C<='Z')) return(true);
	if((C>='a')&&(C<='z')) return(true);
	if((C>='0')&&(C<='9')) return(true);
	return(false);
}

void parsing(vector<int> &c)
{
	len=strlen(ma);
	for(x=0;x<len;x++) if(!huruf(ma[x])) ma[x]=' ';
	x=-1;
	c.clear();
	string temp;
	while(x+1<len)
	{
		x++;
		if(ma[x]==' ') continue;
		temp.clear();
		while((x<len)&&(ma[x]!=' ')) temp+=ma[x++];
		if(idx.find(temp)==idx.end()) idx[temp]=cnt++;
		c.pb(idx[temp]);
	}
}

int solve(int A,int B)
{
	if((A==a.size())||(B==b.size())) return(0);
	if(dp[A][B]!=-1) return(dp[A][B]);
	
	int &ret = dp[A][B];
	if(a[A]==b[B]) ret = 1 + solve(A+1,B+1); else
		ret=max(solve(A,B+1),solve(A+1,B));
	return(ret);
}

int main()
{
	T=0;
	while(gets(ma))
	{
		cnt=0;
		idx.clear();
		parsing(a);
		gets(ma);
		parsing(b);
		
		printf("%2d. ",++T);
		if(a.empty()||b.empty()) printf("Blank!\n"); else
		{
			memset(dp,-1,sizeof(dp));
			printf("Length of longest match: %d\n",solve(0,0));
		}
		
	}
	return 0;
}

