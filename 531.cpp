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

map<string,int> indeks;
char masuk[4000];
int x,y,z,t,now,panjang;
int dp[300][300];
PII path[300][300];
vector<int> ban[2];
vector<string> dict;

int solve(int a,int b)
{
	if((a==ban[0].size())||(b==ban[1].size())) return 0;
	if(dp[a][b]!=-1) return(dp[a][b]);
	
	int &ret = dp[a][b];
	if(ban[0][a]==ban[1][b]) 
	{
		path[a][b]=mp(a+1,b+1);
		ret = 1+solve(a+1,b+1); 
	} else
	{
		int amaju=solve(a+1,b);
		int bmaju=solve(a,b+1);
		
		if(amaju>bmaju) path[a][b]=mp(a+1,b); else path[a][b]=mp(a,b+1);
		ret=max(amaju,bmaju);
	}
	return(ret);
}

void jawab()
{
	memset(dp,-1,sizeof(dp));
	int N=solve(0,0);
	x=y=0;
	while(N>0)
	{
		if(ban[0][x]==ban[1][y]) 
		{
			printf("%s",dict[ban[0][x]].c_str());
			N--;
			if(N) printf(" "); else printf("\n");
		}
		PII temp=path[x][y];
		x=temp.fi;
		y=temp.se;
	}
	indeks.clear();
	ban[0].clear();ban[1].clear();
	dict.clear();
	z=now=0;
}

int main()
{
	z=now=0;
	while(gets(masuk))
	{
		if((masuk[0]=='#')&&(z==0)) z++; else
		if((masuk[0]=='#')&&(z==1)) jawab(); else
		{
			panjang=strlen(masuk);
			x=-1;
			do
			{
				x++;
				while((masuk[x]==' ')&&(x<panjang)) x++;
				if(x==panjang) break;
				
				y=x;
				while((masuk[y]!=' ')&&(y<panjang)) y++;y--;
				string temp="";
				for(t=x;t<=y;t++) temp+=masuk[t];
				if(indeks.find(temp)==indeks.end()) 
				{
					indeks[temp]=now++;
					dict.pb(temp);
				}
				ban[z].pb(indeks[temp]);
				x=y;
			} while(x+1<panjang);
		}
	}
	return 0;
}

