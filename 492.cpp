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
#define pi acos(-1.0)
#define eps 1e-9

using namespace std;

string masuk;
int a,x,y,z,panjang;

char kecilin(char t)
{
	if((t>='A')&&(t<='Z')) return(t-'A'+'a');
		else return(t);
}

bool konsonan(char t)
{
	if((t=='a')||(t=='i')||(t=='u')||(t=='e')||(t=='o')) return(false);
		else return(true);
}

int main()
{
	while(getline(cin,masuk))
	{
		panjang=masuk.size();
		x=-1;
		do
		{
			x++;
			while((!((kecilin(masuk[x])>='a')&&(kecilin(masuk[x])<='z')))&&(x<panjang))
			{
				printf("%c",masuk[x]);
				x++;
			}
			if(x==panjang) break;
			
			y=x+1;
			while((kecilin(masuk[y])>='a')&&(kecilin(masuk[y])<='z')&&(y<panjang)) y++;y--;
			z=x;
			if(konsonan(kecilin(masuk[x]))) z++;
			for(a=z;a<=y;a++) printf("%c",masuk[a]);
			if(konsonan(kecilin(masuk[x]))) printf("%c",masuk[x]);
			printf("ay");
			x=y;
		}while(x+1<panjang);
		printf("\n");
	}
	return 0;
}

