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

int T,x,y,z,len,now;
char msk[10000];
bool hitam[40][40];

void quad(int xa,int xb,int ya,int yb)
{
	now++;
	if((now>=len)||(msk[now]=='e')) return;
	if(msk[now]=='f')
	{
		for(int i=xa;i<=xb;i++)
			for(int j=ya;j<=yb;j++) hitam[i][j]=true;
		return;
	}
	
	if(msk[now]=='p')
	{
		quad((xa+xb)/2+1,xb,ya,(ya+yb)/2);
		quad(xa,(xa+xb)/2,ya,(ya+yb)/2);
		quad(xa,(xa+xb)/2,(ya+yb)/2+1,yb);
		quad((xa+xb)/2+1,xb,(ya+yb)/2+1,yb);
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(hitam,false,sizeof(hitam));
		for(x=0;x<2;x++)
		{
			scanf("%s",msk);len=strlen(msk);
			now=-1;quad(1,32,1,32);
		}
		
		z=0;
		for(x=1;x<=32;x++)
			for(y=1;y<=32;y++) if(hitam[x][y]) z++;
		printf("There are %d black pixels.\n",z);
	}
	return 0;
}

