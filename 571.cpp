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

bool visited[1010][1010];
PII par[1010][1010],final;
queue<PII> q;
vector<PII> seq;
int A,B,N,x,y;

int main()
{
	while(scanf("%d %d %d",&A,&B,&N)!=EOF)
	{
		for(x=0;x<=A;x++)
			for(y=0;y<=B;y++)
			{
				visited[x][y]=false;
				par[x][y]=mp(-1,-1);
			}
		
		while(!q.empty()) q.pop();
		q.push(mp(0,0));
		visited[0][0]=true;
		while(!q.empty())
		{
			PII now = q.front();q.pop();
			
			if(now.se==N)
			{
				final = now;
				break;
			}
			
			//fill A
			if(now.fi<A && !visited[A][now.se])
			{
				visited[A][now.se]=true;
				q.push(mp(A,now.se));
				par[A][now.se]=now;
			}
			
			//fill B
			if(now.se<B && !visited[now.fi][B])
			{	
				visited[now.fi][B]=true;
				q.push(mp(now.fi,B));
				par[now.fi][B]=now;
			}
			
			//empty A
			if(now.fi>0 && !visited[0][now.se])
			{
				visited[0][now.se]=true;
				q.push(mp(0,now.se));
				par[0][now.se]=now;
			}
			
			//empty B
			if(now.se>0 && !visited[now.fi][0])
			{
				visited[now.fi][0]=true;
				q.push(mp(now.fi,0));
				par[now.fi][0]=now;
			}
			
			//pour A to B
			if(now.se<B && now.fi>0)
			{
				int poured = min(now.fi,B-now.se);
				if(!visited[now.fi-poured][now.se+poured])
				{
					visited[now.fi-poured][now.se+poured]=true;
					q.push(mp(now.fi-poured,now.se+poured));
					par[now.fi-poured][now.se+poured]=now;
				}
			}
			
			//pour B to A
			if(now.se>0 && now.fi<A)
			{
				int poured = min(now.se,A-now.fi);
				if(!visited[now.fi+poured][now.se-poured])
				{
					visited[now.fi+poured][now.se-poured]=true;
					q.push(mp(now.fi+poured,now.se-poured));
					par[now.fi+poured][now.se-poured]=now;
				}
			}
		}
	
		
		seq.clear();
		while(final!=mp(-1,-1))
		{
			seq.pb(final);
			final = par[final.fi][final.se];
		}
		
		for(x=seq.size()-1;x;x--) 
		{
			PII now = seq[x];
			PII next = seq[x-1];
			
			if(now.se==next.se && next.fi==A) printf("fill A\n"); else
			if(now.fi==next.fi && next.se==B) printf("fill B\n"); else
			if(now.se==next.se && next.fi==0) printf("empty A\n"); else
			if(now.fi==next.fi && next.se==0) printf("empty B\n"); else
			if(next.se>now.se) printf("pour A B\n"); else
			if(next.fi>now.fi) printf("pour B A\n");
		}
		printf("success\n");
	}
	return 0;
}

