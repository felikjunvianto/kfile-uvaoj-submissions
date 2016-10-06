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

int dx[]={-1, 0, 1, 0};
int dy[]={ 0, 1, 0,-1};

int T,bawah,samping,x,y,ans;
int peta[110][110];
int dp[110][110];
char nama[200];

int solve(int x,int y)
{
	if(dp[x][y]!=-1) return(dp[x][y]);
	
	int &ret = dp[x][y] = 1;
	for(int t=0;t<4;t++)
	{
		int sx=x+dx[t],sy=y+dy[t];
		if((sx>=1)&&(sx<=samping)&&(sy>=1)&&(sy<=bawah))
			if(peta[sx][sy]<peta[x][y]) ret=max(ret,solve(sx,sy)+1);
	}
	return(ret);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s %d %d",nama,&bawah,&samping);
		for(y=1;y<=bawah;y++)
			for(x=1;x<=samping;x++) scanf("%d",&peta[x][y]);
			
		memset(dp,-1,sizeof(dp));
		ans=0;
		for(y=1;y<=bawah;y++)
			for(x=1;x<=samping;x++) ans=max(ans,solve(x,y));
			
		printf("%s: %d\n",nama,ans);
	}
	return 0;
}

