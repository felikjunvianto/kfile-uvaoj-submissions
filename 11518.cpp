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

int T, N, M, L, x, y, z;
bool fall[10010];
vector<int> adjlist[10010];
queue<int> q;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&N, &M, &L);
		for(x=1;x<=N;x++)
		{
			fall[x] = false;
			adjlist[x].clear();
		}
		
		while(M--)
		{
			scanf("%d %d",&x,&y);
			adjlist[x].pb(y);
		}
		
		while(L--)
		{
			scanf("%d",&x);
			if(fall[x]) continue;
			fall[x] = true;
			
			q.push(x);
			while(!q.empty())
			{
				x = q.front();q.pop();
				for(y=0;y<adjlist[x].size();y++) if(!fall[adjlist[x][y]])
				{
					fall[adjlist[x][y]]=true;
					q.push(adjlist[x][y]);
				}
			}
		}
		
		z = 0;
		for(x=1;x<=N;x++) if(fall[x]) z++;
		printf("%d\n",z);
	}
	return 0;
}

