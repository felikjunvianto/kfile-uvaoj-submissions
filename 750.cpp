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

int T,x,y,z;
bool bawah[10],tambah[20],kurang[20];
int list[10];

void bt(int now)
{
	int a;
	if(now==x) bt(now+1); else
	if(now==9)
	{
		printf("%2d     ",++z);
		for(a=1;a<=8;a++) printf(" %d",list[a]);
		printf("\n");
	} else
		for(a=1;a<=8;a++) if((bawah[a])&&(tambah[a+now])&&(kurang[a-now+10]))
		{
			bawah[a]=tambah[a+now]=kurang[a-now+10] = false;
			list[now]=a;
			bt(now+1);
			bawah[a]=tambah[a+now]=kurang[a-now+10] = true;
		}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		z=0;
		scanf("%d %d",&y,&x);
		memset(bawah,true,sizeof(bawah));
		memset(tambah,true,sizeof(tambah));
		memset(kurang,true,sizeof(kurang));
		list[x]=y;
		bawah[y]=tambah[y+x]=kurang[y-x+10]=false;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		bt(1);
		if(T) printf("\n");
	}
	return 0;
}

