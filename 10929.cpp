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

using namespace std;

char masuk[1050];
int panjang;

bool terbagi()
{
	int x,sisa=0;
	for(x=0;x<panjang;x++) sisa=(sisa*10+(masuk[x]-'0'))%11;
	return(sisa==0);
}

int main()
{
	do
	{
		scanf("%s",masuk);
		panjang=strlen(masuk);
		if((panjang==1)&&(masuk[0]=='0')) break;
		
		printf("%s is ",masuk);
		if(!terbagi()) printf("not ");
		printf("a multiple of 11.\n");
	}while((panjang!=1)||(masuk[0]!='0'));
	return 0;
}

