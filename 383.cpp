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

int port,edge,query;
vector<int> adjlist[700];
vector<int> list;
int t,x,y,z,weight;
bool visited[700],bisa;
queue<PII> q;
char port1[3],port2[3];

int kode(string cari)
{
	return((cari[0]-'A')*26+(cari[1]-'A'));
}

int main()
{
	scanf("%d",&t);
	printf("SHIPPING ROUTES OUTPUT\n\n");
	for(z=1;z<=t;z++)
	{
		printf("DATA SET  %d\n\n",z);
		scanf("%d %d %d",&port,&edge,&query);
		list.clear();
		
		for(x=0;x<port;x++) 
		{
			scanf("%s",port1);
			list.pb(kode(port1));
			adjlist[list.back()].clear();
		}
		
		for(x=0;x<edge;x++)
		{
			scanf("%s %s",port1,port2);
			adjlist[kode(port1)].pb(kode(port2));
			adjlist[kode(port2)].pb(kode(port1));
		}
			
		for(x=0;x<query;x++)
		{
			scanf("%d %s %s",&weight,port1,port2);
			while(!q.empty()) q.pop();
			for(y=0;y<list.size();y++) visited[list[y]]=false;
			q.push(mp(kode(port1),0));
			visited[kode(port1)]=true;
			bisa=false;
			
			while((!q.empty())&&(!bisa))
			{
				if(q.front().fi==kode(port2)) bisa=true; else
				{
					for(y=0;y<adjlist[q.front().fi].size();y++)
						if(!visited[adjlist[q.front().fi][y]])
						{
							visited[adjlist[q.front().fi][y]]=true;
							q.push(mp(adjlist[q.front().fi][y],q.front().se+1));
						}
					q.pop();
				}
			}
			
			if(bisa) printf("$%d\n",weight*q.front().se*100); else
				printf("NO SHIPMENT POSSIBLE\n");
		}
		printf("\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}

