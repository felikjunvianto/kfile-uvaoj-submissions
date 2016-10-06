#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t,x,y,z,b[150];
bool ada[25000];
bool b2;

int main()
{
	z=0;
	while(scanf("%d",&t)!=EOF)
	{
		z++;
		for(x=0;x<t;x++) scanf("%d",&b[x]);
		
		if(b[0]<1) b2=false; else b2=true;
		
		if(b2) for(x=1;x<t;x++) if(b[x]<=b[x-1])
		{
			b2=false;
			break;
		}
		
		if(b2)
		{
			memset(ada,false,sizeof(ada));
			for(x=0;x<t;x++)
			{
				for(y=x;y<t;y++) if(ada[b[x]+b[y]])
				{
					b2=false;
					break;
				} else ada[b[x]+b[y]]=true;
				if(!b2) break;
			}
		}
		
		printf("Case #%d: It is ",z);
		if(!b2) printf("not ");
		printf("a B2-Sequence.\n");
		printf("\n");
	}
	return 0;
}
