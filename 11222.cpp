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

int cnt[10010];
int T,N,x,y,z;
int play[3];
vector<int> mentah[3],asli[3];

bool cf(int i,int j)
{
	if((int)asli[i].size()!=(int)asli[j].size()) 
		return((int)asli[i].size()>(int)asli[j].size());
	return(i<j);
}

int main()
{
	scanf("%d",&T);
	for(z=1;z<=T;z++)
	{
		memset(cnt,0,sizeof(cnt));
		for(x=0;x<3;x++)
		{
			play[x]=x;
			mentah[x].clear();
			scanf("%d",&N);
			while(N--)
			{
				scanf("%d",&y);
				mentah[x].pb(y);
				cnt[y]++;
			}
		}
		
		for(x=0;x<3;x++)
		{
			asli[x].clear();
			for(y=0;y<mentah[x].size();y++) if(cnt[mentah[x][y]]==1)
				asli[x].pb(mentah[x][y]);
		}
		sort(play,play+3,cf);
		x=0;
		
		printf("Case #%d:\n",z);
		while((asli[play[x]].size()==asli[play[0]].size())&&(x<3))
		{
			printf("%d %d",play[x]+1,asli[play[x]].size());
			sort(asli[play[x]].begin(),asli[play[x]].end());
			for(y=0;y<asli[play[x]].size();y++) printf(" %d",asli[play[x]][y]);
			printf("\n");
			x++;
		}
	}
	return 0;
}

