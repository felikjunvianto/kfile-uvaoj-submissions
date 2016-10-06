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

int T,N,H,x,y,z,jum;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&H);
		int last=(1<<N);
		for(x=1;x<last;x++)
		{
			jum=0;
			for(y=0;y<N;y++) if((x&(1<<y))>0) jum++;
			if(jum==H) 
			{
				for(y=N-1;y>=0;y--) printf("%d",((x&(1<<y))>0));
				printf("\n");
			}
		}
		if(T) printf("\n");
	}
	return 0;
}

