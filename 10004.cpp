#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n,titik,garis,x,y,z;
bool adj[300][300];
int lokasi[300];
bool bisa;

void warnai(int t)
{
	int a;
	if(!bisa) return;
	for(a=0;a<titik;a++) if(adj[t][a]) 
		if(lokasi[a]==-1) 
		{
			lokasi[a] = lokasi[t]^1;
			warnai(a);
		}
		else if(lokasi[a]==lokasi[t])
		{
			bisa=false;
			return;
		}
}

int main()
{
	do
	{
		scanf("%d",&titik);
		if(titik==0) break;
		
		scanf("%d",&garis);
		memset(adj,false,sizeof(adj));
		memset(lokasi,-1,sizeof(lokasi));
		
		for(n=0;n<garis;n++)
		{
			scanf("%d %d",&x,&y);
			adj[x][y] = adj[y][x] = true;
		}
		
		lokasi[y]=0;
		bisa=true;
		warnai(0);
		
		if(bisa) printf("BICOLORABLE.\n"); else printf("NOT BICOLORABLE.\n");
	} while(titik>0);
	return 0;
}
