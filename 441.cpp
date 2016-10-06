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

int bil[15];
int t,n,x,y,z,a,b,c,d,e,f;

int main()
{
	t=0;
	do
	{
		scanf("%d",&n);
		if(n==0) break;
		for(x=0;x<n;x++) scanf("%d",&bil[x]);
		t++;
		if(t>1) printf("\n");
		for(a=0;a+5<n;a++)
			for(b=a+1;b+4<n;b++)
				for(c=b+1;c+3<n;c++)
					for(d=c+1;d+2<n;d++)
						for(e=d+1;e+1<n;e++)
							for(f=e+1;f<n;f++)
								printf("%d %d %d %d %d %d\n",bil[a],bil[b],bil[c],bil[d],bil[e],bil[f]);
	}while(n!=0);
	return 0;
}

