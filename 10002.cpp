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
#define LL long long
#define INF 1000000000

using namespace std;

PDD t[110];
int N,x,y,z;
double Ax,Ay,A;
vector<PDD> ch;
stack<PDD> s;

double det(PDD p,PDD q,PDD r)
{
	return(p.fi*(q.se-r.se)+q.fi*(r.se-p.se)+r.fi*(p.se-q.se));
}

double dis(PDD i)
{
	double x=t[0].fi-i.fi;
	double y=t[0].se-i.se;
	return(x*x+y*y);
}

bool cf(PDD i,PDD j)
{
	if(fabs(det(t[0],i,j))<eps) return(dis(i)<dis(j));
	return(det(t[0],i,j)>0);
}

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(N<3) break;
		
		int PO=0;
		for(x=0;x<N;x++)
		{
			scanf("%lf %lf",&t[x].fi,&t[x].se);
			if((t[PO].se>t[x].se)||((fabs(t[PO].se-t[x].se)<eps)&&(t[PO].fi<t[x].fi))) PO=x;
		}
		
		swap(t[PO],t[0]);
		sort(t+1,t+N,cf);
		
		s.push(t[N-1]);
		s.push(t[0]);
		x=1;
		
		PDD now,prev;
		while(x<N)
		{
			now=s.top();s.pop();
			prev=s.top();s.push(now);
			
			if(det(prev,now,t[x])>0) s.push(t[x++]); else s.pop();
		}
		
		ch.clear();
		while(!s.empty())
		{
			ch.pb(s.top());
			s.pop();
		}ch.pop_back();
		
		Ax=Ay=A=0;
		for(x=2;x<ch.size();x++)
		{
			double L=0.5*fabs(det(ch[0],ch[x-1],ch[x]));
			Ax+=(ch[0].fi+ch[x-1].fi+ch[x].fi)*L/(double)3.0;
			Ay+=(ch[0].se+ch[x-1].se+ch[x].se)*L/(double)3.0;
			A+=L;
		}
		
		Ax/=A;
		Ay/=A;
		printf("%.3lf %.3lf\n",Ax,Ay);
	}
	return 0;
}

