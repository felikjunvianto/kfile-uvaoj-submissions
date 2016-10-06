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

char msk[1111];
int N;

int main()
{
	scanf("%d", &N);
	while(N--)
	{
		scanf("%s", msk);
		int len = strlen(msk);
		
		if(!strcmp(msk, "1") || !strcmp(msk, "4") || !strcmp(msk, "78")) printf("+\n"); else
			if(len >= 2 && msk[len - 1] == '5' && msk[len - 2] == '3') printf("-\n"); else
				if(len >= 2 && msk[0] == '9' && msk[len - 1] == '4') printf("*\n"); else
					if(len >= 3 && msk[0] == '1' && msk[1] == '9' && msk[2] == '0') printf("?\n");
	}
	return 0;
}

