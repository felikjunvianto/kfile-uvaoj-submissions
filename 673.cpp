#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char masuk[130],stack[130];
int panjang,x,m,t;
bool oke;

int main()
{
	scanf("%d\n",&t);
	while(t--)
	{
		gets(masuk);
		panjang=strlen(masuk);
		oke=true;
		m=0;
		if(panjang>0) for(x=0;x<panjang;x++) if(oke) switch(masuk[x])
		{
			case('[') : case('(') : m++;
									stack[m]=masuk[x];
									break;
			case(']') : if((m==0)||(stack[m]!='[')) oke=false; else m--;
						break;
			case(')') : if((m==0)||(stack[m]!='(')) oke=false; else m--;
						break;
		}

		if((m==0)&&(oke)) printf("Yes\n");
			else printf("No\n");
	}
	return 0;
}
