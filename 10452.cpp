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

int dr[]={ 0,-1, 0};
int dc[]={-1, 0, 1};
char path[]={'@','I','E','H','O','V','A','#'};
string com[]={"left","forth","right"};

int T,i,x;
int W,H,r,c;
char board[10][10];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&H,&W);
		for(r=0;r<H;r++) scanf("%s",board[r]);
		
		for(r=0;r<H;r++)
		{
			for(c=0;c<W;c++) if(board[r][c]=='@') break;
			if(board[r][c]=='@') break;
		}
		
		for(i=0;i<7;i++)
			for(x=0;x<3;x++)
			{
				int sr=r+dr[x];
				int sc=c+dc[x];
			
				if(sr>-1 && sc>-1 && sr<H && sc<W && board[sr][sc]==path[i+1])
				{
					if(i) printf(" ");
					printf("%s",com[x].c_str());
					r=sr,c=sc;
					break;
				}
			}

		printf("\n");
	}
	return 0;
}

