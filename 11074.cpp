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

int S,T,N,i;

int main()
{
	i = 0;
	while(1)
	{
		scanf("%d %d %d",&S,&T,&N);
		if(!S && !T && !N) break;
		
		printf("Case %d:\n",++i);
		int loop = 2*N+1;
		for(int r=0;r<loop;r++)
		{
			int inner = (r&1)?S:T;
			while(inner--)
			{
				for(int c=0;c<loop;c++)
				{
					int inner2 = (c&1)?S:T;
					char pat = ((r&1)&&(c&1))?'.':'*';
					for(int j=0;j<inner2;j++) printf("%c",pat);
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}

