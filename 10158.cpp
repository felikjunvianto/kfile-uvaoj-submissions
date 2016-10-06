/*
	Algoritma : setiap node menyimpan pointer ke orang tua dan musuh saat ini. Pada awalnya setiap
	            node diberi musuh dummy (1 dengan N, 2 dengan N + 1, dst) agar setiap node dapat
	            dipandang sebagai 1 set dari himpunan teman dan musuh. 
	
	Lemma : setiap set maksimal hanya bermusuhan dengan 1 set lain, sehingga saat penggabungan teman,
	        musuhnya juga harus digabung, begitu pula sebaliknya.
	        
	Untuk mengecek apakah 2 node teman atau musuh, cukup melihat apakah orangtua kedua node sama (untuk areFriends())
	dan apakah orangtua salah satu node = orangtua musuh node yang lain (untuk areEnemies()).
	
	Credits to Kemal Maulana & Ashar Fuadi for giving hints.
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

int N;
int par[20010], ene[20010];
int c, i, j;

int find(int k)
{
	if(par[k] == -1) par[k] = k; else
	{
		int tk = k;
		while(tk != par[tk]) tk = par[tk];
		par[k] = tk;
	}
	return par[k];
}

int main()
{
	scanf("%d", &N);
	memset(par, -1, sizeof(par));
	for(int a = 0; a < N; a++) 
	{
		ene[a] = a + N;
		ene[a + N] = a;
	}
	
	while(1)
	{
		scanf("%d %d %d", &c, &i, &j);
		if(!c && !i && !j) break;
		
		switch(c)
		{
			case(1) : if(find(i) == find(ene[j]) || find(ene[i]) == find(j)) printf("-1\n"); else 
					  {
					  	par[find(i)] = find(j);
					  	par[find(ene[i])] = find(ene[j]);
					  }
					  break;
			
			case(2) : if(find(i) == find(j) || find(ene[i]) == find(ene[j])) printf("-1\n"); else
					  {
					  	par[find(i)] = find(ene[j]);
					  	par[find(j)] = find(ene[i]);
					  }
					  break;
					  
			case(3) : printf("%d\n", (find(i) == find(j) || find(ene[i]) == find(ene[j])) ? 1 : 0); break;
			
			case(4) : printf("%d\n", (find(i) == find(ene[j]) || find(ene[i]) == find(j)) ? 1 : 0); break;
		}
	}
	return 0;
}
