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

int T,N,x,y,z,len,gede;
int fib[50];
bool vis[50];
char msk[110],urut[50];
string asli;
vector<int> bil;

int main()
{
	fib[0]=fib[1]=1;
	for(x=2;x<=45;x++) fib[x]=fib[x-1]+fib[x-2];
	fib[0]=0;
	
	scanf("%d",&T);
	while(T--)
	{
		gede=0;
		scanf("%d",&N);
		memset(vis,false,sizeof(vis));
		bil.clear();
		for(x=1;x<=N;x++)
		{
			scanf("%d",&z);
			gede=max(gede,z);
			bil.pb(z);
		}getchar();
		
		gets(msk);
		len=strlen(msk);
		asli.clear();
		for(x=0;x<len;x++) if((msk[x]>='A')&&(msk[x]<='Z')) asli+=msk[x];
		
		for(x=0;x<bil.size();x++)
		{
			y=lower_bound(fib,fib+46,bil[x])-fib;
			vis[y]=true;
			urut[y]=asli[x];
		}
		
		y=lower_bound(fib,fib+46,gede)-fib;
		for(x=1;x<=y;x++) if(!vis[x]) printf(" "); else printf("%c",urut[x]);
		printf("\n");
	}
	
	return 0;
}

