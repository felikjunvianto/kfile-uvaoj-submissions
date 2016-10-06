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

vector<PDD> point,ch;
stack<PDD> s;
PDD now,prev;
int t,x,y,z,n;
double a,b,perimeter;

double det(PDD p,PDD q,PDD r)
{
	return(p.fi*(q.se-r.se)+q.fi*(r.se-p.se)+r.fi*(p.se-q.se));
}

double dis(PDD i,PDD j)
{
	return(sqrt(pow(i.fi-j.fi,2)+pow(i.se-j.se,2)));
}

bool cf(PDD i,PDD j)
{
	if(fabs(det(point[0],i,j))<eps) return(dis(i,point[0])<dis(j,point[0]));
	double xa=i.fi-point[0].fi;double ya=i.se-point[0].se;
	double xb=j.fi-point[0].fi;double yb=j.se-point[0].se;
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
		point.clear();
		for(x=0;x<t;x++)
		{
			scanf("%lf %lf",&a,&b);
			point.pb(mp(a,b));
			if((point[z].se>point[x].se)||((fabs(point[z].se-point[x].se)<eps)&&(point[z].fi<point[x].se))) z=x;
		}
		
		swap(point[0],point[z]);
		sort(++point.begin(),point.end(),cf);
		//for(x=0;x<t;x++) printf("%.2f %.2f\n",point[x].fi,point[x].se);cout<<endl;
		s.push(point[t-1]);
		s.push(point[0]);
		z=1;
		while(z<t)
		{
			now=s.top();s.pop();
			prev=s.top();s.push(now);
			
			if(det(prev,now,point[z])>=0.0000)
			{
				s.push(point[z]);
				z++;
			} else s.pop();
		}
		
		ch.clear();
		while(!s.empty()) 
		{
			ch.pb(s.top());
			s.pop();
		} ch.pop_back();
		
		perimeter=0;
		t=ch.size();
		for(x=0;x<t;x++) perimeter+=dis(ch[x],ch[(x+1)%t]);
		
		if(n>1) printf("\n");
		printf("Region #%d:\n",n++);
		for(x=0;x<=t;x++)
		{
			printf("(%.1f,%.1f)",ch[x%t].fi,ch[x%t].se);
			if(x<t) printf("-");
		}
		printf("\nPerimeter length = %.2lf\n",perimeter);
	}while(t!=0);
	return 0;
}

