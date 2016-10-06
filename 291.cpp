#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

#define fi first
#define se second

using namespace std;

bool adjmat[6][6];
int x,y;
int node[8];

void jalan(int now,int t)
{
	int x;
	if(t==9)
	{
		for(x=0;x<t;x++) printf("%d",node[x]);
		printf("\n");
	} else
		for(x=1;x<=5;x++) if(adjmat[now][x])
		{
			adjmat[now][x]=false;
			adjmat[x][now]=false;
			node[t]=x;
			jalan(x,t+1);
			adjmat[now][x]=true;
			adjmat[x][now]=true;
		}
}

int main()
{
	adjmat[1][2]=true;
	adjmat[1][3]=true;
	adjmat[1][5]=true;
	adjmat[2][1]=true;
	adjmat[2][3]=true;
	adjmat[2][5]=true;
	adjmat[3][1]=true;
	adjmat[3][2]=true;
	adjmat[3][4]=true;
	adjmat[3][5]=true;
	adjmat[4][3]=true;
	adjmat[4][5]=true;
	adjmat[5][1]=true;
	adjmat[5][2]=true;
	adjmat[5][3]=true;
	adjmat[5][4]=true;
	
	node[0]=1;
	jalan(1,1);	
	return 0;
}
