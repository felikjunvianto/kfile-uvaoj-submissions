#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct angka {int bil,jum;};

int x,y,z,n,masuk,kali,spasi,temp,batas;
angka prime[30];
bool bilangan[101];

int main()
{
	memset(bilangan,true,sizeof(bilangan));
	bilangan[1] = false;
	n=-1;
	for(x=1;x<=100;x++) if(bilangan[x])
	{
		n++;
		prime[n].bil = x;
		z=2;
		while(x*z<=100) 
		{
			bilangan[x*z] = false;
			z++;
		}
	}
	
	do
	{
		scanf("%d",&masuk);
		if(masuk==0) break;
		
		for(x=0;x<=n;x++) prime[x].jum = 0;
		kali=1;
		for(y=2;y<=masuk;y++)
		{
			kali *= y;
			for(x=0;x<=n;x++) if(kali%prime[x].bil==0)
				while(kali%prime[x].bil==0)
				{
					prime[x].jum++;
					kali /= prime[x].bil;
				}
		}
		
		spasi=0;
		temp=masuk;
		do
		{
			spasi++;
			temp /= 10;
		}while(temp>0);
		for(y=3;y>spasi;y--) printf(" ");
		printf("%d! =",masuk);
		
		batas=0;
		for(x=0;x<=n;x++) if(prime[x].jum>0)
		{
			if(batas<15) batas++; else
			{
				batas=1;
				printf("\n");
				printf("      ");	
			}
			
			spasi=0;
			temp=prime[x].jum;
			do
			{
				spasi++;
				temp /= 10;
			}while(temp>0);
			for(y=3;y>spasi;y--) printf(" ");
			printf("%d",prime[x].jum);
		}
		printf("\n");
	} while(masuk != 0);
	return 0;
}
