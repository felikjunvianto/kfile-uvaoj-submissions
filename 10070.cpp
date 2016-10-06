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

char year[10000];
int len;
bool leap,hulu,bulu,awal;

int mod(int N)
{
	int temp = 0;
	for(int i = 0 ;i < len;i++)
		temp=(temp*10 + (year[i]-'0'))%N;
	return temp;
}

int main()
{
	awal=true;
	while(scanf("%s",year)!=EOF)
	{
		len=strlen(year);
		leap=hulu=bulu=false;
		
		if(mod(100)==0)
		{
			if(mod(400)==0) leap = true;
		} else if(mod(4)==0) leap = true;
		
		if(mod(15)==0) hulu = true;
		if((leap) && (mod(55)==0)) bulu = true;
		
		if(!awal) printf("\n");
		awal=false;
		
		if(leap || hulu || bulu)
		{
			if(leap) printf("This is leap year.\n");
			if(hulu) printf("This is huluculu festival year.\n");
			if(bulu) printf("This is bulukulu festival year.\n");
		} else printf("This is an ordinary year.\n");
	}
	return 0;
}

