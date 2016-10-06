/*
   Algorithm : Penyelesaian soal ini dapat menggunakan struktur data linked list. Untuk setiap
               kartu yang diambil, representasi kartu tersebut dalam node linked list dibuang
			   sehingga proses pencarian kartu dan penentuan kondisi awal kartu lebih cepat
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

int N;
PII list[60];
string ans[60];
char card[5], word[60];

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		for(int i = 0; i < N; i++) list[i] = mp((i - 1 + N)%N, (i + 1)%N);
		
		int size = N, now = 0;
		for(int i = 0; i < N; i++)
		{
			scanf("%s %s", card, word);
			int move = (strlen(word) - 1)% size;
			
			while(move--) now = list[now].se;
			ans[now] = card;
			list[list[now].fi].se = list[now].se;
			list[list[now].se].fi = list[now].fi;
			now = list[now].se;
			size--;
		}
		
		for(int i = 0; i < N; i++) printf("%s%c",ans[i].c_str(),i+1==N?'\n':' ');
	}
	return 0;
}

