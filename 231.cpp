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

vector<int> dp,misil;
int x,y,t,terbesar;

int main()
{
	t=0;
	do
	{
		scanf("%d",&x);
		if(x==-1)
		{
			if(misil.size()==0) break;
			t++;
			if(t>1) printf("\n");
			printf("Test #%d:\n",t);
			printf("  maximum possible interceptions: %d\n",terbesar);
			terbesar=0;
			dp.clear();
			misil.clear();
		} else
		{
			misil.pb(x);
			dp.pb(1);
			x=misil.size()-1;
			for(y=x-1;y>=0;y--) if(misil[y]>misil[x])
				dp[x]=max(dp[x],dp[y]+1);
			terbesar=max(terbesar,dp[x]);
		}
	}while(1);
	return 0;
}

