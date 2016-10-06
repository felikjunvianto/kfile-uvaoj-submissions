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

int T,x,now;
int prob[15],need;

int main()
{
	T=0;
	while(1)
	{
		scanf("%d",&now);
		if(now<0) break;
		
		for(x=1;x<=12;x++) scanf("%d",&prob[x]);
			
		printf("Case %d:\n",++T);
		for(x=1;x<=12;x++)
		{
			scanf("%d",&need);
			printf("No problem");
			if(need<=now) 
			{
				printf("! :D\n");
				now-=need;
			} else printf(". :(\n");
			now+=prob[x];
		}
	}
	return 0;
}

