/**
 Algoritma : bagi petak-petak menjadi 2 himpunan yang saling pisah: himpunan semua petak(i,j) di mana
             i + j = 2n (himpunan kiri), dan himpunan semua petak(i, j) di mana i + j = 2n + 1 (himpunan kanan).
			 Kita hanya tertarik pada petak yang mengandung simbol '*'.
			 
			 Untuk setiap elemen di himpunan kiri, jika dia berbagi sisi dengan 1 atau lebih elemen di himpunan 
			 kanan, buat edge yang menhubungkan kedua elemen tersebut.
			 
			 Lakukan alternating path untuk mencari MCBM (misal nilainya M). Karena 1 buah matching meng-cover
			 2 titik pada grid, maka total satelit yang dibutuhkan adalah:
			 
			 = M + (|banyak elemen kiri| + |banyak elemen kanan| - 2 * M)
			 = |banyak simbol '*' pada peta| - M.
			
 */
 
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
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>
#define LL long long
#define INF 1000000000

using namespace std;

int dr[] = { 1, 0,-1, 0};
int dc[] = { 0, 1, 0,-1};

int T, R, C, par[410], num;
char grid[50][20];
vector<int> adjlist[410];
bool visited[410];

int augment(int now)
{
	if(visited[now]) return 0;
	visited[now] = true;
	
	for(int i = 0; i < adjlist[now].size(); i++)
	{
		int next = adjlist[now][i];
		if(par[next] == -1 || augment(par[next]))
		{
			par[next] = now;
			return 1;
		}
	}
	return 0;
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &R, &C);
		for(int i = 0; i < R; i++) scanf("%s", grid[i]);
		
		num = 0;
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
			{
				int node = i * C + j;
				adjlist[node].clear();
				if(grid[i][j] == '*') num++;
			}
		
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++) 
			{
				if(((i + j) % 2) || (grid[i][j] == 'o')) continue;
				
				int node = i * C + j;
				for(int k = 0; k < 4; k++)
				{
					int sr = i + dr[k], sc  = j + dc[k];
					if(sr < 0 || sc < 0 || sr >= R || sc >= C) continue;
					
					if(grid[sr][sc] == '*') adjlist[node].pb(sr * C + sc);
				}
			}
			
		memset(par, -1, sizeof(par));
		int ans = 0;
		for(int i = 0; i < R; i++) 
			for(int j = 0; j < C; j++)
				if(((i + j) % 2 == 0) && grid[i][j] == '*')
				{
					memset(visited, false, sizeof(visited));
					ans += augment(i * C + j);
				}
		
		printf("%d\n", num - ans);
	}
	return 0;
}

