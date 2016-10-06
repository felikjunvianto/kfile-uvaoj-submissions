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

int x,T,i,p,q;
int two[20];
int large,small;
vector<LL> num[20];
queue<pair<LL,int> > que;

int main()
{
	two[0]=1;
	for(x=1;x<=17;x++) two[x]=two[x-1]<<1;
	
	que.push(mp(1LL,1));
	que.push(mp(2LL,1));
	
	while(!que.empty())
	{
		pair<LL,int> now = que.front();que.pop();
		num[now.se].pb(now.fi);
		
		if(now.se<17)
		{
			now.fi*=10LL;now.se++;
			que.push(mp(now.fi+1LL,now.se));
			que.push(mp(now.fi+2LL,now.se));
		}
	}
	
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d",&p,&q);
				
		small=large=-1;
		for(x=0;x<num[p].size();x++) if(num[p][x]%(LL)two[q]==0)
		{
			small=x;
			break;
		}
		
		for(x=num[p].size()-1;x>=0;x--) if(num[p][x]%(LL)two[q]==0)
		{
			large=x;
			break;
		}
		
		printf("Case %d: ",i);
		if(small==-1 && large==-1) printf("impossible\n"); else
			if(small==large) printf("%lld\n",num[p][small]); else
				printf("%lld %lld\n",num[p][small],num[p][large]);
	}
	return 0;
}

