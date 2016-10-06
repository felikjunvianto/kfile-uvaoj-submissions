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
	int num,solved,pen;
} team;

team tim[111];
int solved[111][11];
int penalty[111][11];
char baca[111],ver[2];
int x,N,prob,sec;
bool submit[111];

bool cf(team i, team j)
{
	if(i.solved!=j.solved) return(i.solved>j.solved);
	if(i.pen!=j.pen) return(i.pen<j.pen);
	return(i.num<j.num);
}

void initialize()
{
	memset(solved,-1,sizeof(solved));
	memset(penalty,0,sizeof(penalty));
	memset(submit,false,sizeof(submit));
}

void solve()
{
	for(x=1;x<=100;x++)
	{
		int score=0,total=0;
		for(int y=1;y<10;y++) if(solved[x][y]!=-1)
		{
			score++;
			total+=solved[x][y]+penalty[x][y]*20;
		}
		tim[x]=(team){x,score,total};
	}
	
	sort(tim+1,tim+101,cf);
	for(x=1;x<=100;x++) if(submit[tim[x].num])
		printf("%d %d %d\n",tim[x].num,tim[x].solved,tim[x].pen);
}

int main()
{
	scanf("%d",&x);getchar();
	gets(baca);
	initialize();
	
	while(gets(baca))
	{
		if(!strlen(baca)) 
		{
			solve();
			printf("\n");
			initialize();
			continue;
		}
		
		sscanf(baca,"%d %d %d %s",&N,&prob,&sec,ver);
		submit[N]=true;
		switch(ver[0])
		{
			case('C') : if(solved[N][prob]==-1) solved[N][prob]=sec;break;
			case('I') : if(solved[N][prob]==-1) penalty[N][prob]++;break;
		}
	}
	solve();
	return 0;
}

