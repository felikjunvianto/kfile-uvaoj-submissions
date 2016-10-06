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

int N,panjang;
char kata[30];

int main()
{
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",kata);
		panjang=strlen(kata);
		sort(kata,kata+panjang);
		do
		{
			printf("%s\n",kata);
		}while(next_permutation(kata,kata+panjang));
		printf("\n");
	}
	return 0;
}

