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

int i,w,x,y,z,len;
int T,E,S,F;
int par[303];
bool visited[303];
char msk[1000];
vector<int> adjlist[303];

int main()
{
	while(scanf("%d",&T)!=EOF)
	{
		getchar();
		for(i=1;i<=T;i++) adjlist[i].clear();
		
		for(i=1;i<=T;i++)
		{
			gets(msk);len=strlen(msk);
			x=0;
			for(y=0;y<len && msk[y]!='-';y++) x=x*10+msk[y]-'0';
			z=y;
			
			do
			{
				y=++z;w=0;
				while(y<len && msk[y]!=',') w=w*10+msk[y++]-'0';
				if(w>0) adjlist[x].pb(w);
				z=y;
			} while(z+1<len);
		}
		printf("-----\n");
		
		scanf("%d",&E);
		while(E--)
		{
			scanf("%d %d",&S,&F);
			for(i=1;i<=T;i++) 
			{
				visited[i]=false;
				par[i]=-1;
			}
			
			visited[S]=true;
			queue<int> q;
			q.push(S);
			
			while(!q.empty())
			{
				x=q.front();q.pop();
				if(x==F) break;
				
				for(i=0;i<adjlist[x].size();i++)
				{
					w=adjlist[x][i];
					if(!visited[w]) 
					{
						visited[w]=true;
						par[w]=x;
						q.push(w);
					}
				}
			}
			
			if(!visited[F]) printf("connection impossible\n"); else
			{
				vector<int> ans;
				x=F;
				while(x!=-1)
				{
					ans.pb(x);
					x=par[x];
				}
				
				for(i=(int)ans.size()-1;i>=0;i--) 
					printf("%d%c",ans[i],i?' ':'\n');
			}
		}
	}
	return 0;
}

