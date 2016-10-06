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

int C, T, N;
int r1, r2, c1, c2;

int main()
{
	scanf("%d",&C);
	while(C--)
	{
		scanf("%d",&T);
		scanf("%d",&N);
		
		while(T--)
		{
			scanf("%d %d %d %d\n",&r1, &c1, &r2, &c2);
			if(abs(r1 - c1)%2 != abs(r2 - c2)%2) printf("no move\n"); else
				if(r1 == r2 && c1 == c2) printf("0\n"); else
					if(r1 - c1 == r2 - c2 || r1 + c1 == r2 + c2) printf("1\n"); else
						printf("2\n");
		}
	}
	return 0;
}

