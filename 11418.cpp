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

int T,N,K,x,y,z,i,f;
int s,t;
vector<int> adjlist[55];
vector<string> name[30];
int adjmat[55][55],path[55];
bool visited[55];
char msk[50];

void augment(int now)
{
	if(now==s) f=1; else if(path[now]!=-1)
	{
		augment(path[now]);
		adjmat[path[now]][now]-=f;
		adjmat[now][path[now]]+=f;
	}
}

int main()
{
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&N);
		s=0,t=2*N+1;
		for(x=s;x<=t;x++)
		{
			adjlist[x].clear();
			for(y=s;y<=t;y++) adjmat[x][y]=0;
		}
		
		for(x=1;x<=N;x++)
		{
			adjlist[s].pb(x);
			adjlist[x].pb(s);
			adjmat[s][x]=1;
			
			adjlist[x+N].pb(t);
			adjlist[t].pb(x+N);
			adjmat[x+N][t]=1;
		}
		
		for(z=1;z<=N;z++)
		{
			name[z].clear();
			scanf("%d",&K);
			while(K--)
			{
				scanf("%s",msk);
				int len=strlen(msk);
				for(x=0;x<len;x++) if((msk[x]>='A')&&(msk[x]<='Z')) msk[x]^=32;
				msk[0]^=32;
				name[z].pb(msk);
				
				y= msk[0]-'A'+1;
				if(y>N) continue;
				adjlist[y].pb(z+N);
				adjlist[z+N].pb(y);
				adjmat[y][z+N]=1;
			}
		}
		
		while(1)
		{
			for(x=s;x<=t;x++) 
			{
				visited[x]=false;
				path[x]=-1;
			}
			
			visited[s]=true;
			queue<int> q;
			q.push(s);
			
			while(!q.empty())
			{
				int now = q.front();q.pop();
				for(x=0;x<adjlist[now].size();x++)
				{
					int next = adjlist[now][x];
					if((!visited[next])&&(adjmat[now][next]!=0))
					{
						visited[next]=true;
						path[next]=now;
						q.push(next);
					}
				}
			}
			
			f=0;
			augment(t);
			if(!f) break;
		}
		
		printf("Case #%d:\n",i);
		for(x=1;x<=N;x++)
		{
			for(y=1+N;y<=2*N;y++) if((!adjmat[x][y])&&(adjmat[y][x])) break;
			
			y-=N;
			for(z=0;z<name[y].size();z++) if((char)(name[y][z][0])==(char)('A'+x-1))
			{
				printf("%s\n",name[y][z].c_str());
				break;
			}
		}
	}
	return 0;
}

