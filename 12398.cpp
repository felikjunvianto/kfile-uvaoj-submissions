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

int dr[] = { 1, 0,-1, 0};
int dc[] = { 0, 1, 0,-1};

char msk[222];
int len,x,i,r,c,y,z;
int board[5][5];

int main()
{
	i = 0;
	while(gets(msk))
	{
		len=strlen(msk);
		memset(board,0,sizeof(board));
		for(x=len-1;x>=0;x--) 
		{
			z = msk[x]-'a';
			r = z / 3;
			c = z % 3;
			board[r][c] = (board[r][c]+1)%10;
			
			for(y = 0; y < 4;y++)
			{
				int rs = r + dr[y], cs = c + dc[y];
				if(rs>=0 && cs>=0 && rs<3 && cs<3)
					board[rs][cs] = (board[rs][cs]+1)%10;
			}
		}
		
		printf("Case #%d:\n",++i);
		for(r=0;r<3;r++)
			for(c=0;c<3;c++)
				printf("%d%c",board[r][c],c==2?'\n':' ');
	}
	return 0;
}

