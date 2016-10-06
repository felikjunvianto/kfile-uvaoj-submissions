#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

int ukuran,x,y,z,digit;
char bil[20];

int main()
{
	do
	{
		scanf("%d %s",&ukuran,&bil);
		if((ukuran==0)&&(bil[0]=='0')) break;

		digit=strlen(bil);
		for(x=0;x<digit;x++) //teratas
		{
			switch(bil[x])
			{
				case('1') : case('4') : for(y=0;y<ukuran+2;y++) printf(" ");break;
				default   : for(y=0;y<ukuran+2;y++) if((y==0)||(y==ukuran+1)) printf(" "); 
							  else printf("-");break;
			}
			if(x<digit-1) printf(" ");
		}
		printf("\n");
		
		for(z=0;z<ukuran;z++) //kedua
		{
			for(x=0;x<digit;x++) 
			{
				switch(bil[x])
				{
					case('1') : case('2') : 
					case('3') : case('7') : for(y=0;y<ukuran+1;y++) printf(" ");
											printf("|");break;
											
					case('5') : case('6') : printf("|");
											for(y=0;y<ukuran+1;y++) printf(" ");
											break;
					
					default   : for(y=0;y<ukuran+2;y++) if((y==0)||(y==ukuran+1)) printf("|"); 
								else printf(" ");break;
				}
				if(x<digit-1) printf(" ");
			}
			printf("\n");
		}
		
		for(x=0;x<digit;x++) //ketiga
		{
			switch(bil[x])
			{
				case('1') : case('7') : case('0'): for(y=0;y<ukuran+2;y++) printf(" ");break;
				default   : for(y=0;y<ukuran+2;y++) if((y==0)||(y==ukuran+1)) printf(" "); 
							  else printf("-");break;
			}
			if(x<digit-1) printf(" ");
		}
		printf("\n");
		
		for(z=0;z<ukuran;z++) //keempat
		{
			for(x=0;x<digit;x++) 
			{
				switch(bil[x])
				{
					case('2') : printf("|");
								for(y=0;y<ukuran+1;y++) printf(" ");
								break;			
					
					case('6') : case('8') : case('0') :	for(y=0;y<ukuran+2;y++) if((y==0)||(y==ukuran+1)) printf("|"); 
														else printf(" ");break;
														
					default   : for(y=0;y<ukuran+1;y++) printf(" ");
								printf("|"); break;
				}
				if(x<digit-1) printf(" ");
			}
			printf("\n");
		}
		
		for(x=0;x<digit;x++) //terakhir
		{
			switch(bil[x])
			{
				case('1') : case('4') : case('7') : for(y=0;y<ukuran+2;y++) printf(" ");break;
				default   : for(y=0;y<ukuran+2;y++) if((y==0)||(y==ukuran+1)) printf(" "); 
							  else printf("-");break;
			}
			if(x<digit-1) printf(" ");
		}
		printf("\n");
		printf("\n");
	} while((ukuran!=0)&&(bil!=0));
	return 0;
}
