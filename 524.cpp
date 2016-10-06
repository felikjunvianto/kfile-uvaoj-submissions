#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define INF 1000000000
#define eps 1e-9
#define PII pair<int,int> 

using namespace std;

int N,val[20],x,y,z;
bool done[20],used[20],prime[40];
vector<vector<int> > ans[17];

void gen(int now)
{
	if((now==N) && (prime[val[0]+val[N-1]]))
	{
		vector<int> ring;
		for(int i=0;i<N;i++) ring.pb(val[i]);
		ans[N].pb(ring);
	} else
	
	for(int i=2;i<=N;i++) if((!used[i]) && (prime[val[now-1]+i]))
	{
		used[i]=true;
		val[now]=i;
		gen(now+1);
		used[i]=false;
	}
}

int main()
{
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(x=2;x*x<=40;x++) if(prime[x])
		for(y=2;x*y<=40;y++) prime[x*y]=false;
		
	int T=0;
	memset(done,false,sizeof(done));
	val[0]=1;
	used[1]=true;
	while(scanf("%d",&N)!=EOF)
	{
		if(!done[N]) gen(1);
		
		if(T) printf("\n");
		printf("Case %d:\n",++T);
		for(x=0;x<ans[N].size();x++)
			for(y=0;y<ans[N][x].size();y++)
				printf("%d%c",ans[N][x][y],y+1==(int)ans[N][x].size()?'\n':' ');
	}
	return 0;
}

