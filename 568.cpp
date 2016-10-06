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

int bil[10100];
int x,y,z,temp,dua,lima,hitung;

int main()
{
	memset(bil,0,sizeof(bil));
	for(x=1;x<=10000;x++)
	{
		bil[x]=bil[x-1];
		temp=x;
		while((temp>0)&&(temp%5==0)) 
		{
			temp/=5;
			bil[x]++;
		}
	}
	
	while(scanf("%d",&hitung)!=EOF)
	{
		dua=lima=bil[hitung];
		int z=1;
		for(x=0;x<=hitung;x++)
		{
			temp=x;
			while((temp>0)&&(temp%2==0)&&(dua>0)) 
			{
				dua--;
				temp/=2;
			}
			
			while((temp>0)&&(temp%5==0)&&(lima>0)) 
			{
				lima--;
				temp/=5;
			}
			if(temp>0) z=(z*temp)%10;
		}
		printf("%5d -> %d\n",hitung,z);
	}
	return 0;
}

