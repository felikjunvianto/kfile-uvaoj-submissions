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

using namespace std;

int cara[30100];
int bil[40];
int t,x,y,z;
bool a;

int main()
{
	z=0;
	while(scanf("%d",&t)!=EOF)
	{
		z++;
		for(x=0;x<t;x++) scanf("%d",&bil[x]);
		
		if(bil[0]<1) a=false; else a=true;
		if(a) for(x=1;x<t;x++) if(bil[x]<=bil[x-1]) 
		{
			a=false;
			break;
		}
		
		if(a)
		{
			memset(cara,0,sizeof(cara));
			cara[0]=1;
			for(x=0;x<t;x++)
				for(y=30000;y>=bil[x];y--) cara[y]+=cara[y-bil[x]];
			for(x=0;x<t;x++) if(cara[bil[x]]>1) 
			{
				a=false;
				break;
			}
		}
		
		printf("Case #%d:",z);
		for(x=0;x<t;x++) printf(" %d",bil[x]);printf("\n");
		printf("This is ");
		if(!a) printf("not ");
		printf("an A-sequence.\n");
	}
	return 0;
}

