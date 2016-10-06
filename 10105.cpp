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

int N,K,ni,i,ans;
int C[20][20];

int main()
{
	C[0][0]=1;
	for(int x=1;x<20;x++)
	{
		C[x][0]=C[x][x]=1;
		for(int y=1;y<x;y++) C[x][y]=C[x-1][y-1]+C[x-1][y];
	}
	
	while(scanf("%d %d",&N,&K)!=EOF)
	{
		ans=1;
		while(K--)
		{
			scanf("%d",&ni);
			i=N-ni;
			ans*=C[N][i];
			N=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}

