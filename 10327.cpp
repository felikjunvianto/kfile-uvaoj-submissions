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

int n,x,y,z,total;
int bil[1010];

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(x=0;x<n;x++) scanf("%d",&bil[x]);
		total=0;
		for(x=n-1;x>0;x--)
			for(y=1;y<=x;y++) if(bil[y]<bil[y-1]) 
			{
				swap(bil[y],bil[y-1]);
				total++;
			}
			printf("Minimum exchange operations : %d\n",total);
	}
	return 0;
}

