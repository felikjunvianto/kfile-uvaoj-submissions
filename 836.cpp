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

int x,y,z,t,N;
int pref[30][30];
char msk[30][30];
bool awal;

void hitung()
{
	N--;
	for(y=1;y<=N;y++)
		for(x=1;x<=N;x++) pref[y][x]=(msk[y][x-1]-'0')+pref[y-1][x];
		
	int ans=0;
	for(y=1;y<=N;y++)
		for(z=y;z<=N;z++)
			for(x=1;x<=N;x++) 
				if(pref[z][x]-pref[y-1][x]==z-y+1)
				{
					t=x;
					while((t<=N)&&(pref[z][t]-pref[y-1][t]==z-y+1)) t++;t--;
					ans=max(ans,(z-y+1)*(t-x+1));
					x=t;
				}
				
	if(!awal) printf("\n");
	awal=false;
	printf("%d\n",ans);
}

int main()
{
	scanf("%d",&x);getchar();getchar();
	awal=true;
	N=1;
	
	while(gets(msk[N]))
	{
		if(strlen(msk[N])==0)
		{
			hitung();
			N=1;
		} else N++;
	}
	hitung();
	
	return 0;
}

