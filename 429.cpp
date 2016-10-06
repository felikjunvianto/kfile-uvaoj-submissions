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

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>

using namespace std;

int t,x,y,panjang;
char masuk[30];
vector<string> dict[20];
bool cari;

void shortdist()
{
	queue<pair<string,int> > q;
	vector<bool> visited;
	int n,x,y,z;
	string kata1,kata2;
	kata1=kata2="";
	for(x=0;x<panjang;x++) if(masuk[x]==' ') break;
	for(y=0;y<x;y++) kata1+=masuk[y];
	for(y=x+1;y<panjang;y++) kata2+=masuk[y];
	
	q.push(mp(kata1,0));
	bool ketemu=false;
	int basis=kata1.size();
	for(x=0;x<dict[basis].size();x++) 
		if(kata1==dict[basis][x]) visited.pb(true); else visited.pb(false);
	
	do
	{
		string kata3=q.front().fi;
		if(kata3==kata2) ketemu=true; else
		{
			for(x=0;x<dict[basis].size();x++) if(!visited[x])
			{
				int beda=0;
				for(y=0;y<basis;y++)
					if(kata3[y]!=dict[basis][x][y]) beda++;
				
				if(beda==1) 
				{
					q.push(mp(dict[basis][x],q.front().se+1));
					visited[x]=true;
				}
			}
			q.pop();
		}
	}while((!q.empty())&&(!ketemu));
	printf("%s %s %d\n",kata1.c_str(),kata2.c_str(),q.front().se);
}

int main()
{
	t=0;
	scanf("%d\n",&x);
	cari=false;
	while(gets(masuk))
	{
		panjang=strlen(masuk);
		if(panjang==0)
		{
			t++;
			if(t>1) printf("\n");
			cari=false;
			for(x=0;x<20;x++) dict[x].clear();
			printf("\n");
		} else
		
		if(masuk[0]=='*') cari=true; else
		if(!cari) dict[panjang].pb(masuk); else
		if(cari) shortdist();
	}
	return 0;
}

