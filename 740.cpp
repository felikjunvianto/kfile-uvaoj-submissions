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
#define LL long long
#define INF 1000000000

using namespace std;

char kecil[40],besar[40];
char masuk[100];
bool shifted;

int main()
{
	gets(kecil);
	gets(besar);
	while(gets(masuk))
	{
		int panjang=strlen(masuk);
		shifted=false;
		
		int y=0,code=0;
		for(int x=0;x<panjang;x++)
		{
			code=(code*2)+(masuk[x]-'0');
			y++;
			if(y==5)
			{
				if(code==27) shifted=false; else
					if(code==31) shifted=true; else
						if(shifted) printf("%c",besar[code]); else
							printf("%c",kecil[code]);
				y=code=0;
			}
		}
		printf("\n");
	}
	return 0;
}

