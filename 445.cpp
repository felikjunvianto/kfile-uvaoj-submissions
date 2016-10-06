#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

char masuk[500];
int panjang,x,y,sum;

int main()
{
	while(gets(masuk))
	{
		panjang=strlen(masuk);
		if(panjang>0) 
		{
			sum=0;
			for(x=0;x<panjang;x++) switch(masuk[x])
			{
				case('b'): for(y=0;y<sum;y++) printf(" ");
						   sum=0;
						   break;
				case('!'): printf("\n");break;
				case('0'): 
				case('1'): 
				case('2'): 
				case('3'):
				case('4'):
				case('5'):
				case('6'):
				case('7'):
				case('8'):
				case('9'): sum+=masuk[x]-'0';break;
				default : for(y=0;y<sum;y++) printf("%c",masuk[x]);
						  sum=0;
						  break;
			}
			printf("\n");
		} else printf("\n");
	}
	return 0;
}
