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

int t,x,patokan,dicek;
PII titik[60];
bool ada;

int det(PII a,PII b,PII c)
{
	return(a.fi*(b.se-c.se)+b.fi*(c.se-a.se)+c.fi*(a.se-b.se));
}

int main()
{
	do
	{
		scanf("%d",&t);
		if(t==0) break;
		
		for(x=0;x<t;x++) scanf("%d %d",&titik[x].fi,&titik[x].se);
		ada=false;
		patokan=det(titik[0],titik[1],titik[2]);
		for(x=1;x<t;x++) 
		{
			dicek=det(titik[x],titik[(x+1)%t],titik[(x+2)%t]);
			if(((patokan>0)&&(dicek<0))||((patokan<0)&&(dicek>0)))
			{
				ada=true;
				break;
			}
		}
		if(!ada) printf("No\n"); else printf("Yes\n");
	}while(t!=0);
	return 0;
}

