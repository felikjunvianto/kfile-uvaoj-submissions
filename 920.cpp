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
#define pi acos(-1.0)
#define eps 1e-9

using namespace std;

pair<int,int> koor[110];
int terakhir;
int t,n,x,y,z,A,B,C;
double panjang;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(x=0;x<n;x++) scanf("%d %d",&koor[x].fi,&koor[x].se);
		sort(koor,koor+n);
		terakhir=n-1;
		panjang=0;
		for(x=n-2;x>=0;x--) if(koor[x].se>koor[terakhir].se)
		{
			A=koor[x].se-koor[x+1].se;
			B=koor[x].fi-koor[x+1].fi;
			C=B*koor[x+1].se-A*koor[x+1].fi;
			double jatuh=(double)(koor[terakhir].se*B-C)/A;
			
			panjang+=sqrt(((double)koor[x].fi-jatuh)*((double)koor[x].fi-jatuh)+
				(double)(koor[x].se-koor[terakhir].se)*(koor[x].se-koor[terakhir].se));
			terakhir=x;
		}
		printf("%.2f\n",panjang);
	}
	return 0;
}

