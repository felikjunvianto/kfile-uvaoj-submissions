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

LL ans;
int N,x,y,z;
int bit[500100];
pair<LL,int> num[500100];

int query(int x)
{
	int ret=0;
	for(int i=x;i;i-=i&-i) ret+=bit[i];
	return(ret);
}

void update(int x,int v)
{
	for(int i=x;i<=N;i+=i&-i) bit[i]+=v;
}

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		for(x=0;x<N;x++)
		{
			scanf("%d",&y);
			num[x]=mp(y,N-x);
		}
		sort(num,num+N);
		memset(bit,0,sizeof(bit));
		
		ans=0LL;
		for(x=0;x<N;x++)
		{
			ans+=(LL)query(num[x].se-1);
			update(num[x].se,1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

