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

int T, x, y, z;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&x, &y, &z);
		int temp = (2*x-y)*z/(x+y);
		printf("%d\n",min(temp,z));
	}
	return 0;
}
