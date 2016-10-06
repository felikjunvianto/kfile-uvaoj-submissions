/**
 Algoritma : Lakukan DP knapsack dengan kondisi awal pemegang saham yang ingin dicari keuntungan maksimalnya
             sudah harus terambil. Lalu looping dari 50.01% hingga 100.00% untuk mencari persentase terkecil
			 yang mungkin dibentuk.
			 
			 Jawaban = persentase saham yang dipegang / persentase total bentukan saham terkecil yang mungkin.
			 
 Kesalahan pada UTS lalu : pada bagian looping (menggunakan DP bottom up flying table), ditulis:
                          
						   for(int j = stockhold[i]; j <= 10000; j++) 
						   
						   Looping di atas berakibat seorang pemegang saham dapat masuk ke bentukan berkali-kali.
						   Statement looping yang benar adalah
						   
						   for(int j = 10000; j >= stockhold[i]; j--) 
 */
 
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
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

int N, T, total, stockhold[111];
bool dp[10101];
PII persen;

int main()
{
	while(1)
	{
		scanf("%d %d", &N, &T);
		if(!N && !T) break;
		
		for(int i = 1; i <= N; i++) 
		{
			scanf("%d.%d", &persen.fi, &persen.se);
			stockhold[i] = persen.fi * 100 + persen.se;
		}
		
		memset(dp, false, sizeof(dp));
		dp[stockhold[T]] = true;
		for(int i = 1; i <= N; i++) if(i != T)
			for(int j = 10000; j >= stockhold[i]; j--) 
				if(dp[j - stockhold[i]]) dp[j] = true;
		
		for(total = 5001; total <= 10000; total++) if(dp[total]) break;
		
		int ans = (stockhold[T] * 10000) / total;
		if(((stockhold[T] * 10000) % total) * 2 >= total) ans++;
		printf("%.2lf\n", ans / (double) 100);
	}
	
	return 0;
}
