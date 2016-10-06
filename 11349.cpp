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

int T,N,r,c;
LL mat[111][111];
char d1[2],d2[2];
bool sym;

int main()
{
	scanf("%d",&T);
	for(int i = 1;i<=T;i++)
	{
		scanf("%s %s %d",d1,d2,&N);

		sym=true;
		for(r=1;r<=N;r++)
			for(c=1;c<=N;c++)
			{
				scanf("%lld",&mat[r][c]);
				if(mat[r][c]<0LL) sym=false;
			}
				
		for(r=1;r<=N && sym;r++)
			for(c=1;c<=r && sym;c++)
				if(mat[r][c]!=mat[N-r+1][N-c+1])
					sym=false;
		
		printf("Test #%d: %s\n",i,sym?"Symmetric.":"Non-symmetric.");
	}
	return 0;
}

