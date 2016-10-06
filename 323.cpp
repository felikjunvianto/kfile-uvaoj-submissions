/*
	Algoritma: Algoritma pada soal ini dapat dibagi menjadi 3 bagian utama, yaitu:
			   1. Mencari nilai |D - P| yang paling kecil.
			   2. Untuk nilai |D - P| terkecil yang mungkin, mencari nilai D + P
			   3. Tracing untuk mencari konfigurasi kandidat yang diambil
			   
			   Untuk mencari nilai |D - P| terkecil yang mungkin, gunakan DP dengan state (sekarang orang ke berapa,
			   berapa orang lain yang harus diambil, dan nilai D - P saat ini dengan offset 400 agar nilainya
			   tidak pernah negatif). 
			   Base case: jika tidak ada yang perlu diambil lagi, return |(nilai D - P saat ini) - 400|
			   
			              jika orang sudah habis namun masih perlu mengambil orang, return INF. (pruning tambahan
						  bisa dengan jika banyak orang yang masih perlu diambil melebihi orang yang tersisa, tidak
						  mungkin ada solusi. Potong kemungkinan tersebut karena tidak akan menghasilkan jawaban.
						  
			   Recurrence: Untuk orang yang saat ini diperiksa, ada 2 kemungkinan; ambil atau tidak. Lalu bandingkan
				   		   kedua jawabannya, dan ambil yang terkecil.
							
			   Untuk mencari nilai D + P terbesar yang mungkin, gunakan DP dengan state (sekarang orang ke berapa,
			   berapa orang lain yang harus diambil, dan nilai D - P saat ini dengan offset 400 agar nilainya
			   tidak pernah negatif). 
			   Base case: jika tidak ada yang perlu diambil lagi, periksa apakah nilai |(nilai D - P saat ini) - 400|
			              sama dengan nilai terkecil yang mungkin yang sudah dicari sebelumnya. Jika ya return 0, jika
						  tidak return INF.
						  
				    	  jika orang sudah habis namun masih perlu mengambil orang, return INF. (pruning tambahan
						  bisa dengan jika banyak orang yang masih perlu diambil melebihi orang yang tersisa, tidak
						  mungkin ada solusi. Potong kemungkinan tersebut karena tidak akan menghasilkan jawaban.
						  
			   Recurrence: Untuk orang yang saat ini diperiksa, ada 2 kemungkinan; ambil atau tidak. Lalu bandingkan
						   kedua jawabannya, dan ambil yang terbesar (lalu set path state DP saat ini ke state berikutnya
						   yang menghasilkan nilai terbesar tersebut).
						   
			   Berdasarkan path yang sudah diset saat melakukan DP kedua, lakukan tracing hingga mencapai akhir dari path
			   tersebut (disimbolkan dengan {-1, -1, -1}). Cetak jumlah P dan D, lalu cetak semua kandidat yang digunakan
	
	Credits to William Gozali for giving hints.
*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>

#define fi first
#define se second
#define LL long long
#define mp make_pair
#define pb push_back
#define INF 1000000000
#define eps 1e-9
#define PII pair<int,int> 

using namespace std;

typedef struct { int now, left, diff; } par;

par next[202][22][808];
int dp[202][22][808];
int p[202], d[202];
int N, M, minDiff, maxSum;

int solve(int now, int left, int diff)
{
	if(!left) return abs(diff - 400);
	if((now == N && left) || (N - now < left)) return INF;
	
	if(dp[now][left][diff] == -1)
	{
		int skip = solve(now + 1, left, diff);
		int take = solve(now + 1, left - 1, diff + d[now] - p[now]);
		
		if(skip < take) dp[now][left][diff] = skip;
			else dp[now][left][diff] = take;
	}
	return dp[now][left][diff];
}

int findMax(int now, int left, int diff)
{
	if(!left) 
	{
		if(abs(diff-400) != minDiff) return -INF;
		next[now][left][diff] = (par) {-1, -1, -1};
		return 0;		
	}
	if((now == N && left) || (N - now < left)) return -INF;
	if(dp[now][left][diff] != -1) return dp[now][left][diff];
	
	int &ret = dp[now][left][diff];
	int skip = findMax(now + 1, left, diff);
	int take = findMax(now + 1, left - 1, diff + d[now] - p[now]) + d[now] + p[now];
	
	if(skip > take)
	{
		ret = skip;
		next[now][left][diff] = (par) {now + 1, left, diff};
	} else
	{
		ret = take;
		next[now][left][diff] = (par) {now + 1, left - 1, diff + d[now] - p[now]};
	}
	
	return ret;
}

int main()
{
	int T = 0;
    while(1)
    {
    	scanf("%d %d", &N, &M);
    	if(!N && !M) break;
    	
    	for(int i = 0; i < N; i++) scanf("%d %d", &p[i], &d[i]);
    	
    	memset(dp, -1, sizeof(dp));
    	minDiff = abs(solve(0, M, 400));
    	
    	memset(dp, -1, sizeof(dp));
    	maxSum = findMax(0, M, 400);
    	
		par now = (par) {0, M, 400};
		vector<int> cand; 
		int P = 0, D = 0;
		while(1)
		{
			par move = next[now.now][now.left][now.diff];
			if(move.now == -1 && move.left == -1 && move.diff == -1) break;
			
			if(now.left > move.left) 
			{
				cand.pb(now.now + 1);
				P += p[now.now]; D += d[now.now];
			}
			now = move;
		} 
		
		printf("Jury #%d\n", ++T);
		printf("Best jury has value %d for prosecution and value %d for defence:\n", P, D);
		for(int i = 0; i < cand.size(); i++) printf(" %d", cand[i]);
		printf("\n\n");
    }
    return 0;
}

