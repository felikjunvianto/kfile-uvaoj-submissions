#include <cstdio>
#include <cstdlib>
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
#include <set>

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

const int D_MAX = 700;
int N, start, C[1010][D_MAX + 10], res[D_MAX + 10];

int main()
{
	memset(C, 0, sizeof(C));
	C[0][0] = 1;
	for(int n = 1; n <= 1000; n++)
	{
		int m = 4 * n - 2, carry = 0;
		memset(res, 0, sizeof(res));
		for(int i = 0; i <= D_MAX; i++) 
		{
			res[i] = C[n-1][i] * m + carry;
			carry = res[i] / 10;
			res[i] %= 10;
		}
		
		int d = n + 1, temp = 0, p = 0;
		for(start = D_MAX; start >= 0; start--) if(res[start]) break;
		for(int i = start; i >= 0; i--)
		{
			temp = temp * 10 + res[i];
			C[n][p++] = temp / d;
			temp %= d;
		}
		
		for(int i = 0; 2 * (i + 1) <= p; i++) swap(C[n][i], C[n][p - i - 1]);
	}
	
	while(scanf("%d", &N) != EOF)
	{
		for(start = D_MAX; start >= 0; start--) if(C[N][start]) break;
		for(int i = start; i >= 0; i--) printf("%d", C[N][i]);
		printf("\n");
	}
	return 0;
}

