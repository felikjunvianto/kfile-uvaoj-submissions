/*
	Algoritma: Tidak perlu membuat papan R * C (Memory Limit). Cukup simpan semua kolom dan baris yang
	           pernah diinjak setidaknya satu penjaga. Kemudian dari posisi Arif, coba diam dan gerakkan
			   ke 4 arah mata angin, jika setidaknya ada 1 posisi (diam atau bergerak) di mana posisi itu
			   menginjak kolom DAN baris yang belum pernah dijaga penjaga lain, maka Arif dapat lolos.
*/

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
#define PII pair<int,int> 

using namespace std;

int dr[] = {0, 1, 0,-1, 0};
int dc[] = {0, 0,-1, 0, 1};

int T, R, C, Prob;
int r, c;
bool lolos, row[10010], col[10010];

int main()
{
	T = 0;
	while(1)
	{
	    scanf("%d %d %d",&R, &C, &Prob);
	    if(!R && !C && !Prob) break;
	    
	    memset(row, false, sizeof(row));
	    memset(col, false, sizeof(col));
	    
	    while(Prob--)
        {
            scanf("%d %d", &r, &c);
            row[r] = col[c] = true;
        }
        
        scanf("%d %d",&r, &c);
        lolos = false;
        for(int i=0; i < 5 && !lolos; i++)
        {
            int sr = r + dr[i], sc = c + dc[i];
            if(sr < 0 || sc < 0 || sr >= R || sc >= C) continue;
            if(row[sr] || col[sc]) continue;
            
            lolos = true;
        }
        
        printf("Case %d: ", ++T);
        if(lolos) printf("Escaped again! More 2D grid problems!\n"); else
            printf("Party time! Let's find a restaurant!\n");
	}
	return 0;
}
