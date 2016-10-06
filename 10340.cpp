#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

char a[5000000],b[5000000];
int panjang_a,panjang_b;
int x,y,z;

int main()
{
	while(scanf("%s %s",a,b) != EOF)
	{
		panjang_a = strlen(a);
		panjang_b = strlen(b);
		
		y=-1;
		x=0;
		do
		{
			y++;
			while((y<panjang_b-1)&&(b[y] != a[x])) y++;
			if(b[y]==a[x])
			{
				x++;
				if(x==panjang_a) break;
			}
		} while(y<panjang_b-1);
		if(x==panjang_a) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}
