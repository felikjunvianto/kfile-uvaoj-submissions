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

char masuk[20];
int panjang,x,y,z,bil;

int decimal()
{
	int hasil=0;
	int kunci=1;
	for(int x=panjang-1;x>=2;x--) 
	{
		if((masuk[x]>='0')&&(masuk[x]<='9')) hasil+=(masuk[x]-'0')*kunci;
			else hasil+=(masuk[x]-'A'+10)*kunci;
		kunci*=16;
	}
	return(hasil);
}

string hexa()
{
	string hasil="";
	while(bil>0)
	{
		if(bil%16<10) hasil=(char)((bil%16)+'0')+hasil;
			else hasil=(char)((bil%16)-10+'A')+hasil;
		bil/=16;
	}
	return(hasil);
}

int main()
{
	do
	{
		gets(masuk);
		if(masuk[0]=='-') break;
		
		panjang=strlen(masuk);
		if(masuk[1]=='x') printf("%d\n",decimal()); else
		{
			bil=0;
			for(x=0;x<panjang;x++) bil=bil*10+masuk[x]-'0';
			printf("0x%s\n",hexa().c_str());
		}
	}while(masuk[0]!='-');
	return 0;
}

