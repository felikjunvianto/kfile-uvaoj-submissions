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

int N,ans;

int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		ans = 0;
	
		do
		{
			ans += N/2 + 1;
			N= N/2 + N%2;
		} while (N>1);
	
		printf("%d\n",ans -1);
	}
	return 0;
}

