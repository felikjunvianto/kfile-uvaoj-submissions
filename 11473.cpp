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

int t,x,y,z,banyak,pohon;
pair<double,double> node[110];
double jalan[110],jarak,now;

int main()
{
	scanf("%d",&t);
	for(x=1;x<=t;x++)
	{
		scanf("%d %d",&banyak,&pohon);
		for(y=0;y<banyak;y++) scanf("%lf %lf",&node[y].fi,&node[y].se);
		printf("Road #%d:\n",x);
	
		jarak=0;
		for(y=0;y<banyak-1;y++) 
		{
			jalan[y]=sqrt(pow(node[y].fi-node[y+1].fi,2)+pow(node[y].se-node[y+1].se,2));
			jarak+=jalan[y];
		}

		jarak/=(double)(pohon-1);
		now=jarak;
		pohon-=2;
		printf("%.2f %.2f\n",node[0].fi,node[0].se);
		while(pohon--)
		{
			double patokan=0;
			for(y=0;y<banyak-1;y++) 
			{
				patokan+=jalan[y];
				if(patokan>now) 
				{
					patokan-=jalan[y];
					break;
				}
			}
			double dihitung=now-patokan;
			double vertikal=dihitung*(node[y+1].se-node[y].se)/jalan[y];
			double horizontal=dihitung*(node[y+1].fi-node[y].fi)/jalan[y];
			printf("%.2f %.2f\n",node[y].fi+horizontal,node[y].se+vertikal);
			now+=jarak;
		}
		printf("%.2f %.2f\n\n",node[banyak-1].fi,node[banyak-1].se);
	}
	return 0;
}

