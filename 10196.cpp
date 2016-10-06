#include <cstdio>
#include <cmath>
#include <cctype>
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

char board[10][10];
int r,c;
bool whiteCheck,blackCheck;

void Pawn(int r,int c)
{
	int dc[]={-1, 1};
	char target = (board[r][c]=='P'?'k':'K');
	for(int i=0;i<2;i++)
	{
		int sr=(board[r][c]=='P'?r-1:r+1);
		int sc=c+dc[i];
						
		if((sr<8)&&(sr>-1)&&(sc<8)&&(sc>-1)&&(board[sr][sc]==target))
		{
			(target=='k'?blackCheck = true:whiteCheck=true);
			break;
		}
	}
}

void Knight(int r,int c)
{
	int dc[]={-2,-1, 1, 2, 2, 1,-1,-2};
	int dr[]={ 1, 2, 2, 1,-1,-2,-2,-1};
	char target = (board[r][c]=='N'?'k':'K');
	for(int i=0;i<8;i++)
	{
		int sr=r+dr[i];
		int sc=c+dc[i];
						
		if((sr<8)&&(sr>-1)&&(sc<8)&&(sc>-1)&&(board[sr][sc]==target))
		{
			(target=='k'?blackCheck = true:whiteCheck=true);
			return;
		}
	}
}

void Bishop(int r,int c)
{
	int dc[]={ 1, 1,-1,-1};
	int dr[]={-1, 1, 1,-1};
	char target = (board[r][c]=='B'?'k':'K');
	for(int i=0;i<4;i++)
		for(int move = 1; move < 8; move++)
		{
			int sr=r+move*dr[i];
			int sc=c+move*dc[i];
			
			if((sr>7)||(sr<0)||(sc>7)||(sc<0)) break;
			if(board[sr][sc]!='.' && board[sr][sc]!=target) break;
			
			if(board[sr][sc]==target)
			{
				(target=='k'?blackCheck = true:whiteCheck=true);
				return;
			}
		}
}

void Rook(int r,int c)
{
	int dc[]={ 0, 1, 0,-1};
	int dr[]={-1, 0, 1, 0};
	char target = (board[r][c]=='R'?'k':'K');
	for(int i=0;i<4;i++)
		for(int move = 1; move < 8; move++)
		{
			int sr=r+move*dr[i];
			int sc=c+move*dc[i];
						
			if((sr>7)||(sr<0)||(sc>7)||(sc<0)) break;
			if(board[sr][sc]!='.' && board[sr][sc]!=target) break;
			
			if(board[sr][sc]==target)
			{
				(target=='k'?blackCheck = true:whiteCheck=true);
				return;
			}
		}
}

void Queen(int r,int c)
{
	char q = board[r][c];
	board[r][c]=(q=='Q'?'R':'r'); Rook(r,c);
	board[r][c]=(q=='Q'?'B':'b'); Bishop(r,c);
	board[r][c] = q;
}

int main()
{
	int i = 0;
	while(1)
	{
		for(r=0;r<8;r++) scanf("%s",board[r]);
		bool allblank = true;
		for(r=0;r<8 && allblank;r++)
			for(c=0;c<8 && allblank;c++) 
				if(board[r][c]!='.') allblank=false;
				
		if(allblank) break;
		
		whiteCheck = blackCheck = false;
		for(r=0;r<8;r++)
			for(c=0;c<8;c++) if(board[r][c]!='.')
				switch(tolower(board[r][c]))
				{
					case('p') : Pawn(r,c);break;
					case('n') : Knight(r,c);break;
					case('b') : Bishop(r,c);break;
					case('r') : Rook(r,c); break;
					case('q') : Queen(r,c); break;
				}
			
		printf("Game #%d: ",++i);
		if(!whiteCheck && !blackCheck) printf("no king is in check.\n");
		if(whiteCheck) printf("white king is in check.\n");
		if(blackCheck) printf("black king is in check.\n");
	}
	return 0;
}

