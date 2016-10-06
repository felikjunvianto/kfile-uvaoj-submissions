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

int len,x,y,z;
char masuk[1000];
vector<int> bil,sorted,langkah;

void balik(int n)
{
	for(int i=0;2*i<n;i++) swap(bil[i],bil[n-i]);
	langkah.pb((int)bil.size()-n);
}

int main()
{
	while(gets(masuk))
	{
		bil.clear();
		sorted.clear();
		langkah.clear();
		len=strlen(masuk);
		x=-1;
		do
		{
			x++;
			if(masuk[x]==' ') continue;
			
			z=0;
			while((masuk[x]!=' ')&&(x<len))
			{
				z=z*10+masuk[x]-'0';
				x++;
			}
			bil.pb(z);
		}while(x+1<len);
		sorted=bil;
		sort(sorted.begin(),sorted.end());
		
		for(x=0;x<bil.size();x++)
		{
			printf("%d",bil[x]);
			if(x+1<bil.size()) printf(" "); else printf("\n");
		}
		
		for(x=sorted.size()-1;x>=0;x--)
		{
			for(y=0;y<bil.size();y++) if(bil[y]==sorted[x]) break;
			if(y!=x)
			{
				if(y!=0) balik(y);
				balik(x);
			}
		} langkah.pb(0);
		for(x=0;x<langkah.size();x++)
		{
			printf("%d",langkah[x]);
			if(langkah[x]!=0) printf(" "); else printf("\n");
		}
	}
	return 0;
}

