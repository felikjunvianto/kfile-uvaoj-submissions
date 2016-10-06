#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int t,x,y,z,num1,num2,hasil;
char masuk[10];
char operant[2];

int ubah()
{
	int panjang=strlen(masuk);
	int jumlah=0;
	int x,y,empat;
	
	for(x=0;x<panjang;x++)
	{
		empat=1;
		for(y=panjang;y>x+1;y--) empat *= 4;
		switch(masuk[x])
		{
			case('V') : empat*=0; break;
			case('U') : empat*=1; break;
			case('C') : empat*=2; break;
			case('D') : empat*=3; break;
		}
		jumlah+=empat;
	}
	return jumlah;
}

int main()
{
	scanf("%d",&t);
	printf("COWCULATIONS OUTPUT\n");
	while(t--)
	{
		scanf("%s",&masuk);
		num1=ubah();
		scanf("%s",&masuk);
		num2=ubah();
		for(x=0;x<3;x++)
		{
			scanf("%s",&operant);
			switch(operant[0])
			{
				case('A') : num2+=num1;break;
				case('L') : num2*=4;break;
				case('R') : num2/=4;break;
				default   : break;
			}
		}
		scanf("%s",&masuk);
		hasil=ubah();
		if(hasil==num2) printf("YES\n"); else printf("NO\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
