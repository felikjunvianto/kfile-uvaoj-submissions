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

int T,N,x,y,z,len;
char mat[110][110];
char msk[10100];

int main()
{
	scanf("%d",&T);getchar();
	while(T--)
	{
		gets(msk);
		len=strlen(msk);
		
		N=(int)sqrt(len);
		if(N*N!=len)
		{
			printf("INVALID\n");
			continue;
		}
		
		z=0;
		for(y=1;y<=N;y++)
			for(x=1;x<=N;x++) mat[x][y]=msk[z++];
		for(x=1;x<=N;x++)
			for(y=1;y<=N;y++) printf("%c",mat[x][y]);
		printf("\n");
	}
	return 0;
}

