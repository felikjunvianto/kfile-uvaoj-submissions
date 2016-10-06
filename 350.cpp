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

pair<bool,int> udah[11000];
int z,i,m,l,x,y,t;

int main()
{
	t=0;
	do
	{
		scanf("%d %d %d %d",&z,&i,&m,&l);
		if(z+i+m+l==0) break;
		
		t++;
		for(x=0;x<10000;x++) udah[x].fi = udah[x].se = 0;
		x=1;
		
		while(!udah[l].fi)
		{
			udah[l].fi=true;
			udah[l].se=x;
			x++;
			l=(z*l+i)%m;
		}
		printf("Case %d: %d\n",t,x-udah[(z*l+i)%m].se+1);
	}while(1);
	return 0;
}

