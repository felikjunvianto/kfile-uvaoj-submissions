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

int fib[1010][215];
int N,carry,x,y,z;

int main()
{
	memset(fib,0,sizeof(fib));
	fib[0][0]=1;
	fib[1][0]=2;
	for(x=2;x<=1000;x++)
	{
		carry=0;
		for(y=0;y<215;y++)
		{
			fib[x][y]=fib[x-1][y]+fib[x-2][y]+carry;
			carry=fib[x][y]/10;
			fib[x][y]%=10;
		}
	}
	
	while(scanf("%d",&N)!=EOF)
	{
		for(y=214;y>=0;y--) if(fib[N][y]!=0) break;
		for(x=y;x>=0;x--) printf("%d",fib[N][x]);
		printf("\n");
	}
	return 0;
}

