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

typedef struct
{
	int x,y,r;
} circle;

int T,x,y,z;
int N,bts;
LL temp,ans;
circle crane[20];
bool collide[20][20];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(x=0;x<N;x++) scanf("%d %d %d",&crane[x].x,&crane[x].y,&crane[x].r);
		memset(collide,false,sizeof(collide));
		
		for(x=0;x<N;x++)
			for(y=x+1;y<N;y++)
			{
				int dx = crane[x].x - crane[y].x;
				int dy = crane[x].y - crane[y].y;
				int sr = crane[x].r + crane[y].r;
				
				if(dx*dx+dy*dy <= sr*sr)
					collide[x][y] = collide[y][x] = true;
			}
			
		ans = 0LL;
		bts = 1<<N;
		for(x=0;x<bts;x++)
		{
			vector<int> now;
			temp = 0LL;
			for(y=0;y<N;y++) if(x&(1<<y)) 
			{
				temp += (LL)crane[y].r*crane[y].r;
				now.pb(y);
			}
			
			bool oke = true;
			for(y=0;y<now.size() && oke;y++)
				for(z=y+1;z<now.size() && oke;z++) 
					if(collide[now[y]][now[z]]) oke = false;
			
			if(oke) ans = max(ans,temp);
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}

