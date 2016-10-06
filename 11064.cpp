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

int N, totient, gcdm;

int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		int temp = N;
		gcdm = 1, totient = N;
		for(int i = 2; temp > 1 && i < 46341 && i * i <= N; i++) if(temp % i == 0)
		{
			int power = 0;
			while(temp % i == 0) 
			{
				power++;
				temp /= i;
			}
			
			gcdm *= (power + 1);
			totient = (totient / i) * (i - 1);
		}
		
		if(temp > 1)
		{
			gcdm *= 2;
			totient = (totient / temp) * (temp - 1);
		}
		
		printf("%d\n", N - totient - gcdm + 1); // since 1 is counted twice
	}
	return 0;
}

