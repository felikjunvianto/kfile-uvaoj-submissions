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

bool state[20000]; // X=1,O=2
int conf[8][3]={{0,1,2},{0,4,8},{0,3,6},{1,4,7},
				{2,4,6},{2,5,8},{3,4,5},{6,7,8}};
int tiga[15];
int x,y,z,T;
queue<PII> q;
char masuk[5];

void ubah(int N)
{
	int x=0;
	while(N>0)
	{
		tiga[x++]=N%3;
		N/=3;
	}
	while(x<9) tiga[x++]=0;
}

int konver()
{
	int ans=0,kali=1;
	for(int x=0;x<9;x++)
	{
		ans+=tiga[x]*kali;
		kali*=3;
	}
	return(ans);
}

bool menang(int p)
{
	for(int x=0;x<8;x++) 
	{
		bool sama=true;
		for(int y=0;(y<3)&&sama;y++) if(tiga[conf[x][y]]!=p) sama=false;
		if(sama) return(true);
	}
	return(false);
}

int main()
{
	memset(state,false,sizeof(state));
	state[0]=true;
	
	q.push(mp(0,1));
	while(!q.empty())
	{
		PII now=q.front();
		q.pop();
		
		ubah(now.fi);
		if(menang(3-now.se)) continue;
		for(x=0;x<9;x++) if(tiga[x]==0)
		{
			tiga[x]=now.se;
			int next=konver();
			if(!state[next])
			{
				q.push(mp(next,3-now.se));
				state[next]=true;
			}
			tiga[x]=0;
		}
	}
	
	scanf("%d",&T);
	while(T--)
	{
		for(y=0;y<3;y++)
		{
			scanf("%s",masuk);
			for(x=0;x<3;x++)
			{
				z=y*3+x;
				switch(masuk[x])
				{
					case('.') : tiga[z]=0;break;
					case('X') : tiga[z]=1;break;
					case('O') : tiga[z]=2;break;
				}
			}
		}
		
		z=konver();
		if(state[z]) printf("yes\n"); else printf("no\n");
	}
	return 0;
}

