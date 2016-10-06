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

char masuk[1000010];
int pre[1000010];
int panjang,N,x,y,z;

int main()
{
	z=0;
	while(scanf("%s",masuk)!=EOF)
	{
		panjang=strlen(masuk);
		pre[0]=0;
		for(x=1;x<=panjang;x++)
		{
			pre[x]=pre[x-1];
			if(masuk[x-1]=='1') pre[x]++;
		}
		
		scanf("%d",&N);
		printf("Case %d:\n",++z);
		while(N--)
		{
			scanf("%d %d",&x,&y);
			x++,y++;
			int a=min(x,y),b=max(x,y);
			if((pre[b]-pre[a-1]==0)||(pre[b]-pre[a-1]==b-a+1)) printf("Yes\n"); else printf("No\n");
		}
	}
	return 0;
}

