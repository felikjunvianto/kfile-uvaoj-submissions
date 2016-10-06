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
#define PLL pair<LL,LL>
#define LL long long
#define INF 1000000000

using namespace std;

int dx[]={ 1, 0,-1, 0};
int dy[]={ 0, 1, 0,-1};

int N,i,j,k,bawah,samping;
pair<PLL,PLL> seg[111];
vector<LL> X,Y;
map<LL,int> idX,idY;
char grid[410][410];

void compressGrid()
{
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	samping=unique(X.begin(),X.end())-X.begin();
	bawah=unique(Y.begin(),Y.end())-Y.begin();
	
	idX.clear();
	for(int a=0;a<samping;a++) idX[X[a]]=a*2+1;
	
	idY.clear();
	for(int a=0;a<bawah;a++) idY[Y[a]]=a*2+1;	
}

void ff(int x,int y)
{
	for(int z=0;z<4;z++)
	{
		int sx=x+dx[z],sy=y+dy[z];
		if((sx<0)||(sy<0)||(sx>samping)||(sy>bawah)) continue;
		if(grid[sx][sy]!='.') continue;
		
		grid[sx][sy]='#';
		ff(sx,sy);
	}
}

void constructGrid()
{
	samping*=2;
	bawah*=2;
	for(i=0;i<=samping;i++)
		for(j=0;j<=bawah;j++) grid[i][j]='.';
		
	for(k=0;k<N;k++)
	{
		int newX1=min(idX[seg[k].fi.fi],idX[seg[k].se.fi]);
		int newY1=min(idY[seg[k].fi.se],idY[seg[k].se.se]);
		int newX2=max(idX[seg[k].fi.fi],idX[seg[k].se.fi]);
		int newY2=max(idY[seg[k].fi.se],idY[seg[k].se.se]);
		
		for(i=newX1;i<=newX2;i++)
			for(j=newY1;j<=newY2;j++) grid[i][j]='@';
	}
	
	grid[0][0]='#';
	ff(0,0);
	
	for(i=0;i<=samping;i++)
		for(j=0;j<=bawah;j++) if(grid[i][j]=='@')
			if(((grid[i-1][j]=='.')&&(grid[i+1][j]=='.'))||
			   ((grid[i][j-1]=='.')&&(grid[i][j+1]=='.')))
					grid[i][j]='.';
}

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		X.clear();
		Y.clear();
		for(i=0;i<N;i++)
		{
			scanf("%lld %lld %lld %lld",&seg[i].fi.fi,&seg[i].fi.se,&seg[i].se.fi,&seg[i].se.se);
			X.pb(seg[i].fi.fi);X.pb(seg[i].se.fi);
			Y.pb(seg[i].fi.se);Y.pb(seg[i].se.se);
		}
		
		compressGrid();
		constructGrid();
		
		int ans=0;
		for(i=1;i<samping;i++)
			for(j=1;j<bawah;j++) if(grid[i][j]=='.')
			{
				ans++;
				grid[i][j]='#';
				ff(i,j);
			}
		
		printf("%d\n",ans);
	}
	return 0;
}

