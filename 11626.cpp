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

int t,n,x,y,z,a,b;
char stat[2];
vector<PII> convex;

long long det(PII p,PII q,PII r)
{
	long long a=(long long)p.fi*(q.se-r.se);
	long long b=(long long)q.fi*(r.se-p.se);
	long long c=(long long)r.fi*(p.se-q.se);
	return(a+b+c);
}

long long dis(PII i)
{
	long long x=(long long)i.fi-convex[0].fi;
	long long y=(long long)i.se-convex[0].se;
	return(x*x+y*y);
}

bool cf(PII i,PII j)
{
	if(det(convex[0],i,j)==0) return(dis(i)<dis(j));
	int xa=i.fi-convex[0].fi;int ya=i.se-convex[0].se;
	int xb=j.fi-convex[0].fi;int yb=j.se-convex[0].se;
	return(atan2(ya,xa)<atan2(yb,xb));
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		convex.clear();
		z=0;
		while(n--)
		{
			scanf("%d %d %s",&a,&b,stat);
			if(stat[0]=='Y')
			{
					convex.pb(mp(a,b));
					if((convex[z].se>convex.back().se)||((convex[z].se==convex.back().se)&&(convex[z].fi<convex.back().fi)))
						z=convex.size()-1;
			}
		}
		swap(convex[0],convex[z]);
		sort(++convex.begin(),convex.end(),cf);
		
		z=0;
		n=convex.size();
		for(x=0;x<n;x++) 
			if((convex[z].fi>convex[x].fi)||((convex[z].fi==convex[x].fi)&&(convex[z].se>convex[x].se)))
				z=x;
				
		printf("%d\n",n);
		for(x=0;x<n;x++) printf("%d %d\n",convex[(x+z)%n].fi,convex[(x+z)%n].se);
	}
	return 0;
}

