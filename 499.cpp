#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char kata[2000];
int sum[60];
int panjang,n,x,y,z,maks;

int main()
{
	while(gets(kata))
	{
		panjang=strlen(kata);
		memset(sum,0,sizeof(sum));
		maks=0;
		for(x=0;x<panjang;x++) 
			if((((int)kata[x]>=65)&&((int)kata[x]<=90))||(((int)kata[x]>=97)&&((int)kata[x]<=122)))
			{
				sum[(int)(kata[x])-65]++;
				if(maks<sum[(int)(kata[x])-65]) maks = sum[(int)(kata[x])-65];
			}
			
		for(x=0;x<60;x++) if(((x+65>=65)&&(x+65<=90))||((x+65>=97)&&(x+65<=122)))
			if(sum[x]==maks) printf("%c",(char)x+65);
		printf(" %d\n",maks);
	}
	return 0;
}

