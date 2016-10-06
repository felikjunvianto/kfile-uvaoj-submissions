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

int fib[40],x,N,T;
bool binfib[40];

int main()
{
	fib[0]=1;fib[1]=2;
	for(x=2;x<40;x++) fib[x]=fib[x-1]+fib[x-2];
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		printf("%d = ",N);
		memset(binfib,false,sizeof(binfib));
		for(x=39;x>=0;x--) if(fib[x]<=N)
		{
			binfib[x]=true;
			N-=fib[x];
		}
		
		for(x=39;x>=0;x--) if(binfib[x]) break;
		do {printf("%c",binfib[x]?'1':'0');} while(x--);
		printf(" (fib)\n");
	}
	return 0;
}

