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

int dr[] = {-1, 0, 1, 0};
int dc[] = { 0, 1, 0,-1};

int T, x, tile;
char inp[2];
string board;
map<string,string> path;
queue<string> q;

int main()
{
	path["123456780"] = "win";
	q.push("123456780");
	
	while(!q.empty())
	{
		string now = q.front();q.pop();
		for(x=0;x<9;x++) if(now[x]=='0') break;
		
		int r = x / 3, c = x % 3;
		
		for(int i = 0; i < 4; i++)
		{
			int sr = r + dr[i], sc = c + dc[i];
			if(sr>=0 && sc>=0 && sr <=2 && sc <=2)
			{
				int sx = sr*3 + sc;
				string next = now;
				swap(next[x], next[sx]);
				if(path.find(next)==path.end())
				{
					path[next] = now;
					q.push(next);
				}
			}
		} 
	}

	scanf("%d",&T);
	while(T--)
	{
		board.clear();
		for(x=0;x<9;x++) 
		{
			scanf("%s",inp);
			if(inp[0]>='0' && inp[0]<='9') board+=inp[0]; else board+='0';
		}
		
		if(path.find(board)==path.end()) printf("unsolvable\n"); else
		{
			while(board!="123456780")
			{
				string next = path[board];
				int i, j;
				
				for(i=0;i<9;i++) if(board[i]=='0') break;
				for(j=0;j<9;j++) if(next[j]=='0') break;
				
				switch(j-i)
				{
					case( 1) : printf("r"); break;
					case( 3) : printf("d"); break;
					case(-1) : printf("l"); break;
					case(-3) : printf("u"); break;
				}
				board = next;
			} printf("\n");
		} 
		
		if(T) printf("\n");
	}
	return 0;
}

