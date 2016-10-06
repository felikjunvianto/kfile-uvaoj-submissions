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

pair<int,pair<int,string> > dna[110];
char masuk[60];
int beda,x,y,z,t,m,n;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(x=0;x<m;x++)
		{
			scanf("%s",masuk);
			beda=0;
			for(y=0;y<n-1;y++)
				for(z=y+1;z<n;z++) if(masuk[y]>masuk[z]) beda++;
			dna[x]=mp(beda,mp(x,masuk));
		}
		
		sort(dna,dna+m);
		for(x=0;x<m;x++) printf("%s\n",dna[x].se.se.c_str());
		if(t>0) printf("\n");
	}
	return 0;
}

