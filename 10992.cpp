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

int pembagi[]={2,5,7,11,15,20,28,36};
string nama[]={"Tanveer Ahsan",
			   "Shahriar Manzoor",
			   "Adrian Kugel",
			   "Anton Maydell",
			   "Derek Kisman",
			   "Rezaul Alam Chowdhury",
			   "Jimmy Mardell",
			   "Monirul Hasan"};

int bignum[60],kurang[10];
char masuk[60];
int panjang,x,t;
bool ada,kabisat;

bool divisible(int t)
{
	int x,sisa=0;
	for(x=panjang-1;x>=0;x--) sisa=(sisa*10+bignum[x])%t;
	return(sisa==0);
}

int main()
{
	t=0;
	kurang[0]=8;
	kurang[1]=4;
	kurang[2]=1;
	kurang[3]=2;
	do
	{
		scanf("%s",masuk);
		if(masuk[0]=='0') break;
		
		t++;
		if(t>1) printf("\n");
		printf("%s\n",masuk);
		panjang=strlen(masuk);
		for(x=0;x<panjang;x++) bignum[x]=masuk[panjang-x-1]-'0';
		
		ada=false;
		int tahun=bignum[0]+bignum[1]*10+bignum[2]*100+bignum[3]*1000;
		if((tahun>=2148)||(panjang>4))
		{
			kabisat=false;
			if(bignum[0]+bignum[1]==0)
			{
				if((bignum[2]+bignum[3]*10)%4==0) kabisat=true;
			} else if((bignum[0]+bignum[1]*10)%4==0) kabisat=true;
			
			for(x=0;x<4;x++) if(bignum[x]<kurang[x])
			{
				bignum[x]=bignum[x]+10-kurang[x];
				bignum[x+1]--;
			} else bignum[x]-=kurang[x];
		
			for(x=4;x<panjang;x++) if(bignum[x]==-1)
			{
				bignum[x]=9;
				bignum[x+1]--;
			}	
			
			for(x=0;x<8;x++) if(divisible(pembagi[x]))
			{
				ada=true;
				printf("Ghost of %s!!!\n",nama[x].c_str());
			}	
		
			if(kabisat)
			{
				ada=true;
				printf("Ghost of K. M. Iftekhar!!!\n");
			}
		}
		if(!ada) printf("No ghost will come in this year\n");
	}while(masuk[0]!='0');
	return 0;
}

