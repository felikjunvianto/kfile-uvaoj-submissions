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

int tukar[]={1,2,4,10,20,40};
int j[6];
int x,y,z,uang,terkecil;
int dp[110],kembalian[110];
int gede=1000000000;

int main()
{
	for(x=1;x<=100;x++) kembalian[x]=gede;
	kembalian[0]=0;
	for(x=0;x<6;x++)
		for(y=tukar[x];y<=100;y++) kembalian[y]=min(kembalian[y],kembalian[y-tukar[x]]+1);
	
	do
	{
		for(x=0;x<6;x++) scanf("%d",&j[x]);
		if(j[0]+j[1]+j[2]+j[3]+j[4]+j[5]==0) break;
		
		scanf("%d.%d",&x,&y);
		uang=(x*100+y)/5;
		for(x=1;x<=100;x++) dp[x]=gede;
		dp[0]=0;
		
		for(z=0;z<6;z++)
			for(x=0;x<j[z];x++)
				for(y=100;y>=tukar[z];y--) dp[y]=min(dp[y],dp[y-tukar[z]]+1);
		
		terkecil=gede;
		for(x=uang;x<=100;x++) if(dp[x]!=gede) terkecil=min(terkecil,dp[x]+kembalian[x-uang]);
		printf("%3d\n",terkecil);
	}while(1);
	return 0;
}

