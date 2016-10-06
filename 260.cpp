#include <cstdio>
#include <cstdlib>
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
#include <set>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int> 
#define pdd pair<double,double>
#define LL long long

#define PI 2*acos(0.0)
#define EPS 1e-9
#define INF 1000000000

using namespace std;

int dr[] = {-1, 0,-1, 1, 0, 1};
int dc[] = {-1,-1, 0, 0, 1, 1};

int N;
char grid[202][202];
bool visited[202][202];
queue<pii> Q;

int main()
{
	int T = 0;
	while(1)
	{
		scanf("%d", &N);
		if(!N) break;

		for(int i = 0; i < N; i++) scanf("%s", grid[i]);
		memset(visited, false, sizeof(visited));

		for(int c = 0; c < N; c++) if(grid[0][c] == 'b')
		{
			Q.push(mp(0, c));
			visited[0][c] = true;
		}

		while(!Q.empty())
		{
			pii now = Q.front(); Q.pop();

			for(int i = 0; i < 6; i++)
			{
				int sr = now.fi + dr[i], sc = now.se + dc[i];
				if(sr >= 0 && sc >= 0 && sr < N && sc < N && grid[sr][sc] == 'b' && !visited[sr][sc])
				{
					Q.push(mp(sr, sc));
					visited[sr][sc] = true;
				}
			}
		}

		bool blackWin = false;
		for(int c = 0; c < N && !blackWin; c++) blackWin |= visited[N-1][c];

		printf("%d %c\n", ++T, blackWin ? 'B' : 'W');
	}
	return 0;
}

