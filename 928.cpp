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
	int r,c,seq,move;
} cell;

int dr[]={ 0, 1, 0,-1};
int dc[]={ 1, 0,-1, 0};

int T,Row,Column,r,c,i,ans;
char grid[310][310];
bool visited[310][310][5];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&Row,&Column);
		for(r=0;r<Row;r++) scanf("%s",grid[r]);
		
		for(r=0;r<Row;r++)
		{
			for(c=0;c<Column;c++) if(grid[r][c]=='S') break;
			if(grid[r][c]=='S') break;
		}
		
		memset(visited,false,sizeof(visited));
		visited[r][c][1]=true;
		ans=-1;
		queue<cell> q;
		q.push((cell){r,c,1,0});
		
		while(!q.empty())
		{
			cell now = q.front();q.pop();

			if(grid[now.r][now.c]=='E')
			{
				ans=now.move;
				break;
			}
			
			for(i=0;i<4;i++)
			{
				bool oke=true;
				int sr,sc,next;
				for(int m=1;m<=now.seq && oke;m++)
				{
					sr=now.r+m*dr[i];
					sc=now.c+m*dc[i];
					if((sr<0) || (sc<0) || (sr>=Row) || (sc>=Column) || (grid[sr][sc]=='#'))
						oke=false;
				}
				
				if(oke) 
				{
					sr=now.r+now.seq*dr[i];
					sc=now.c+now.seq*dc[i];
					next=(now.seq==3?1:now.seq+1);
					if(!visited[sr][sc][next])
					{
						visited[sr][sc][next]=true;
						q.push((cell){sr,sc,next,now.move+1});
					}
				}
			}
		}
		
		if(ans==-1) printf("NO\n"); else printf("%d\n",ans);
	}
	return 0;
}

