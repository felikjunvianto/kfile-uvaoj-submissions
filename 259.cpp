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

vector<string> inp;
vector<char> prog;
bool visited[40];
int adjmat[40][40];
int path[40],f,mf,tot;
int s = 36,t=37;
char msk[100];

void augment(int now)
{
	if(now==s) f=1; else if(path[now]!=-1)
	{
		augment(path[now]);
		adjmat[path[now]][now]-=f;
		adjmat[now][path[now]]+=f;
	}
}

void solve()
{
	int x,y,z;
	vector<int> adjlist[40];
	
	memset(adjmat,0,sizeof(adjmat));
	for(x=0;x<10;x++) 
	{
		adjmat[x][t]=1;
		adjlist[x].pb(t);
		adjlist[t].pb(x);
	}
	
	tot = 0;
	prog.clear();
	for(x=0;x<inp.size();x++)
	{
		char now = inp[x][0];
		int byk = (int)(inp[x][1]-'0');
		tot+=byk;
		
		prog.pb(now);
		y=9+(int)prog.size();
		adjmat[s][y]=byk;
		adjlist[s].pb(y);
		adjlist[y].pb(s);
			
		for(z=3;inp[x][z]!=';';z++)
		{
			int a =(int)(inp[x][z]-'0');
			adjmat[y][a]=1;
			adjlist[y].pb(a);
			adjlist[a].pb(y);
		}
	}
	
	mf=0;
	while(1)
	{
		memset(visited,false,sizeof(visited));
		memset(path,-1,sizeof(path));
		queue<int> q;
		q.push(s);
		visited[s]=true;
		
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
		mf+=f;
	}
	
	if(mf!=tot) printf("!\n"); else
	{
		char ans[15];ans[10]='\0';
		for(x=0;x<10;x++)
		{
			ans[x]='_';
			for(y=0;y<prog.size();y++)
				if((!adjmat[y+10][x])&&(adjmat[x][y+10]))
				{
					ans[x]=prog[y];
					break;
				}
		}
		
		printf("%s\n",ans);
	}
}

int main()
{
	while(gets(msk))
	{
		if(strlen(msk)==0)
		{
			solve();
			inp.clear();
		} else inp.pb(msk);
	}
	solve();
	return 0;
}

