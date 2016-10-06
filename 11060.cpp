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

int N,M,T,x,y;
char masuk[70];
map<string,int> indeks;
vector<string> drink;
vector<int> adjlist[110];
int par[110];

int main()
{
	T=0;
	while(scanf("%d",&N)!=EOF)
	{
		drink.clear();
		indeks.clear();
		for(x=0;x<N;x++)
		{
			scanf("%s",masuk);
			indeks[masuk]=x;
			drink.pb(masuk);
			adjlist[x].clear();
		}
		memset(par,0,sizeof(par));
		scanf("%d",&M);
		while(M--)
		{
			scanf("%s",masuk);x=indeks[masuk];
			scanf("%s",masuk);y=indeks[masuk];
			par[y]++;
			adjlist[x].pb(y);
		}
		
		printf("Case #%d: Dilbert should drink beverages in this order:",++T);
		for(x=0;x<N;x++)
		{
			int next=-1;
			for(y=0;y<N;y++) if((next==-1)||(par[next]>par[y])) next=y;
			printf(" %s",drink[next].c_str());
			par[next]=INF;
			for(y=0;y<adjlist[next].size();y++) par[adjlist[next][y]]--;
		}
		printf(".\n\n");
	}
	return 0;
}

