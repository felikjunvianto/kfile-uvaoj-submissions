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

using namespace std;

int angka[370][810],sekarang[101];
int digit[10];
int n,x,y,z,temp,carry;

int main()
{
	memset(angka,0,sizeof(angka));
	angka[1][1]=1;
	for(x=2;x<=366;x++)
	{
		temp=x;
		memset(sekarang,0,sizeof(sekarang));
		y=0;
		while(temp>0)
		{
			y++;
			sekarang[y]=temp%10;
			temp/=10;
		}
		
		carry=0;
		for(y=1;y<=800;y++)
			for(z=1;z<=100;z++) 
			{
				angka[x][y+z-1]=angka[x][y+z-1]+(angka[x-1][y]*sekarang[z])+carry;
				if(angka[x][y+z-1]>9)
				{
					carry=angka[x][y+z-1]/10;
					angka[x][y+z-1]%=10;
				} else carry=0;
			}
	}
	
	do
	{
		scanf("%d",&n);
		if(n==0) break;
		
		memset(digit,0,sizeof(digit));
		for(z=800;z>=1;z--) if(angka[n][z]!=0) break;
		for(y=z;y>=1;y--) digit[angka[n][y]]++;
		
		printf("%d! --\n",n);
		for(x=0;x<10;x++)
		{
			if(x%5==0) printf("   "); else printf("    ");
			printf("(%d)",x);
			printf("%5d",digit[x]);
			if((x+1)%5==0) printf("\n");
		}
		
	}while(n!=0);
	return 0;
}
