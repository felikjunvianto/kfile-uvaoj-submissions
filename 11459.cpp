/*
   Algorithm : simulasikan saja permainan ular tangga nya sesuai yang diminta soal.
               
   Tricks : Jangan lupa setelah ada pemain yang mencapai petak ke 100, lemparan dadu berikutnya diabaikan
			(posisi pemain setelahnya jangan di-update)
*/

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

int T, A, B, C, i, j, turn;
int snakeladder[111];
int playerPos[1000010];
bool end;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&A, &B, &C);
		
		memset(snakeladder, -1, sizeof(snakeladder));
		while(B--)
		{
			scanf("%d %d", &i, &j);
			snakeladder[i] = j;
		}
		
		for(i = 1; i <= A; i++) playerPos[i] = 1;
		end = false; turn = 1;
		while(C--)
		{
			scanf("%d", &i);
			if(end) continue;
			
			int newPos = min(playerPos[turn] + i, 100);
			if(snakeladder[newPos] != -1) playerPos[turn] = snakeladder[newPos];
				else playerPos[turn] = newPos;
			
			if(playerPos[turn] == 100) end = true;
			turn++; if(turn > A) turn = 1;
		}
		
		for(i = 1; i <= A; i++) printf("Position of player %d is %d.\n", i, playerPos[i]);
	}
	return 0;
}

