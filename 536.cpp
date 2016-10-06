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

char pre[30], in[30];
PII adjlist[30];

void solve(string preord, string inord)
{
	int root = preord[0]-'A';
	string tofind = ""; tofind += preord[0];
	
	int rootloc = inord.find(tofind);
	int left, right;
	if(rootloc) left = 1; else left = -1;
	if(rootloc+1 < inord.size()) right = 1 + rootloc; else right = -1;
	
	if(left!=-1) adjlist[root].fi = preord[left]-'A';
	if(right!=-1) adjlist[root].se = preord[right]-'A';
	
	string leftpre = preord.substr(1,rootloc), rightpre = preord.substr(rootloc+1);
	string leftin = inord.substr(0,rootloc), rightin = inord.substr(rootloc+1);
	
	if(leftpre.size() && leftin.size()) solve(leftpre, leftin);
	if(rightpre.size() && rightin.size()) solve(rightpre, rightin);
}

void print(int now)
{
	if(adjlist[now].fi!=-1) print(adjlist[now].fi);
	if(adjlist[now].se!=-1) print(adjlist[now].se);
	printf("%c",now+'A');
}

int main()
{
	while(scanf("%s %s",pre,in)!=EOF)
	{
		for(int x = 0; x < 26;x++) adjlist[x]=mp(-1,-1);
		solve(pre,in);
		print(pre[0]-'A'); printf("\n");
	}
	return 0;
}

