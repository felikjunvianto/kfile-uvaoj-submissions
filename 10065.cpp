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

int t,x,y,z,a,b,n,bungkus,lantai;
vector<PII> titik,convex;
stack<PII> s;
PII now,prev;

int area(vector<PII> i)
{
	int n=i.size();
	int hasil=i[0].fi*(i[1].se-i[n-1].se);
	for(int x=1;x<n;x++) hasil+=i[x].fi*(i[(x+1)%n].se-i[x-1].se);
	return abs(hasil);
}

int det(PII p, PII q, PII r)
{
	return(p.fi*(q.se-r.se)+q.fi*(r.se-p.se)+r.fi*(p.se-q.se));
}

int dis(PII i)
{
	int x=i.fi-titik[0].fi;
	int y=i.se-titik[0].se;
	return(x*x+y*y);
}

bool cf(PII i,PII j)
{
	if(det(titik[0],i,j)==0) return(dis(i)<dis(j));
	
	int xa=i.fi-titik[0].fi;int ya=i.se-titik[0].se;
	int xb=j.fi-titik[0].fi;int yb=j.se-titik[0].se;
	return(atan2(ya,xa)<atan2(yb,xb));
}

int main()
{
	n=1;
	do
	{
		scanf("%d",&t);
		if(t==0) break;
		
		z=0;
		titik.clear();
		for(x=0;x<t;x++)
		{
			scanf("%d %d",&a,&b);
			titik.pb(mp(a,b));
			if((titik[z].se>titik[x].se)||((titik[z].se==titik[x].se)&&(titik[z].fi<titik[x].fi))) z=x;
		}
		lantai=area(titik);
		swap(titik[z],titik[0]);
		sort(++titik.begin(),titik.end(),cf);
		
		s.push(titik[t-1]);
		s.push(titik[0]);
		
		z=1;
		while(z<t)
		{
			now=s.top();s.pop();
			prev=s.top();s.push(now);
			if(det(prev,now,titik[z])>=0)
			{
				s.push(titik[z]);
				z++;
			} else s.pop();
		}
		
		convex.clear();
		while(!s.empty())
		{
			convex.pb(s.top());
			s.pop();
		}convex.pop_back();
		
		bungkus=area(convex);
		
		printf("Tile #%d\n",n++);
		printf("Wasted Space = %.2lf %c\n\n",(double)(bungkus-lantai)*100/bungkus,37);
	}while(t!=0);
	return 0;
}

