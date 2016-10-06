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

int dx[]={-1, 0, 1, 0};
int dy[]={ 0,-1, 0, 1};

int bawah,samping,x,y,z;
char peta[230][230],tanda;
int total,terbesar,ans;
bool cycle;

void ff(int x,int y)
{
	ans++;
	if((x==1)||(y==1)||(x==samping*3)||(y==bawah*3)) cycle=false;
	for(int t=0;t<4;t++)
	{
		int sx=x+dx[t],sy=y+dy[t];
		if((sx>=1)&&(sx<=samping*3)&&(sy>=1)&&(sy<=bawah*3))
			if(peta[sx][sy]=='.')
			{
				peta[sx][sy]='!';
				ff(sx,sy);
			}
	}
}

int main()
{
	z=0;
	while(1)
	{
		scanf("%d %d",&samping,&bawah);getchar();
		if(samping+bawah==0) break;
		
		for(x=1;x<=samping*3;x++)
			for(y=1;y<=bawah*3;y++) peta[x][y]='.';
			
		for(y=1;y<=bawah;y++)
		{
			for(x=1;x<=samping;x++)
			{
				scanf("%c",&tanda);
				int a=1+(y-1)*3;
				int b,c;
				if(tanda=='/')
				{
					b=3*x;
					c=-1;
				} else
				{
					b=1+(x-1)*3;
					c=1;
				}
				
				for(int m=0;m<3;m++)
				{
					peta[b][a]='x';
					b+=c;
					a++;
				}
			}
			getchar();
		}
		
		total=0;
		terbesar=-1;
		for(x=1;x<=samping*3;x++)
			for(y=1;y<=bawah*3;y++) if(peta[x][y]=='.')
			{
				peta[x][y]='!';
				ans=0;
				cycle=true;
				ff(x,y);
				if(cycle)
				{
					total++;
					terbesar=max(terbesar,ans);
				}
			}
			
		printf("Maze #%d:\n",++z);
		if(!total) printf("There are no cycles.\n"); else
			printf("%d Cycles; the longest has length %d.\n",total,terbesar/3);
		printf("\n");
	}
	return 0;
}

