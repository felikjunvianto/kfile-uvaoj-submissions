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

char vowel[]={'a','i','u','e','o'};
int N,x,lena,lenb;
char a[30],b[30];
bool oke;

bool kons(char T)
{
	for(int i=0;i<5;i++) if(T==vowel[i]) return(false);
	return(true);
}

int main()
{
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",a);lena=strlen(a);
		scanf("%s",b);lenb=strlen(b);
		
		if(lena!=lenb)
		{
			printf("No\n");
			continue;
		}
		
		oke=true;
		for(x=0;x<lena;x++) if(kons(a[x])&&kons(b[x]))
		{
			if(a[x]!=b[x]) oke=false;
		} else if(kons(a[x])||kons(b[x])) oke=false;
		if(oke) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}

