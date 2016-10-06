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

int n,q,x,y,z;
vector<int> marble;

int main()
{
	z=0;
	do
	{
		scanf("%d %d",&n,&q);
		if(n==0) break;
		
		z++;
		marble.clear();
		for(x=0;x<n;x++)
		{
			scanf("%d",&y);
			marble.pb(y);
		}
		sort(marble.begin(),marble.end());
		
		printf("CASE# %d:\n",z);
		for(x=0;x<q;x++)
		{
			scanf("%d",&y);
			printf("%d ",y);
			if(!binary_search(marble.begin(),marble.end(),y)) printf("not found\n");
				else printf("found at %d\n",lower_bound(marble.begin(),marble.end(),y)-marble.begin()+1);
		}
	}while(n!=0);
	return 0;
}

