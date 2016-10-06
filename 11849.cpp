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

int Jack[1000010],Jill[1000010];
int N,M,x,y,tot;

int main()
{
	while(1)
	{
		scanf("%d %d",&N,&M);
		if(!N && !M) break;
		
		for(x=0;x<N;x++) scanf("%d",&Jack[x]);
		for(x=0;x<M;x++) scanf("%d",&Jill[x]);
		
		tot=0;
		y=0;
		for(x=0;x<N;x++)
		{
			while((y<M) && (Jack[x]>Jill[y])) y++;
			if(Jack[x]==Jill[y]) tot++;
		}
		printf("%d\n",tot);
	}
	return 0;
}

