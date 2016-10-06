/*
	Algoritma : sediakan array boolean dari 0 hingga 1 juta. Jika nilai pada indeks i adalah true,
				maka pada detik tersebut sudah ada pekerjaan, namun jika tidak maka pada detik tersebut
				masih belum ada pekerjaan.
				
				Untuk setiap pekerjaan (baik 1 kali atau yang repetitif), looping dari waktu mulai hingga
				waktu selesai-1, lalu cek apakah pada detik tersebut sudah ada pekerjaan. Jika belum, tandai
				jadi sudah. Namun jika sudah, berarti terjadi konflik. Break saat itu juga.
				
				Jika sampai akhir tidak ditemui indeks yang sudah terisi sebelumnya, maka tidak ada konflik.
				Dengan cara ini, dijamin algoritma akan berjalan secara konstan (1 juta operasi per test case).

	Credits to Ashar Fuadi for giving hints.
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

int N, M, St, Fi, Re;
bool waktu[1000010];

int main()
{
	while(1)
	{
		scanf("%d %d", &N, &M);
		if(!N && !M) break;
		
		memset(waktu, false, sizeof(waktu));
		bool conflict = false;
		while(N--)
		{
			scanf("%d %d", &St, &Fi);
			for(int i = St; i < Fi && !conflict; i++) 
				if(waktu[i]) conflict = true; else waktu[i] = true;
		}
		
		while(M--)
		{
			scanf("%d %d %d", &St, &Fi, &Re);
			while(!conflict && St <= 1000000 && Fi <= 1000000)
			{
				for(int i = St; i < Fi && !conflict; i++)
					if(waktu[i]) conflict = true; else waktu[i] = true;
					
				St += Re; Fi += Re;
			}
		}
		
		if(!conflict) printf("NO ");
		printf("CONFLICT\n");
	}
	return 0;
}

