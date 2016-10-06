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

int dr[]={-1, 0, 1, 0};
int dc[]={ 0, 1, 0,-1};

typedef struct
{
	int r,c,dir,color,t;
} cell;

bool visited[30][30][4][5];
char grid[30][30];
int bawah,samping,x,y,z,c,ans;
PII start,finish;
queue<cell> q;

int main()
{
	c=0;
	while(1)
	{
		scanf("%d %d",&bawah,&samping);
		if(bawah+samping==0) break;
		
		for(y=0;y<bawah;y++) scanf("%s",grid[y]);
		for(y=0;y<bawah;y++)
			for(x=0;x<samping;x++)
			{
				memset(visited[y][x],false,sizeof(visited[y][x]));
				if(grid[y][x]=='S')
				{
					grid[y][x]='.';
					start=mp(y,x);
				}
				
				if(grid[y][x]=='T')
				{
					grid[y][x]='.';
					finish=mp(y,x);
				}
			}
			
		while(!q.empty()) q.pop();
		q.push((cell){start.fi,start.se,0,0,0});
		visited[start.fi][start.se][0][0]=true;
		
		ans=INF;
		while(!q.empty())
		{
			cell now=q.front();q.pop();
			if((mp(now.r,now.c)==finish)&&(!now.color)) 
			{
				ans=now.t;
				break;
			}
			
			//maju
			int sr=now.r+dr[now.dir],sc=now.c+dc[now.dir];
			if((sr>-1)&&(sc>-1)&&(sr<bawah)&&(sc<samping)&&(grid[sr][sc]=='.'))
				if(!visited[sr][sc][now.dir][(now.color+1)%5])
				{
					visited[sr][sc][now.dir][(now.color+1)%5]=true;
					q.push((cell){sr,sc,now.dir,(now.color+1)%5,now.t+1});
				}
				
			//hadap kiri kanan
			for(int i=-1;i<=1;i+=2)
			{
				int sdir=(now.dir+i+4)%4;
				if(!visited[now.r][now.c][sdir][now.color])
				{
					visited[now.r][now.c][sdir][now.color]=true;
					q.push((cell){now.r,now.c,sdir,now.color,now.t+1});
				}
			}
		}
		
		if(c) printf("\n");
		printf("Case #%d\n",++c);
		if(ans==INF) printf("destination not reachable\n");
			else printf("minimum time = %d sec\n",ans);
	}
	return 0;
}

