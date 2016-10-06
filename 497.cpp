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

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>

using namespace std;

vector<int> dp,misil,par;
char baca[10];
int x,y,z,terbesar;

void cetak(int now)
{
	if(par[now]!=now) cetak(par[now]);
	printf("%d\n",misil[now]);
}

void keluarkan()
{
	printf("Max hits: %d\n",dp[terbesar]);
	cetak(terbesar);
}

int main()
{
	terbesar=0;
	scanf("%d\n",&x);
	while(gets(baca))
	{
		int panjang=strlen(baca);
		if(panjang==0)
		{
			keluarkan();
			printf("\n");
			par.clear();
			dp.clear();
			misil.clear();
			terbesar=0;
		} else
		
		{
			sscanf(baca,"%d",&x);
			misil.pb(x);
			dp.pb(1);
			x=misil.size()-1;
			par.pb(x);
			
			for(y=x-1;y>=0;y--) if((misil[y]<misil[x])&&(dp[y]+1>dp[x]))
			{
				par[x]=y;
				dp[x]=dp[y]+1;
			}
			if(dp[x]>dp[terbesar]) terbesar=x;
		}
	}
	keluarkan();
	return 0;
}

