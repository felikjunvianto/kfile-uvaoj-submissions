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

int at, bwh;
vector<int> b;

int main()
{
	while(scanf("%d %d", &at, &bwh) != EOF)
	{
		b.clear();
		
		do
		{
			b.pb(at / bwh);
			at %= bwh;
			swap(at, bwh);
		} while(at != 1);
		
		printf("[%d;", b[0]);
		for(int i = 1; i < b.size(); i++)
			printf("%d%s",b[i],i+1==b.size()?"]\n":",");
	}
	return 0;
}

