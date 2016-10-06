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

int G,len,x,y;
char msk[111];

int main()
{
	while(1)
	{
		scanf("%d",&G);
		if(!G) break;
		
		scanf("%s",msk);len=strlen(msk);
		G=len/G;
		for(x=0;x<len;x+=G)
			for(y=x+G-1;y>=x;y--)
				printf("%c",msk[y]);
				
		printf("\n");
	}
	return 0;
}

