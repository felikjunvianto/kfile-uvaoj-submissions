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

using namespace std;

int N,T,start;
vector<int> adjlist[2600];
vector<int> tahu[2];
int x,y,z,large,when;
bool visited[2600];

int main()
{
	scanf("%d",&T);
	for(x=0;x<T;x++)
	{
		scanf("%d",&z);
		while(z--)
		{
			scanf("%d",&y);
			adjlist[x].pb(y);
		}
	}
	
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&start);
		if(adjlist[start].size()==0) printf("0\n"); else
		{
			int next,now=0;
			tahu[0].clear();
			tahu[0].pb(start);
			memset(visited,false,sizeof(visited));
			visited[start]=true;
			
			large=when=z=0;
			do
			{
				z++;
				next=now^1;
				tahu[next].clear();
				
				for(x=0;x<tahu[now].size();x++)
				{
					int i=tahu[now][x];
					for(y=0;y<adjlist[i].size();y++) if(!visited[adjlist[i][y]])
					{
						visited[adjlist[i][y]]=true;
						tahu[next].pb(adjlist[i][y]);
					}
					
					if(large<tahu[next].size())
					{
						large=tahu[next].size();
						when=z;
					}
				}
				now=next;
			}while(tahu[next].size()>0);
			
			printf("%d %d\n",large,when);
		}
	}
	return 0;
}

