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
#define pii pair<int,int> 
#define pdd pair<double,double>
#define LL long long

#define PI 2*acos(0.0)
#define EPS 1e-9
#define INF 1000000000

using namespace std;

struct carmaker
{
	int L, H;
	string name;
};

int T, D, Q, L, H, P;
carmaker data[10010];
char msk[30];

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &D);		
		for(int d = 0; d < D; d++)
		{
			scanf("%s %d %d", msk, &L, &H);
			data[d] = (carmaker) {L, H, msk};
		}

		scanf("%d", &Q);
		while(Q--)
		{
			scanf("%d", &P);
			int ansIdx = -1, ansCnt = 0;

			for(int d = 0; d < D; d++)
				if(data[d].L <= P && P <= data[d].H)
				{
					ansIdx = d;
					ansCnt++;
				}

			printf("%s\n", ansCnt == 1 ? data[ansIdx].name.c_str() : "UNDETERMINED");
		}

		if(T) printf("\n");
	}
	return 0;
}

