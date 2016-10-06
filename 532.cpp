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

char peta[40][40][40];
int dalam,bawah,samping,x,y,z,waktu;
int dx,dy,dz;
int fin_x,fin_y,fin_z;
queue<pair<PII,PII> > q;

int main()
{
	do
	{
		scanf("%d %d %d\n",&dalam,&bawah,&samping);
		if(dalam+bawah+samping==0) break;
		
		for(z=0;z<dalam;z++)
		{
			for(y=0;y<bawah;y++)
			{
				for(x=0;x<samping;x++)
				{
					scanf("%c",&peta[x][y][z]);
					if(peta[x][y][z]=='S') 
					{
						q.push(mp(mp(x,y),mp(z,0)));
						peta[x][y][z]='@';
					}
					if(peta[x][y][z]=='E')
					{
						fin_x=x;
						fin_y=y;
						fin_z=z;
						peta[x][y][z]='.';
					}	
				}
				getchar();
			}
			getchar();
		}
		
		waktu=-1;
		do
		{
			x=q.front().fi.fi;
			y=q.front().fi.se;
			z=q.front().se.fi;
			
			if((x==fin_x)&&(y==fin_y)&&(z==fin_z)) waktu=q.front().se.se; else
			for(dx=-1;dx<=1;dx++)
				for(dy=-1;dy<=1;dy++)
					for(dz=-1;dz<=1;dz++)
						if(abs(dx)+abs(dy)+abs(dz)==1)
							if((x+dx>=0)&&(x+dx<samping)&&(y+dy>=0)&&(y+dy<bawah)&&(z+dz>=0)&&(z+dz<dalam))
								if(peta[x+dx][y+dy][z+dz]=='.')
								{
									peta[x+dx][y+dy][z+dz]='@';
									q.push(mp(mp(x+dx,y+dy),mp(z+dz,q.front().se.se+1)));
								}
			q.pop();
		}while(!q.empty());
		
		if(waktu==-1) printf("Trapped!\n"); else
			printf("Escaped in %d minute(s).\n",waktu);
	}while(dalam+bawah+samping!=0);
	return 0;
}

