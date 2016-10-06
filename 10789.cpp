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

int T,len,i,x,z;
int cnt[225];
char msk[2010];
bool prime[2510],ada;

int main()
{
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(x=2;x*x<=2000;x++) if(prime[x])
	{
		z=2;
		while(x*z<=2000)
		{
			prime[x*z]=false;
			z++;
		}
	}
	
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%s",msk);len=strlen(msk);
		memset(cnt,0,sizeof(cnt));
		for(x=0;x<len;x++) cnt[(int)msk[x]]++;
		
		printf("Case %d: ",i);
		ada=false;
		for(x=48;x<125;x++) if(prime[cnt[x]])
		{
			ada=true;
			printf("%c",(char)x);
		}
		if(!ada) printf("empty");
		printf("\n");
	}
	return 0;
}

