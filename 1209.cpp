/*
	Algoritma : Generate semua permutasi dari string masukan dengan prev_permutation() dan next_permutation().
				Lakukan dengan benar agar hasilnya terurut, simpan di array, kemudian secara brute force cari
				string dengan jarak 2 huruf bersebelahan terkecil yang paling maksimal.
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

char inp[30], temp[30];
string permut[30];
int len, ans, idx;

int main()
{
	while(scanf("%s",inp)!=EOF)
	{
		len = strlen(inp);
		permut[11] = inp;
	
		strcpy(temp, inp);
		for(int i = 10; i >= 1 && prev_permutation(temp, temp + len); i--) permut[i] = temp;
		
		strcpy(temp, inp);
		for(int i = 12; i <= 21 && next_permutation(temp, temp + len); i++) permut[i] = temp;
		
		ans = 0; idx = -1;
		for(int i = 1; i <= 21; i++)
		{
			int temp = INF;
			for(int j = 0; j + 1 < len; j++) 
				temp = min(temp, abs(permut[i][j + 1] - permut[i][j]));
	
			if(ans < temp) 
			{
				ans = temp;
				idx = i;
			}
		}
		
		printf("%s%d\n",permut[idx].c_str(), ans);
	}
	return 0;
}
