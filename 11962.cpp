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

char num[] = {'A','C','G','T'};

int T,i,len,x,y;
LL idx;
char msk[40];

int main()
{
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%s",msk);len=strlen(msk);
		idx=0LL;
		for(x=0;x<len;x++)
		{
			for(y=0;y<4;y++) if(num[y]==msk[x]) break;
			idx=idx*4LL+(LL)y;
		}
		
		printf("Case %d: (%d:%lld)\n",i,len,idx);
	}
	return 0;
}

