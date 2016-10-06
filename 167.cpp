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

using namespace std;

int T,temp,best;
int x,y,z;
int peta[10][10];
vector<vector<int> > list;
vector<int> now;
bool hor[10],ver[10],tambah[20],kurang[20];

bool boleh(int x,int y)
{
	if(hor[x]) return false;
	if(ver[y]) return false;
	if(tambah[x+y]) return false;
	if(kurang[x-y+10]) return false;
	return true;
}

void bt(int N)
{
	if(N==9) list.pb(now); else
		for(int x=1;x<=8;x++) if(boleh(x,N))
		{
			hor[x]=ver[N]=tambah[x+N]=kurang[x-N+10]=true;
			now[N]=x;
			bt(N+1);
			now[N]=0;
			hor[x]=ver[N]=tambah[x+N]=kurang[x-N+10]=false;
		}
}

int main()
{
	for(x=0;x<10;x++) now.pb(0);
	memset(hor,false,sizeof(hor));
	memset(ver,false,sizeof(ver));
	memset(tambah,false,sizeof(tambah));
	memset(kurang,false,sizeof(kurang));
	bt(1);
	
	scanf("%d",&T);
	while(T--)
	{
		for(y=1;y<=8;y++)
			for(x=1;x<=8;x++) scanf("%d",&peta[x][y]);
			
		best=0;
		for(z=0;z<list.size();z++)
		{
			temp=0;
			for(y=1;y<=8;y++) temp+=peta[list[z][y]][y];
			best=max(best,temp);
		}
		printf("%5d\n",best);
	}
	return 0;
}

