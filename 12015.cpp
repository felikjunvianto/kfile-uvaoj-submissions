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

typedef struct
{
	int nilai,urut;
	string nama;
} cell;

cell web[20];
int T,x,y,i;
char msk[111];

bool cf(cell i,cell j)
{
	if(i.nilai!=j.nilai) return(i.nilai>j.nilai);
	return(i.urut<j.urut);
}

int main()
{
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		for(x=0;x<10;x++)
		{
			scanf("%s %d",msk,&y);
			web[x]=(cell){y,x,msk};
		}
		sort(web,web+10,cf);
		
		y=web[0].nilai;
		printf("Case #%d:\n",i);
		for(x=0;x<10;x++) if(web[x].nilai==y)
			printf("%s\n",web[x].nama.c_str());
	}
	return 0;
}

