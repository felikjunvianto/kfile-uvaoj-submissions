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

vector<PII> titik,ch;
vector<vector<PII> > kingdom;
vector<bool> hidup;
stack<PII> s;
PII misil;
int t,x,y,z,r,daerah;

int det(PII p,PII q,PII r)
{
	return(p.fi*(q.se-r.se)+q.fi*(r.se-p.se)+r.fi*(p.se-q.se));
}

int area(vector<PII> i)
{
	int n=i.size();
	int hasil=i[0].fi*(i[1].se-i[n-1].se);
	for(int x=1;x<n;x++) hasil+=i[x].fi*(i[(x+1)%n].se-i[x-1].se);
	return(abs(hasil));
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
	return(atan2((double)ya,(double)xa)<atan2((double)yb,(double)xb));
}

int main()
{
	do
	{
		scanf("%d",&t);
		if(t==-1) break;
		
		titik.clear();
		z=-1;
		for(r=0;r<t;r++)
		{
			scanf("%d %d",&x,&y);
			titik.pb(mp(x,y));
			if((z==-1)||(titik[z].se>titik[r].se)||((titik[z].se==titik[r].se)&&(titik[z].fi<titik[r].fi))) z=r;
		}
		swap(titik[0],titik[z]);
		sort(++titik.begin(),titik.end(),cf);
		
		s.push(titik[t-1]);
		s.push(titik[0]);
		z=1;
		PII now,prev;
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
		
		ch.clear();
		while(!s.empty())
		{
			ch.pb(s.top());
			s.pop();
		} ch.pop_back();
		
		kingdom.pb(ch);
		hidup.pb(true);
	}while(t!=-1);
	
	daerah=0;
	while(scanf("%d %d",&misil.fi,&misil.se)!=EOF)
	{
		for(x=0;x<kingdom.size();x++) if(hidup[x])
		{
			bool disini=true;
			for(y=0;y<kingdom[x].size();y++)
			{
				if(det(kingdom[x][y],misil,kingdom[x][(y+1)%kingdom[x].size()])<0)
				{
					disini=false;
					break;
				}
			}
				
			if(disini)
			{
				daerah+=abs(area(kingdom[x]));
				hidup[x]=false;
				break;
			}
		}
	}
	printf("%.2lf\n",(double)daerah/2);
	return 0;
}

