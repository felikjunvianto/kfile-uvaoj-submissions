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

typedef struct
{
	int id, day, fine;
} job;

int T, N, x;
job shoe[1010];

bool cf(job i, job j)
{
	if(i.day*j.fine == j.day*i.fine) return i.id < j.id;
	return i.day*j.fine < j.day*i.fine;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(x=0;x<N;x++)
		{
			scanf("%d %d",&shoe[x].day, &shoe[x].fine);
			shoe[x].id = x+1;
		}
		sort(shoe,shoe+N,cf);
		
		for(x=0;x<N;x++) printf("%d%c",shoe[x].id,x+1==N?'\n':' ');
		if(T) printf("\n");
	}
	return 0;
}

