/**
 Algoritma : DP O(N^2). Pendekatan top-down berakibat Time Limit sehingga perlu diubah ke bottom-up 
             flying table.
			 
 Kesalahan saat UTS : algoritma yang digunakan sama sekali berbeda
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
int dp[2][1010];
int Lhor[1010], Rhor[1010];

int main()
{
	while(1)
	{
		scanf("%d", &N);
		if(!N) break;
		
		for(int i = 0; i < N; i++) scanf("%d", &Lhor[i]);
		sort(Lhor, Lhor + N);
		
		for(int i = 0; i < N; i++) scanf("%d", &Rhor[i]);
		sort(Rhor, Rhor + N);
		
		for(int i = 0; i < 2; i++)
			for(int j = 0; j <= N; j++) dp[i][j] = !i ? 0 : -INF;
		
		int now = 0;
		for(int i = N-1; i >= 0; i--)
		{
			int next = 1 - now;
			for(int j = 0; j < N; j++)
				if(Lhor[i] < Rhor[j]) dp[next][j] = dp[now][j] - 1; else
					if(Lhor[i] == Rhor[j]) dp[next][j] = max(dp[now][j + 1], dp[now][j] - 1); else
						if(Lhor[i] > Rhor[j]) dp[next][j] = dp[now][j + 1] + 1;
			now = next;
		}
		
		printf("%d\n", dp[now][0] * 200);
	}
	return 0;
}

