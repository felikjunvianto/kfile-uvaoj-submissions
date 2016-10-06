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

int N, T, x, balance;

int main()
{
	T = 0;
	while(1)
	{
		scanf("%d", &N);
		if(!N) break;
		
		balance = 0;
		while(N--)
		{
			scanf("%d", &x);
			if(x) balance++; else balance--;
		}
		
		printf("Case %d: %d\n", ++T, balance);
	}
	return 0;
}

