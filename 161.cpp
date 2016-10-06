/*
   Algorithm : simulasikan saja pada detik keberapa lagi semua lampu menjadi hijau.
               Looping dimulai dari detik terkecil di mana paling tidak 1 lampu telah menjadi jingga
               (karena pada detik ke 0 semua lampu berwarna hijau).
               
   Tricks : bug pertama terjadi karena lupa menambahkan newline untuk tipe keluaran "Signals fail
            to synchronize in 5 hours.

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

char lamp[111];
int cycle[111], N, T, temp, small;

int main()
{
	while(1)
	{
		N = 0;
		small = INF;
		while(1)
		{
			scanf("%d",&temp);
			if(!temp) break;
			cycle[N++] = temp;
			small = min(small, temp);
		} if(!N) break;
		
		for(T = small - 5; T <= 18000; T++)
		{
			for(int i = 0; i < N; i++) if((T / cycle[i]) & 1) lamp[i] = 'R';
				else if(T % cycle[i] < cycle[i] - 5) lamp[i] = 'G';
					else lamp[i] = 'O';
			
			bool allGreen = true;
			for(int i = 0; i < N && allGreen; i++) if(lamp[i] != 'G') allGreen = false;
			if(allGreen) break;
		}
		
		if(T > 18000) printf("Signals fail to synchronise in 5 hours\n"); 
			else printf("%02d:%02d:%02d\n",T/3600,(T%3600)/60,T%60);
	}
	return 0;
}
