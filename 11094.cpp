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
#define pi 2*acos(0.0)
#define PII pair<int,int> 

using namespace std;

int dr[] = { 1, 0,-1, 0};
int dc[] = { 0, 1, 0,-1};

int Row, Col;
char grid[30][30],land;
int r,c,rpos,cpos,ans,temp;
bool isnow,visited[30][30];

void ff(int r,int c)
{
	if(r==rpos && c==cpos) isnow=true;
	visited[r][c]=true;
	temp++;
	
	for(int i = 0;i < 4;i++)
	{
		int sr = r + dr[i], sc = (c + dc[i] + Col)%Col;
		if(sr>=0 && sr<Row && !visited[sr][sc] && grid[sr][sc]==land) ff(sr,sc);
	}
}

int main()
{
	while(scanf("%d %d",&Row,&Col)!=EOF)
	{
		for(r=0;r<Row;r++) scanf("%s",grid[r]);
		scanf("%d %d",&rpos,&cpos);
		land = grid[rpos][cpos];
		memset(visited,false,sizeof(visited));
		
		ans=0;
		for(r=0;r<Row;r++)
			for(c=0;c<Col;c++)
				if(grid[r][c]==land && !visited[r][c])
				{
					temp=0;isnow=false;
					ff(r,c);
					if(!isnow) ans = max(ans,temp);
				}
		printf("%d\n",ans);
	}
	return 0;
}

