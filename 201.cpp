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

char grid[20][20];
int x,y,z,n,t,i,j,sekarang,ukuran,total,garis;
char tipe[2];
bool ada;

bool oke(int x,int y,int arah)
{
	PII jalan[2];
	jalan[0]=mp(1,0);
	jalan[1]=mp(0,1);
	int z;
	
	for(z=0;z<sekarang;z++) if(grid[x+jalan[arah].fi*z][y+jalan[arah].se*z]!='x') return(false);
	return(true);
}

int main()
{
	t=1;
	while(scanf("%d",&n)!=EOF)
	{
		memset(grid,'.',sizeof(grid));
		ukuran=2*n-1;
		scanf("%d",&garis);
		while(garis--)
		{
			scanf("%s %d %d",tipe,&i,&j);
			i=i*2-1;
			j=j*2-1;
			if(tipe[0]=='H') for(x=0;x<3;x++) grid[j+x][i]='x';
				else for(x=0;x<3;x++) grid[i][j+x]='x';
		}
		
		if(t>1) printf("\n**********************************\n\n");
		printf("Problem #%d\n\n",t++);
		ada=false;
		
		for(z=1;z<n;z++)
		{
			total=0;
			sekarang=2*z+1;
			for(y=1;y<=ukuran-sekarang+1;y++)
				for(x=1;x<=ukuran-sekarang+1;x++) if(grid[x][y]=='x')
					if((x+sekarang-1<=ukuran)&&(y+sekarang-1<=ukuran))
						if(oke(x,y,0)&&oke(x,y,1)&&oke(x+sekarang-1,y,1)&&oke(x,y+sekarang-1,0)) total++;
					
			if(total>0) 
			{
				ada=true;
				printf("%d square (s) of size %d\n",total,z);
			}
		}
		if(!ada) printf("No completed squares can be found.\n");
	}
	return 0;
}

