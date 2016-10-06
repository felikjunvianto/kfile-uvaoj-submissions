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

int x,y,val,len,cnt;
char masuk[1000];
map<int,bool> vis;
map<int,int> node;
bool valid;

void tulis()
{
	for(map<int,bool>::iterator m=vis.begin();m!=vis.end();m++) if(!m->se) valid=false;
	if(!valid) printf("not complete"); else
	for(map<int,bool>::iterator m=vis.begin();m!=vis.end();m++)
	{
		x=m->fi;
		printf("%d",node[x]);
		cnt--;
		if(cnt) printf(" ");
	}printf("\n");
	valid=true;
	vis.clear();
	cnt=0;
}

void tambah()
{
	val=0;
	x=1;
	len=strlen(masuk);
	while((masuk[x]>='0')&&(masuk[x]<='9')&&(x<len)) val=val*10+(masuk[x++]-'0');
	y=0;
	while(x+1<len)
	{
		switch(masuk[x])
		{
			case('L') : y=y*2+1;break;
			case('R') : y=y*2+2;break;
		}
		if(vis.find(y)==vis.end()) vis[y]=false;
		x++;
	}
	if((vis[y])&&(node[y]!=val)) valid=false; else vis[y]=true;
	node[y]=val;
	cnt++;
}

int main()
{
	valid=true;
	while(scanf("%s",masuk)!=EOF)
	{
		if(!strcmp(masuk,"()")) tulis(); else
		tambah();
	}
	return 0;
}

