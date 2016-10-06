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

int bignum[1010][2601],kali[10];
int satu,dua,x,y,z,now,carry;

int main()
{
	bignum[0][0]=1;
	x=satu=0;
	do
	{
		x++;
		now=x;
		dua=-1;
		while(now>0)
		{
			dua++;
			kali[dua]=now%10;
			now/=10;
		}
		
		carry=0;
		for(z=0;z<=dua+1;z++)
			for(y=0;y<=satu+1;y++)
			{
				bignum[x][y+z]+=bignum[x-1][y]*kali[z]+carry;
				carry=bignum[x][y+z]/10;
				bignum[x][y+z]%=10;
			}
			
		for(satu=2600;satu>=0;satu--) if(bignum[x][satu]>0) break;
	}while(x<1000);
	
	while(scanf("%d",&x)!=EOF)
	{
		printf("%d!\n",x);
		for(y=2600;y>=0;y--) if(bignum[x][y]>0) break;
		for(z=y;z>=0;z--) printf("%d",bignum[x][z]);
		printf("\n");
	}
	return 0;
}

