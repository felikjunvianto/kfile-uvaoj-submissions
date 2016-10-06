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

int T, M, N;
string listM[1600], listN[1600], combined[2250010];

int main()
{
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d %d", &M, &N);
		getchar();
		
		char msk[20];
		for(int m = 0; m < M; m++)
		{
			gets(msk);
			listM[m] = msk;
		}
		
		for(int n = 0; n < N; n++)
		{
			gets(msk);
			listN[n] = msk;
		}
		
		int NUM = 0;
		for(int m = 0; m < M; m++)
			for(int n = 0; n < N; n++)
				combined[NUM++] = listM[m] + listN[n];
				
		sort(combined, combined + NUM);
		int ans = 0;
		for(int i = 0; i < NUM; i++)
			if(!i || combined[i] != combined[i - 1]) ans++;
			
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}

