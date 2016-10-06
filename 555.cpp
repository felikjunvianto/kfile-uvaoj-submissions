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

char order[] = {'S', 'W', 'N', 'E'};
char color[] = {'C', 'D', 'S', 'H'};
char value[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
char c[2], msk[100];
int now,x,y,z;
string deck;
vector<PII> card[5];

int main()
{
	while(1)
	{
		scanf("%s",c);
		if(c[0]=='#') break;
		
		for(now = 0;now<4;now++) if(c[0]==order[now]) break;
		deck.clear();
		for(x = 0; x<2;x++) 
		{
			scanf("%s",msk);
			deck+=msk;
		}
		
		for(x=0;x<4;x++) card[x].clear();
		
		for(x=0;x<deck.size();x+=2) 
		{
			for(y=0;y<4;y++) if(deck[x]==color[y]) break;
			for(z=0;z<13;z++) if(deck[x+1]==value[z]) break;
			
			now = (now+1)%4;
			card[now].pb(mp(y,z));
		}
		
		for(x=0;x<4;x++)
		{
			printf("%c:",order[x]);
			sort(card[x].begin(),card[x].end());
			for(y=0;y<card[x].size();y++) printf(" %c%c",color[card[x][y].fi],value[card[x][y].se]);
			printf("\n");
		}
	}
	return 0;
}

