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
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>

using namespace std;

int bignum[5010][1010];
int digit[5010];
int x,y,z,panjang,carry;

int main()
{
	memset(bignum,0,sizeof(bignum));
	bignum[1][0]=1;
	digit[1]=0;
	x=1;
	do
	{
		x++;
		carry=0;
		for(y=0;y<=1005;y++)
		{
			bignum[x][y]=bignum[x-1][y]+bignum[x-2][y]+carry;
			carry=bignum[x][y]/10;
			bignum[x][y]%=10;
		}
		
		for(panjang=1005;panjang>=0;panjang--) if(bignum[x][panjang]>0) break;
		digit[x]=panjang;
		if(panjang+2>1000) break;
	}while(1);
	
	while(scanf("%d",&x)!=EOF)
	{
		for(y=digit[x];y>=0;y--) printf("%d",bignum[x][y]);
		printf("\n");
	}
	return 0;
}

