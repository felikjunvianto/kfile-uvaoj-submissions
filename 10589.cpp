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

int n,m,z,t;
double a,x,y;
PDD titik[4];
bool benar;

int main()
{
	for(z=0;z<4;z++) titik[z]=mp(0.0,0.0);
	do
	{
		scanf("%d %lf",&n,&a);
		if(n==0) break;
		
		titik[1].fi=titik[2].se=titik[3].fi=titik[3].se=a;
		m=0;
		for(z=0;z<n;z++)
		{
			scanf("%lf %lf",&x,&y);
			benar=true;
			for(t=0;t<4;t++) 
				if((x-titik[t].fi)*(x-titik[t].fi)+(y-titik[t].se)*(y-titik[t].se)>a*a)
				{
					benar=false;
					break;
				}
			if(benar) m++;
		}
		printf("%.5lf\n",(double)m*a*a/n);
	}while(n!=0);
	return 0;
}

