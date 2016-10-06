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

int N,r1,r2,c1,c2;
int size,x,y,z;

int main()
{
	int i = 0;
	while(1)
	{
		scanf("%d %d %d %d %d",&N,&r1,&c1,&r2,&c2);
		if(!N) break;
		
		printf("Case %d:\n",++i);
		size=2*N-1;
		for(y=r1;y<=r2;y++)
			for(x=c1;x<=c2;x++)
			{
				int c = x%size, r = y%size;
				int dis = abs(c-N+1)+abs(r-N+1);
				if(dis>=N) printf("."); else printf("%c",dis%26+'a');
				if(x==c2)printf("\n");
			}
	}
	return 0;
}

