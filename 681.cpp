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

int t,n,x,y,z,PO;
vector<PII> titik,convex_hull;
stack<PII> s;

int area(PII p,PII q,PII r)
{
	return(p.fi*(q.se-r.se)+q.fi*(r.se-p.se)+r.fi*(p.se-q.se));
}

int dis(PII i)
{
	int x=titik[0].fi-i.fi;
	int y=titik[0].se-i.se;
	return(x*x+y*y);
}

bool cf(PII i,PII j)
{
	if(area(titik[0],i,j)==0) return(dis(i)<dis(j));
	return(atan2((double)(i.se-titik[0].se),(double)(i.fi-titik[0].fi))<
			atan2((double)(j.se-titik[0].se),(double)(j.fi-titik[0].fi)));
}

int main()
{
	scanf("%d",&t);
	printf("%d\n",t);
	while(t--)
	{
		scanf("%d",&n);
		titik.clear();
		PO=-1;
		for(z=0;z<n;z++)
		{
			scanf("%d %d",&x,&y);
			titik.pb(mp(x,y));
			if((PO==-1)||((titik[z].se<titik[PO].se)||
				((titik[z].se==titik[PO].se)&&(titik[z].fi>titik[PO].fi)))) PO=z;
		}
		titik.pop_back();
		swap(titik[PO],titik[0]);
		n--;
		
		sort(++titik.begin(),titik.end(),cf);
		s.push(titik[n-1]);
		s.push(titik[0]);
		z=1;
		PII now,prev;
		
		while(z<n)
		{
			now=s.top();
			s.pop();prev=s.top();s.push(now);
			if(area(prev,now,titik[z])>0)
			{
				s.push(titik[z]);
				z++;
			} else s.pop();
		}
		
		convex_hull.clear();
		while(!s.empty())
		{
			convex_hull.pb(s.top());
			s.pop();
		}
		
		convex_hull.pop_back();
		n=convex_hull.size();
		printf("%d\n",n+1);
		reverse(convex_hull.begin(),convex_hull.end());
		z=0;
		for(x=0;x<n;x++) if((convex_hull[x].se<convex_hull[z].se)||
							 ((convex_hull[x].se==convex_hull[z].se)&&(convex_hull[x].fi<convex_hull[z].fi))) z=x;
		for(x=0;x<=n;x++) printf("%d %d\n",convex_hull[(z+x)%n].fi,convex_hull[(z+x)%n].se);
		if(t>0) 
		{
			scanf("%d",&x);
			printf("%d\n",x);
		}
	}	
	return 0;
}

