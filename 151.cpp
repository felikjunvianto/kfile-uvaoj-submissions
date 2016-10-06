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
	int l,r;
}cell;

int now;
vector<cell> city,next;
int N,M,hancur,x,y,z;
int ans[110];
bool oke;

int main()
{
	for(N=13;N<=100;N++)
	{
		city.clear();
		for(x=0;x<N;x++) if(!x) city.pb((cell){N-1,(x+1)%N}); else city.pb((cell){x-1,(x+1)%N});
		
		M=0;
		do
		{
			M++;
			oke=true;
			next=city;
			hancur=now=0;

			while((hancur<N-1)&&oke)
			{
				next[next[now].l].r=next[now].r;
				next[next[now].r].l=next[now].l;
				now=next[now].r;
				hancur++;
				
				x=(M-1)%(N-hancur);
				while(x--) now=next[now].r;
				if((now==12)&&(hancur<N-1))
				{
					oke=false;
					break;
				}
			}
		}while(!oke);
		ans[N]=M;
	}
	
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		printf("%d\n",ans[N]);
	}
	return 0;
}

