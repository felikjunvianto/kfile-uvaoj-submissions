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

using namespace std;

int T,N,x,y,panjang;
bool oke;
char masuk[15];
vector<string> nomor;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		nomor.clear();
		scanf("%d",&N);
		while(N--)
		{
			scanf("%s",masuk);
			nomor.pb(masuk);
		}
		sort(nomor.begin(),nomor.end());
		oke=true;
		
		for(x=1;x<nomor.size();x++)
		{
			panjang=min(nomor[x-1].size(),nomor[x].size());
			bool sama=true;
			for(y=0;(y<panjang)&&sama;y++) if(nomor[x][y]!=nomor[x-1][y]) sama=false;
			if(sama)
			{
				oke=false;
				break;
			}
		}
		if(oke) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}

