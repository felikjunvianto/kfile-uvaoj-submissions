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

int panjang,x;
char masuk[100];

int main()
{
	do
	{
		scanf("%s",&masuk);
		if(masuk[0]=='#') break;
		panjang=strlen(masuk);
		if(!next_permutation(masuk,masuk+panjang)) printf("No Successor\n");else 
		{
			for(x=0;x<panjang;x++) printf("%c",masuk[x]);
			printf("\n");
		}
	}while(masuk[0]!='#');
	return 0;
}
