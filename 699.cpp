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

int posisi[]={-1,1};
stack<PII> s;
vector<PII> leaf;
vector<int> tumpuk;
int x,z,n,urutan,terkiri,terkanan;

int main()
{
	z=0;
	do
	{
		scanf("%d",&n);
		if(n==-1) break;
		
		urutan=0;
		leaf.clear();
		leaf.pb(mp(0,n));
		s.push(mp(urutan,0));
		
		do
		{
			scanf("%d",&x);
			PII prev=s.top();
			s.top().se++;
			if(s.top().se==2) s.pop();
			
			if(x>0) 
			{
				urutan++;
				leaf.pb(mp(leaf[prev.fi].fi+posisi[prev.se],x));
				s.push(mp(urutan,0));
			}
		}while(!s.empty());
		
		terkiri=terkanan=0;
		for(x=1;x<leaf.size();x++) 
		{
			if(leaf[terkiri].fi>leaf[x].fi) terkiri=x;
			if(leaf[terkanan].fi<leaf[x].fi) terkanan=x;
		}
		terkiri=abs(leaf[terkiri].fi);
		
		tumpuk.clear();
		while(leaf[terkanan].fi+terkiri>=tumpuk.size()) tumpuk.pb(0);
		for(x=0;x<leaf.size();x++) tumpuk[leaf[x].fi+terkiri]+=leaf[x].se;
		
		printf("Case %d:\n",++z);
		for(x=0;x<tumpuk.size();x++)
		{
			printf("%d",tumpuk[x]);
			if(x<tumpuk.size()-1) printf(" ");
		}
		printf("\n\n");
	}while(n!=-1);
	return 0;
}

