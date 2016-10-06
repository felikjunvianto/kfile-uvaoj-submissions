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

using namespace std;

map<string,int> indeks;
string coba;
char komb[10];
bool used[30]={0};
int x,y,z;

void gen(int t)
{
	int y;
	if(t==x+1)
	{
		z++;
		coba="";
		for(y=1;y<t;y++) coba+=komb[y];
		indeks[coba]=z;
	} else 
		for(y=0;y<26;y++) if((!used[y])&&(y+'a'>komb[t-1]))
		{
			used[y]=true;
			komb[t]=y+'a';
			gen(t+1);
			used[y]=false;
		}
}

int main()
{
	z=0;
	komb[0]='a'-1;
	for(x=1;x<=5;x++) gen(1);
	
	while(scanf("%s",komb)!=EOF)
	{
		bool boleh=true;
		int panjang=strlen(komb);
		for(x=1;x<panjang;x++) if(komb[x]<=komb[x-1])
		{
			boleh=false;
			break;
		}
		
		if(!boleh) printf("0\n"); else printf("%d\n",indeks[komb]);
	}
	return 0;
}

