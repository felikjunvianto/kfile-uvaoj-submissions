/*
	Algoritma: Pertama-tama terapkan max flow pada graf yang ada hingga tidak ada augmenting path lagi.
			   Lalu lakukan flood fill dari source. Sebuah node bisa dijelajahi dari node lain jika
			   kapasitas dari edge yang menghubungkan mereka tidak 0.
			   
			   Untuk mencari himpunan edge minimal yang perlu dipotong, lakukan looping O(N^2) untuk mencari
			   edge di mana salah satu sisi terkunjungi pada floodfill sebelumnya dan sisi lainya tidak terkunjungi
			   (atau bisa juga dengan kapasitas edge = 0, dan kapasitas backflow nya = kapasitas edge awal).
 */

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

int N,E;
int x,y,z,f;
int path[60];
vector<int> adjlist[60];
vector<PII> edgelist;
bool visited[60];
int adjmat[60][60];

void flow(int now,int v)
{
	if(now==1) f=v; else if(path[now]!=-1)
	{
		flow(path[now],min(v,adjmat[path[now]][now]));
		adjmat[path[now]][now]-=f;
		adjmat[now][path[now]]+=f;
	}
}

void ff(int now)
{
	for(int i=0;i<adjlist[now].size();i++)
	{
		int next=adjlist[now][i];
		if((!visited[next])&&(adjmat[now][next]))
		{
			visited[next]=true;
			ff(next);
		}
	}
}

int main()
{
	while(1)
	{
		scanf("%d %d",&N,&E);
		if(N+E==0) break;
		
		edgelist.clear();
		for(x=1;x<=N;x++) adjlist[x].clear();
		
		memset(adjmat,0,sizeof(adjmat));
		while(E--)
		{
			scanf("%d %d %d",&x,&y,&z);
			adjmat[x][y]=adjmat[y][x]=z;
			adjlist[x].pb(y);
			adjlist[y].pb(x);
			edgelist.pb(mp(x,y));
		}
		
		while(1)
		{
			memset(path,-1,sizeof(path));
			memset(visited,false,sizeof(visited));
			queue<int> q;
			visited[1]=true;
			q.push(1);
			
			while(!q.empty())
			{
				x = q.front();q.pop();
				for(y=0;y<adjlist[x].size();y++)
				{
					z=adjlist[x][y];
					if((!visited[z])&&(adjmat[x][z]))
					{
						visited[z]=true;
						q.push(z);
						path[z]=x;
					}
				}
			}
			
			f=0;
			flow(2,INF);
			if(!f) break;
		}
		
		memset(visited,false,sizeof(visited));
		visited[1]=true;
		ff(1);
		
		for(x=0;x<edgelist.size();x++)
		{
			y=edgelist[x].fi,z=edgelist[x].se;
			if((visited[y])^(visited[z])) printf("%d %d\n",y,z);
		}
		printf("\n");
	}
	return 0;
}

