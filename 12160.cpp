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

int s,f,num,x,y,ans;
int button[15];
bool visited[10010];
queue<PII> q;

int main()
{
	y=0;
	while(1)
	{
		scanf("%d %d %d",&s,&f,&num);
		if(s+f+num==0) break;
		
		for(x=0;x<num;x++) scanf("%d",&button[x]);
		memset(visited,false,sizeof(visited));
		q.push(mp(s,0));
		ans = INF;
		
		while(!q.empty())
		{
			PII now = q.front();q.pop();
			if(now.fi==f) ans=min(ans,now.se); else
				for(x=0;x<num;x++)
				{
					int next = (now.fi+button[x])%10000;
					if(!visited[next])
					{
						visited[next]=true;
						q.push(mp(next,now.se+1));
					}
				}
		}
		
		printf("Case %d: ",++y);
		if(ans==INF) printf("Permanently Locked\n"); else printf("%d\n",ans);
	}
	return 0;
}

