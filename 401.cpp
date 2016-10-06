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
			   //1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21
char kaca1[] = {'A','E','H','I','J','L','M','O','S','T','U','V','W','X','Y','Z','1','2','3','5','8'};
char kaca2[] = {'A','3','H','I','L','J','M','O','2','T','U','V','W','X','Y','5','1','S','E','Z','8'};
char masuk[10000];
bool palin,mirror;
int x,y,z,panjang;

int main()
{
	while(scanf("%s",&masuk)!=EOF)
	{
		panjang=strlen(masuk);
		palin=true;
		for(x=0;2*x<=panjang-1;x++) if(masuk[x]!=masuk[panjang-1-x])
		{
			palin=false;
			break;
		}
		
		if(panjang%2==0) mirror=true; else
		{
			mirror=false;
			for(x=0;x<21;x++) if((masuk[(panjang-1)/2]==kaca1[x])&&(masuk[(panjang-1)/2]==kaca2[x]))
			{
				mirror=true;
				break;
			}
		}
		
		if(mirror)
			for(x=0;2*x<=panjang-1;x++) if(!mirror) break; else
			{
				mirror=false;
				for(y=0;y<21;y++) if((masuk[x]==kaca1[y])&&(masuk[panjang-1-x]==kaca2[y]))
				{
					mirror=true;
					break;
				}
			}
				
		printf("%s -- ",masuk);
		if((palin)&&(mirror)) printf("is a mirrored palindrome.\n"); else
			if(palin) printf("is a regular palindrome.\n"); else
				if(mirror) printf("is a mirrored string.\n"); else
					printf("is not a palindrome.\n");
		printf("\n");
	}
	return 0;
}
