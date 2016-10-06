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

pair<int,int> v[5],titik[5];
int dott[5],mag[5];
int x,y,z,t;

int dot(pair<int,int> a,pair<int,int> b)
{
	return(a.fi*b.fi+a.se*b.se);
}

bool cf(pair<int,int> a,pair<int,int> b)
{
	return(atan2(a.se-titik[0].se,a.fi-titik[0].fi)>atan2(b.se-titik[0].se,b.fi-titik[0].fi));
}

int main()
{
	scanf("%d",&t);
	for(x=1;x<=t;x++)
	{
		scanf("%d %d",&titik[0].fi,&titik[0].se);
		for(y=1;y<4;y++) 
		{
			scanf("%d %d",&titik[y].fi,&titik[y].se);
			if((titik[y].se<titik[0].se)||((titik[y].se==titik[0].se)&&(titik[y].fi<titik[0].fi))) swap(titik[0],titik[y]);
		}
		sort(titik+1,titik+4,cf);
		
		for(y=0;y<4;y++) v[y]=mp(titik[(y+1)%4].fi-titik[y].fi,titik[(y+1)%4].se-titik[y].se);
		for(y=0;y<4;y++) 
		{
			dott[y]=dot(v[y],v[(y+1)%4]);
			mag[y]=v[y].fi*v[y].fi+v[y].se*v[y].se;
		}
		printf("Case %d: ",x);
		
		if((dott[0]==dott[1])&&(dott[1]==dott[2])&&(dott[2]==dott[3]))
		{
			if((mag[0]==mag[1])&&(mag[1]==mag[2])&&(mag[2]==mag[3])) printf("Square\n"); else
				printf("Rectangle\n");
		} else 
		
		if((dott[0]==dott[2])&&(dott[1]==dott[3]))
		{
			if((mag[0]==mag[1])&&(mag[1]==mag[2])&&(mag[2]==mag[3])) printf("Rhombus\n"); else
				printf("Parallelogram\n");
		}else 
			
		if((v[0].se*v[2].fi==v[2].se*v[0].fi)||(v[1].se*v[3].fi==v[3].se*v[1].fi)) printf("Trapezium\n");
			else printf("Ordinary Quadrilateral\n");
	}
	return 0;
}

