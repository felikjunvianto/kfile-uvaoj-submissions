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

typedef struct {int p,l,t;} kot;

int N,i,x,y,z,t,ans;
int dp[100];
kot box[100];

int solve(int now)
{
	if(dp[now]!=-1) return(dp[now]);
	
	int &ret = dp[now] = box[now].t;
	for(int a=1;a<=N;a++) if(a!=now) 
		if((box[a].p<box[now].p)&&(box[a].l<box[now].l)) 
			ret = max(ret,solve(a)+box[now].t);
			
	return(ret);
}

int main()
{
	t=1;
	while(1)
	{
		scanf("%d",&N);
		if(N==0) break;
		
		N*=3;
		for(i=0;i<N;i+=3)
		{
			scanf("%d %d %d",&x,&y,&z);
			box[i+1]=(kot){min(x,y),max(x,y),z};
			box[i+2]=(kot){min(x,z),max(x,z),y};
			box[i+3]=(kot){min(y,z),max(y,z),x};
		}
		
		memset(dp,-1,sizeof(dp));
		ans=0;
		for(i=1;i<=N;i++) ans=max(ans,solve(i));
		
		printf("Case %d: maximum height = %d\n",t++,ans);
	}
	return 0;
}

