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

vector<PII> bilangan;
int x,y,z,k,n;

bool cf(PII a,PII b)
{
	return(a.fi*b.se<=b.fi*a.se);
}

int main()
{
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		bilangan.clear();
		for(x=1;x<=n;x++)
			for(y=x;y<=n;y++) if(__gcd(x,y)==1) bilangan.pb(mp(x,y));
			
		sort(bilangan.begin(),bilangan.end(),cf);
		printf("%d/%d\n",bilangan[k-1].fi,bilangan[k-1].se);
	}
	return 0;
}

