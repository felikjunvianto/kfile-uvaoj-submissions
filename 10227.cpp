/*
	Algoritma : Untuk setiap orang, sediakan sebuah set<int> untuk menyimpan pohon mana saja yang digunakan.
	            set<int> digunakan untuk mem-filter input yang tidak unik (misal 1 orang mendengar pohon yang
				sama 2 kali).
				
				Kemudian sediakan vector<set<int>> yang berfungsi menyimpan konfigurasi opini yang berbeda.
				Lalu untuk setiap orang yang ada, jika himpunan pohon yang didengar sudah terdaftar sebelumnya
				di vector yang ada, maka jangan lakukan apa-apa. Namun jika belum terdaftar, maka orang ini
				mempunyai opini baru. Tambahkan ke vector himpunan pohon yang didengar orang ini.
				
				Dengan cara seperti ini, banyak opini berbeda yang didengar adalah ukuran dari vector yang
				sudah disiapkan.
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

int N, P, T, a, b;
vector<set<int> > group;
set<int> dengar[111];
char inp[50];

int main()
{
    scanf("%d", &N);
    while(N--)
    {
        scanf("%d %d", &P, &T); gets(inp);
        for(int i = 1; i <= P; i++) dengar[i].clear();
        group.clear();
        
        while(gets(inp))
        {
        	if(!strlen(inp)) break;
        	sscanf(inp, "%d %d", &a, &b);
        	dengar[a].insert(b);
        }
        
        for(int i = 1; i <= P; i++)
		{
			bool dapat = false;
			for(int j = 0; j < group.size() && !dapat; j++)
				if(dengar[i] == group[j]) dapat = true;
				
			if(!dapat) group.pb(dengar[i]);
		}
		
		printf("%d\n", group.size());
		if(N) printf("\n");
    }
    return 0;
}

