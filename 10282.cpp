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

int x,y,len;
map<string,string> idx;
char msk[50];
string a,b;

int main()
{
	while(gets(msk))
	{
		len=strlen(msk);
		if(!len) break;
		
		for(x=0;x<len;x++) if(msk[x]==' ') break;
		a.clear(),b.clear();
		for(y=0;y<x;y++) a+=msk[y];
		for(y=x+1;y<len;y++) b+=msk[y];
		idx[b]=a;
	}
	
	while(scanf("%s",msk)!=EOF)
		if(idx.find(msk)==idx.end()) printf("eh\n"); else printf("%s\n",idx[msk].c_str());
	return 0;
}

