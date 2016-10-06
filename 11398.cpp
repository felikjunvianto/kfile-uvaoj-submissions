#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char masuk[50],biner[50],simbol;
int x,y,z,sum,panjang,digit,dua;

int main()
{
	digit=0;
	sum=0;
	do
	{
		scanf("%s",&masuk);
		if(masuk[0]=='~') break;
		
		if(masuk[0]=='#')
		{
			printf("%d\n",sum);
			sum=0;
			digit=0;
		} else
		
		{
			panjang=strlen(masuk);
			switch(panjang)
			{
				case(1) : simbol='1';break;
				case(2) : simbol='0';break;
				default	: for(x=digit;x<digit+panjang-2;x++) sum*=2;
						  if(simbol=='1') for(x=0;x<panjang-2;x++)
						  {
							dua=1;
							for(y=panjang-3;y>x;y--) dua *=2;
							sum+=2;
						  }
						  digit+=panjang-2;
						  break;
			}
		}
	} while(masuk[0] != '~');
	return 0;
}
