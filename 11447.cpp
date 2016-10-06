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

using namespace std;

PII titik[10050];
int t,n,x,y,z,w,area;
double volume,awal,minum,hujan;

int det()
{
	int total=titik[0].fi*(titik[1].se-titik[n-1].se);
	for(int x=1;x<n;x++) total+=titik[x].fi*(titik[(x+1)%n].se-titik[x-1].se);
	return(total);
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(x=0;x<n;x++) scanf("%d %d",&titik[x].fi,&titik[x].se);
		scanf("%d",&w);
		area=abs(det());
		volume=0.5*(double)area*(double)w;
		
		scanf("%lf %lf %lf",&awal,&minum,&hujan);
		awal=awal*volume/100;
		if(awal<minum) printf("Lack of water. ");
		awal-=min(awal,minum);
		if(awal+hujan>volume) printf("Excess of water. ");
		awal=min(awal+hujan,volume);
		printf("Final percentage: %.0lf%c\n",floor((awal/volume)*100.0),37);
	}
	return 0;
}
