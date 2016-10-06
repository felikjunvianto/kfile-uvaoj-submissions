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

int C,S,x,y,d,i;
int spe[11];
vector<int> ch[5];
double AM,IM;

int main()
{
	i = 0;
	while(scanf("%d %d",&C,&S)!=EOF)
	{
		AM = IM = 0;
		for(y=0;y<C;y++) ch[y].clear();
		for(x=0;x<S;x++)
		{
			scanf("%d",&spe[x]);
			AM += (double)spe[x];
		} AM/=(double)C;
		
		sort(spe,spe+S);
		x=S-1;
		for(y=0;(y<C)&&(x>=0);y++) ch[y].pb(spe[x--]);
		for(y=C-1;(y>=0)&&(x>=0);y--) ch[y].pb(spe[x--]);
		
		printf("Set #%d\n",++i);
		for(y=0;y<C;y++) 
		{
			printf(" %d:",y);
			double tmp = 0;
			for(x=0;x<ch[y].size();x++) 
			{
				printf(" %d",ch[y][x]);
				tmp+=(double)ch[y][x];
			}
			printf("\n");
			IM += fabs(tmp-AM);
		}
		printf("IMBALANCE = %.5lf\n\n",IM);
	}
	return 0;
}

