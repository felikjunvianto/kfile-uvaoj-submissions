/*
	Algoritma: Sort edge secara descending. Looping dari depan, untuk elemen yang diperiksa looping saat ini
	           Jika nilainya > 0 (misal nilainya K), maka kurangi K elemen positif berikutnya sebanyak 1 (atau
			   sampai akhir array jika kurang dari K elemen yang ada berikutnya).
			   
			   Setelah itu, looping lagi untuk memeriksa apakah ada elemen array yang masih positif. Jika ada,
			   maka tidak mungkin bisa dibuat graph dengan derajat vertex seperti itu, namun jika semua 0, maka
			   graph dengan derajat vertex seperti itu dapat dibuat.
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

int T, N;
int edge[1010];

bool cf(int i, int j)
{
	return i > j;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(int i = 0; i < N; i++) scanf("%d",&edge[i]);
		
		sort(edge, edge + N, cf);
		for(int i = 0; i < N; i++) if(edge[i])
			for(int j = i + 1; j < N; j++) if(edge[j])
			{
				edge[i]--; edge[j]--;
				if(!edge[i]) break;
			}
			
		bool kosong = true;
		for(int i = 0; i < N && kosong; i++) if(edge[i]) kosong = false;
		printf("%s\n",kosong?"Yes":"No");
		
	}
	return 0;
}

