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
#define pi acos(-1.0)
#define eps 1e-9

using namespace std;

int t;
long long urutan,bilangan,x,y,indeks,panjang;
char masuk[30];
bool used[30];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",masuk);
		panjang=strlen(masuk);
		sort(masuk,masuk+panjang);
		memset(used,false,sizeof(used));
		scanf("%lld",&urutan);
		bilangan=1LL;
		for(x=2;x<=panjang;x++) bilangan*=x;
		
		for(x=panjang;x>=1;x--)
		{
			bilangan/=x;
			indeks=(urutan/bilangan)%x+1;
			for(y=0;y<panjang;y++)
			{
				if(!used[y]) indeks--;
				if(indeks==0) break;
			}
			used[y]=true;
			printf("%c",masuk[y]);
		}
		printf("\n");
	}
	return 0;
}

