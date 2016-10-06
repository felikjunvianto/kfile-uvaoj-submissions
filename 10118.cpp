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

map<pair<pair<PII,PII>,string>,int> dp;
int N,x,y,peta[5][50];

int solve(int a,int b,int c,int d,string pile)
{
	if(dp.find(mp(mp(mp(a,b),mp(c,d)),pile))!=dp.end()) return(dp[mp(mp(mp(a,b),mp(c,d)),pile)]);
	if(pile.size()==5) return(0);
	
	int &ret=dp[mp(mp(mp(a,b),mp(c,d)),pile)]=0;
	int list[]={a,b,c,d};
	int aa,bb,cc,dd;
	
	for(int x=0;x<4;x++) if(list[x]<=N)
	{
		char ambil=peta[x][list[x]]+'A'-1;
		string next=pile;
		bool dapat=false;
		for(int y=0;y<next.size();y++) if(next[y]==ambil)
		{
			next.erase(y,1);
			dapat=true;
			x==0?aa=a+1:aa=a;
			x==1?bb=b+1:bb=b;
			x==2?cc=c+1:cc=c;
			x==3?dd=d+1:dd=d;
			ret=max(ret,solve(aa,bb,cc,dd,next)+1);
			break;
		}
		
		if(!dapat)
		{
			next.pb(ambil);
			sort(next.begin(),next.end());
			x==0?aa=a+1:aa=a;
			x==1?bb=b+1:bb=b;
			x==2?cc=c+1:cc=c;
			x==3?dd=d+1:dd=d;
			ret=max(ret,solve(aa,bb,cc,dd,next));
		}
	}
	return(ret);
}

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		dp.clear();
		for(y=1;y<=N;y++)
			for(x=0;x<4;x++) scanf("%d",&peta[x][y]);
			
		printf("%d\n",solve(1,1,1,1,""));
	}
	return 0;
}

