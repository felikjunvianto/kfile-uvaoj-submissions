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

char msk[10];
int T;

int main()
{
	T = 0;
	while(1)
	{
		scanf("%s", msk);
		if(msk[0] == '*') break;
		
		printf("Case %d: %s\n", ++T, msk[0] == 'H' ? "Hajj-e-Akbar" : "Hajj-e-Asghar");
	}
	return 0;
}

