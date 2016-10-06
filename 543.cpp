#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

vector<int> prima;
bool prime[1000001];
int x,y,z;

int main()
{
	memset(prime,true,sizeof(prime));
	prime[1]=false;
	for(x=1;x<=1000000;x++) if(prime[x])
	{
		prima.push_back(x);
		z=2;
		while(z*x<=1000000)
		{
			prime[z*x]=false;
			z++;
		}
	}
	
	do
	{
		scanf("%d",&z);
		if(z==0) break;
		
		bool ada=false;
		if(z%2==0)
			for(x=1;x<prima.size();x++) if(2*prima[x]>z) break; else
				if(prime[z-prima[x]])
				{
					ada=true;
					printf("%d = %d + %d\n",z,prima[x],z-prima[x]);
					break;
				}

		if(!ada) printf("Goldbach's conjecture is wrong.\n");
	} while(z!=0);
	return 0;
}
