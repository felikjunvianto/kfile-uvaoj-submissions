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

int h,r,t,x,y,z,temp,price;
int hotel,rest,trav;
int photel[25],prest[25],ptrav[25];
bool troke[25][25],rhoke[25][25],htoke[25][25];
bool ada;

int main()
{
	while(scanf("%d %d %d",&trav,&rest,&hotel)!=EOF)
	{
		memset(troke,false,sizeof(troke));
		memset(rhoke,false,sizeof(rhoke));
		memset(htoke,false,sizeof(htoke));
		
		for(x=0;x<trav;x++)
		{
			scanf("%d",&ptrav[x]);
			for(y=0;y<rest;y++)
			{
				scanf("%d",&troke[x][y]);
				troke[x][y]^=1;
			}
		}
		
		for(x=0;x<rest;x++)
		{
			scanf("%d",&prest[x]);
			for(y=0;y<hotel;y++)
			{
				scanf("%d",&rhoke[x][y]);
				rhoke[x][y]^=1;
			}
		}
		
		for(x=0;x<hotel;x++)
		{
			scanf("%d",&photel[x]);
			for(y=0;y<trav;y++)
			{
				scanf("%d",&htoke[x][y]);
				htoke[x][y]^=1;
			}
		}
		
		ada=false;
		price=-1;
		for(x=0;x<trav;x++)
			for(y=0;y<rest;y++)
				for(z=0;z<hotel;z++) if(troke[x][y]&&rhoke[y][z]&&htoke[z][x])
				{
					ada=true;
					temp=ptrav[x]+prest[y]+photel[z];
					if((price==-1)||(price>temp))
					{
						price=temp;
						t=x;
						r=y;
						h=z;
					}
				}
				
		if(!ada) printf("Don't get married!\n"); else
			printf("%d %d %d:%d\n",t,r,h,price);
	}
	return 0;
}

