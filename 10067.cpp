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
	int a,b,c,d,t;
} cell;

int N,M,x,y,z,finish,ans;
bool visited[10][10][10][10];
int o[5];
queue<cell> q;

void baca()
{
	for(x=0;x<4;x++) scanf("%d",&o[x]);
	visited[o[0]][o[1]][o[2]][o[3]]=true;
}

int main()
{
	scanf("%d",&N);
	while(N--)
	{
		memset(visited,false,sizeof(visited));
		baca();

		while(!q.empty()) q.pop();
		q.push((cell){o[0],o[1],o[2],o[3]});
		
		finish=0;
		for(x=0;x<4;x++)
		{
			scanf("%d",&y);
			finish=finish*10+y;
		}
		
		scanf("%d",&M);
		while(M--) baca();
		
		ans=-1;
		while(!q.empty())
		{
			cell now = q.front();q.pop();
			int temp=0,n[]={now.a,now.b,now.c,now.d};
			for(x=0;x<4;x++) temp=temp*10+n[x];
			
			if(temp==finish) 
			{
				ans = now.t;
				break;
			}
			
			for(x=0;x<4;x++)
				for(y=-1;y<=1;y+=2)
				{
					n[x]=(n[x]+y+10)%10;
					if(!visited[n[0]][n[1]][n[2]][n[3]])
					{
						visited[n[0]][n[1]][n[2]][n[3]] = true;
						q.push((cell){n[0],n[1],n[2],n[3],now.t+1});
					}
					n[x]=(n[x]-y+10)%10;
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}

