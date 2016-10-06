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

bool used[10]={0};
int penyebut[5];
int x,y,z,n,t;
bool dapat;

void tes()
{
	int bawah=0;
	int x,pembilang[5];
	for(x=0;x<5;x++) bawah=bawah*10+penyebut[x];
	int atas=n*bawah;
	if(atas>99999) return;
	
	for(x=4;x>=0;x--) 
	{
		pembilang[x]=atas%10;
		atas/=10;
	}
	
	bool jawaban=true;
	bool dipakai[10];
	for(x=0;x<10;x++) dipakai[x]=used[x];
	for(x=0;x<5;x++) if(!dipakai[pembilang[x]]) dipakai[pembilang[x]]=true; else
	{
		jawaban=false;
		break;
	}
	
	if(jawaban)
	{
		dapat=true;
		for(x=0;x<5;x++) printf("%d",pembilang[x]);printf(" / ");
		for(x=0;x<5;x++) printf("%d",penyebut[x]);printf(" = %d\n",n);
	}
}

void cari(int t)
{
	if(t==5) tes(); else
	for(int y=0;y<10;y++) if(!used[y])
	{
		penyebut[t]=y;
		used[y]=true;
		cari(t+1);
		used[y]=false;
	}
}

int main()
{
	t=0;
	do
	{
		scanf("%d",&n);
		if(n==0) break;
	
		dapat=false;
		t++;
		if(t>1) printf("\n");
		cari(0);
		if(!dapat) printf("There are no solutions for %d.\n",n);
	}while(n!=0);
	return 0;
}

