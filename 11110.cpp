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

int peta[110][110];
vector<int> bil;
char masuk[2000],c;
int n,x,y,z,a,b,banyak,panjang;
bool benar;

void ff(int x,int y)
{
	peta[x][y]=0;
	banyak++;
	for(int ver=-1;ver<=1;ver++)
		for(int hor=-1;hor<=1;hor++)
			if((ver==0)^(hor==0))
				if((x+hor>=0)&&(x+hor<n)&&(y+ver>=0)&&(y+ver<n))
					if(peta[x+hor][y+ver]==z) ff(x+hor,y+ver);
}

int main()
{
	do
	{
		scanf("%d\n",&n);
		if(n==0) break;
		
		for(y=0;y<n;y++) 
			for(x=0;x<n;x++) peta[x][y]=n;
		
		benar=true;
		for(x=1;x<n;x++)
		{
			gets(masuk);
			panjang=strlen(masuk);
			if(panjang==0) benar=false;
			bil.clear();
			a=-1;
			do
			{
				a++;
				while((masuk[a]==' ')&&(a<panjang)) a++;
				if(a==panjang) break;
				b=a;
				while((masuk[b]!=' ')&&(b<panjang)) b++;b--;
				bil.pb(0);
				for(y=a;y<=b;y++) bil.back()=bil.back()*10+masuk[y]-'0';
				a=b;
			}while(a<panjang-1);
			
			for(y=0;y<bil.size();y+=2) 
				if((bil[y]!=0)&&(bil[y+1]!=0)) peta[bil[y]-1][bil[y+1]-1]=x;
		}
		
		for(y=0;y<n;y++) if(!benar) break; else
			for(x=0;x<n;x++) if(peta[x][y]!=0)
			{
				banyak=0;
				z=peta[x][y];
				ff(x,y);
				if(banyak!=n) 
				{
					benar=false;
					break;
				}
			}
		
		if(benar) printf("good\n"); else printf("wrong\n");
	}while(n!=0);
	return 0;
}

