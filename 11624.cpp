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

typedef struct{int x,y,t;} cell;

int dx[]={-1, 0, 1, 0};
int dy[]={ 0,-1, 0, 1};

PII J;
int T,bawah,samping,x,y,z,ans;
char grid[1111][1111];
int fire[1111][1111];
queue<cell> q;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&bawah,&samping);getchar();
		memset(fire,-1,sizeof(fire));
		memset(grid,'@',sizeof(grid));
		for(y=1;y<=bawah;y++)
			for(x=1;x<=samping;x++)
			{
				scanf("%c",&grid[x][y]);
				switch(grid[x][y])
				{
					case('F') : q.push((cell){x,y,0});
								fire[x][y]=0;
								grid[x][y]='.';
								break;
								
					case('J') : J=mp(x,y);
								grid[x][y]='#';
								break;
				}
				if(x==samping) getchar();
			}
			
		while(!q.empty())
		{
			cell now=q.front();q.pop();
			for(z=0;z<4;z++)
			{
				int sx=now.x+dx[z],sy=now.y+dy[z];
				if((sx)&&(sy)&&(sx<=samping)&&(sy<=bawah))
					if((grid[sx][sy]=='.')&&(fire[sx][sy]==-1))
					{
						fire[sx][sy]=now.t+1;
						q.push((cell){sx,sy,now.t+1});
					}
			}
		}
		
		q.push((cell){J.fi,J.se,0});
		ans=INF;
		
		while(!q.empty())
		{
			cell now=q.front();q.pop();
			for(z=0;z<4;z++)
			{
				int sx=now.x+dx[z],sy=now.y+dy[z];
				if((sx>=0)&&(sy>=0)&&(sx<=samping+1)&&(sy<=bawah+1))
					if((grid[sx][sy]!='#')&&((fire[sx][sy]==-1)||(now.t+1<fire[sx][sy])))
					{
						if(grid[sx][sy]=='@') ans=min(ans,now.t+1);
						grid[sx][sy]='#';
						q.push((cell){sx,sy,now.t+1});
					}
			}
		}
		if(ans==INF) printf("IMPOSSIBLE\n"); else printf("%d\n",ans);
	}
	return 0;
}

