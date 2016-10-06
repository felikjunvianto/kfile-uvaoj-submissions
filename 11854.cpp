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
#define pi 2*acos(0.0)
#define PII pair<int,int> 

using namespace std;

int side[3];

int main()
{
	while(1)
	{
		scanf("%d %d %d",&side[0], &side[1], &side[2]);
		if(!side[0] && !side[1] && !side[2]) break;
		
		sort(side,side+3);
		if(side[0]*side[0]+side[1]*side[1] == side[2]*side[2]) printf("right\n");
			else printf("wrong\n");
	}
	return 0;
}

