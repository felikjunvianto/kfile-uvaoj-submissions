#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int  jum[] = {1,5,10,50,100,500,1000};
char sim[] = {'I','V','X','L','C','D','M'};
int x,y,z,panjang,sum;
char masuk[100];
string jawab;

int main()
{
	while(scanf("%s",masuk) != EOF)
	{
		panjang=strlen(masuk);
		if((masuk[0]>='0')&&(masuk[0]<='9')) //angka ke romawi
		{
			sum=0;
			for(x=0;x<panjang;x++) sum = sum*10+(masuk[x]-'0');
			
			jawab="";
			for(x=6;x>=0;x--)
			{
				z=sum/jum[x];
				if(z>0)
				{
					if(z<4) for(y=1;y<=z;y++) jawab += sim[x]; else
					jawab = jawab + sim[x] + sim[x+1];
					sum %= jum[x];
				}	
					
				z=sum/jum[x];
				if((z==0)&&(x>=2)&&((sum/(jum[x]-jum[x-2]))==1)&&(x%2==0))
				{
					jawab = jawab + sim[x-2] + sim[x]; 
					sum = sum - (jum[x]-jum[x-2]);
				}
			}
			cout << jawab << endl;
		}
		
		else //romawi ke angka
		{
			sum=0;
			for(x=0;x<panjang;x++)
			{
				for(y=0;y<7;y++) if(sim[y]==masuk[x]) break;
				if(x<panjang-1) for(z=0;z<7;z++) if (sim[z]==masuk[x+1]) break;
				if((x==panjang-1)||(z<=y)) sum += jum[y]; else sum -= jum[y];
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}
