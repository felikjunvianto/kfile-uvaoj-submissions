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

int adjmat[110][110];
int gede=1000000000;
int x,y,z,a,b,c,cost,t,node,edge;
int fartest;

bool equidis(int town)
{
	if(adjmat[1][town]==gede) return(false); else
	{
		bool bisa=true;
		for(int x=2;x<=5;x++) if((adjmat[x][town]==gede)||(adjmat[x][town]!=adjmat[1][town]))
		{
			bisa=false;
			break;
		}
		return(bisa);
	}
}

bool connected(int town)
{
	bool sambung=true;
	for(int x=1;x<=node;x++) if((x!=town)&&(adjmat[x][town]==gede))
	{
		sambung=false;
		break;
	}
	return(sambung);
}

int terjauh(int town)
{
	int temp=0;
	for(int x=1;x<=node;x++) if(x!=town) temp=max(temp,adjmat[x][town]);
	return(temp);
}

int main()
{
	scanf("%d",&t);
	for(x=1;x<=t;x++)
	{
		scanf("%d %d",&node,&edge);
		for(a=1;a<=node;a++)
			for(b=1;b<=node;b++) adjmat[a][b]=gede;
		
		for(y=0;y<edge;y++)
		{
			scanf("%d %d %d",&a,&b,&cost);
			adjmat[b][a]=adjmat[a][b]=min(adjmat[a][b],cost);
		}
		
		for(c=1;c<=node;c++)
			for(a=1;a<=node;a++)
				for(b=1;b<=node;b++) if(b==a) continue; else
					adjmat[a][b]=min(adjmat[a][b],adjmat[a][c]+adjmat[c][b]);
					
		fartest=-1;
		for(y=6;y<=node;y++) if((equidis(y))&&(connected(y)))
			if(fartest==-1) fartest=terjauh(y); else fartest=min(fartest,terjauh(y));
			
		printf("Map %d: %d\n",x,fartest);
	}
	return 0;
}

