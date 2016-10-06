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

int dr[] ={-1, 0, 1, 0};
int dc[] ={ 0, 1, 0,-1};

typedef struct
{
	int r,c,t;
} cell;

int bawah,samping,M,x,y,z,ans;
char grid[1010][1010];
queue<cell> q;
PII finish;

int main()
{
	while(1)
	{
		scanf("%d %d",&bawah,&samping);
		if(bawah+samping==0) break;
		
		for(y=0;y<bawah;y++)
			for(x=0;x<samping;x++) grid[y][x]='.';
			
		scanf("%d",&M);
		while(M--)
		{
			scanf("%d %d",&y,&z);
			while(z--)
			{
				scanf("%d",&x);
				grid[y][x]='#';
			}
		}
		
		scanf("%d %d",&y,&x);
		q.push((cell){y,x,0});
		scanf("%d %d",&finish.fi,&finish.se);
		
		ans=-1;
		while(!q.empty())
		{
			cell now=q.front();q.pop();
			if(mp(now.r,now.c)==finish) ans=now.t; else
				for(z=0;z<4;z++)
				{
					int sr=now.r+dr[z],sc=now.c+dc[z];
					if((sr>-1)&&(sc>-1)&&(sr<bawah)&&(sc<samping)&&(grid[sr][sc]=='.'))
					{
						grid[sr][sc]='#';
						q.push((cell){sr,sc,now.t+1});
					}
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}

