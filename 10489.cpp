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

int T,F,B,rem;
int K,box,next;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		rem=0;
		scanf("%d %d",&F,&B);
		while(B--)
		{
			next=1;
			scanf("%d",&K);
			while(K--)
			{
				scanf("%d",&box);
				next=(next*box)%F;
			}
			rem=(rem+next)%F;
		}
		printf("%d\n",rem);
	}
	return 0;
}

