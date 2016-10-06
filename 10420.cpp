/*
   Algorithm : Simpan semua nama negara dalam map<string, int>. Kemudian setelah semua data masuk,
               Cetak berapa banyak entri pada negara tersebut dengan iterator.
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

map<string, int> country;
char inp[100];
int N;

int main()
{
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s", inp);
		if(country.find(inp) == country.end()) country[inp] = 1; else country[inp]++;
		gets(inp);
	}
	
	for(map<string,int>::iterator it = country.begin(); it != country.end(); it++)
		printf("%s %d\n", (it->fi).c_str(), it->se);
	return 0;
}

