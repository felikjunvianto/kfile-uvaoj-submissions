/* scanf("%c", &c);
p=0;
while (c != '\n'){
  sc[p]=c;
  p++;

  scanf("%c", &c);
}
sc[p]=0;
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

char kata[150],c;
int panjang,sum,x,t,y;

int main()
{
	scanf("%d%c",&t,&c);
	for(y=1;y<=t;y++)
	{
		panjang=0;
		do
		{
			scanf("%c",&c);
			if(c=='\n') break;
			panjang++;
			kata[panjang-1]=c;
		} while(c!='\n');
	
		sum=0;
		for(x=0;x<panjang;x++)
		{
			switch(kata[x])
			{
				case('a') : case('d') : case('g') : 
				case('j') : case('m') : case('p') : 
				case('t') : case('w') : case(' ') : sum+=1;break;
				
				case('b') : case('e') : case('h') :
				case('k') : case('n') : case('q') :
				case('u') : case('x') :				sum+=2;break;
				
				case('s') : case('z') :				sum+=4;break;
				
				default : 							sum+=3;break;
			}
		}
		printf("Case #%d: %d\n",y,sum);
	}
	return 0;
}
