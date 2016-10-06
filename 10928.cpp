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

int t,x,y,z,total,temp,n;
vector<int> neigh;
char c;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		neigh.clear();
		scanf("%d",&n);
		z=-1;
		for(x=1;x<=n;x++)
		{
			temp=0;
			do
			{
				scanf("%d%c",&y,&c);
				temp++;
			}while(c!='\n');
			neigh.pb(temp);
			if((z==-1)||(z>temp))
			{
				z=temp;
				total=1;
			} else if(z==temp) total++;
		}
		
		for(x=0;x<neigh.size();x++) if(neigh[x]==z)
		{
			printf("%d",x+1);
			if(--total) printf(" ");
		}
		printf("\n");
	}
	return 0;
}

