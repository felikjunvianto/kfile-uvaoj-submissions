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

int t,n,x,y,z,dis;
int harga[20010];

bool cf(int i,int j)
{
	return(i>j);
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(x=0;x<n;x++) scanf("%d",&harga[x]);
		sort(harga,harga+n,cf);
		
		dis=0;
		for(x=2;x<n;x+=3) dis+=harga[x];
		printf("%d\n",dis);
	}
	return 0;
}

