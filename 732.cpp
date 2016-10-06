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

char awal[100],akhir[100],seq[200];
int idx[30];
int L,x;
bool anagram;

void find(int i,int o)
{
	if(i+o==2*L)
	{
		int len = 2*L;
		for(int c=0;c<len;c++) printf("%c%c",seq[c],c+1==len?'\n':' ');
		return;
	}
	
	int n = i+o;
	if(i<L)
	{
		seq[n]='i';
		find(i+1,o);
	}
	
	if(i>o)
	{
		stack<char> s;
		seq[n]='o';
		
		int a=0,b=0;
		char check;
		bool oke = true;
		
		for(int c=0;c<=n && oke;c++) if(seq[c]=='i') s.push(awal[a++]); else
		{
			check = s.top(); s.pop();
			if(check!=akhir[b++]) oke=false; 
		}
		
		if(oke) find(i,o+1);
	}
}

int main()
{
	while(scanf("%s",awal)!=EOF)
	{
		memset(idx,0,sizeof(idx));
		L=strlen(awal);
		for(x=0;x<L;x++) idx[awal[x]-'a']++;
		
		scanf("%s",akhir);L=strlen(akhir);
		for(x=0;x<L;x++) idx[akhir[x]-'a']--;
		
		anagram=true;
		for(x=0;x<26 && anagram;x++) if(idx[x]!=0) anagram=false;
		
		printf("[\n");
		if(anagram) find(0,0);
		printf("]\n");
	}
	return 0;
}

