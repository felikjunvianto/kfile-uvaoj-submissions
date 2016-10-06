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
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>

using namespace std;

int n,x,y,z,total;
int bil[60];

int main()
{
	do
	{
		scanf("%d",&n);
		if(n==0) break;
		
		for(x=0;x<n;x++) scanf("%d",&bil[x]);
		total=0;
		for(x=0;x<n-1;x++)
			for(y=x+1;y<n;y++) if(__gcd(bil[x],bil[y])==1) total++;
			
		if(total==0) printf("No estimate for this data set.\n"); else
			printf("%.6lf\n",sqrt((double) 3*n*(n-1)/total));
	}while(n!=0);
	return 0;
}

