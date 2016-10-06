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
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>

using namespace std;

char masuk[300];
int x,asci,panjang;

int main()
{
	while(gets(masuk))
	{
		panjang=strlen(masuk);
		if((masuk[0]>='0')&&(masuk[0]<='9'))
		{
			x=panjang;
			do
			{
				x--;
				asci=masuk[x]-'0';
				while(asci<32)
				{
					x--;
					asci=asci*10+(masuk[x]-'0');
				}
				printf("%c",asci);
			}while(x>0);
		}
			
		else for(x=panjang-1;x>=0;x--)
		{
			asci = (int) masuk[x];
			printf("%d%d",asci%10,(asci%100)/10);
			if(asci>=100) printf("1");
		}
		printf("\n");
	}
	return 0;
}

