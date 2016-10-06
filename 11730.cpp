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

bool prime[1010];
vector<int> bil,faktor[1010];
int visited[1010];
int n,x,y,z,cost,s,t,temp;
queue<PII> q;

int main()
{
	memset(prime,true,sizeof(prime));
	for(x=2;x<=1000;x++) if(prime[x])
	{
		bil.pb(x);
		z=2;
		while(x*z<=1000)
		{
			prime[x*z]=false;
			z++;
		}
	}
	
	for(y=2;y<=1000;y++)
	{
		x=-1;
		temp=y;
		do
		{
			x++;	
			if(temp%bil[x]==0)
			{	
				if(y!=bil[x]) faktor[y].pb(bil[x]);
				while(temp%bil[x]==0) temp/=bil[x];
			}
		}while(temp!=1);
	}
		
	n=0;
	do
	{
		scanf("%d %d",&s,&t);
		if(s+t==0) break;
		
		q.push(mp(s,0));
		memset(visited,-1,sizeof(visited));
		cost=-1;
		do
		{
			temp=q.front().fi;
			if((visited[temp]==-1)||(visited[temp]>q.front().se))
			{
				visited[temp]=q.front().se;
				if(q.front().fi==t) cost=q.front().se; else 
					for(y=0;y<faktor[temp].size();y++) 
						if(temp+faktor[temp][y]<=t) 
							q.push(mp(temp+faktor[temp][y],q.front().se+1));
			}
			q.pop();
		}while(!q.empty());
		printf("Case %d: %d\n",++n,cost);
	} while(s+t>0);
	return 0;
}

