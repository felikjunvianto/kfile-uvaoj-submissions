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

int bignum[1010][2601];
int kali[5];
int satu,dua;
int x,y,z,temp,carry;

int main()
{
	bignum[0][0]=1;
	satu=0;
	for(x=1;x<=1000;x++)
	{
		dua=-1;
		temp=x;
		while(temp>0)
		{
			dua++;
			kali[dua]=temp%10;
			temp/=10;
		}
		
		carry=0;
		for(y=0;y<=satu+1;y++)
			for(z=0;z<=dua+1;z++)
			{
				bignum[x][y+z]+=bignum[x-1][y]*kali[z]+carry;
				carry=bignum[x][y+z]/10;
				bignum[x][y+z]%=10;
			}
		for(satu=2600;satu>=0;satu--) if(bignum[x][satu]>0) break;
	}
	
	while(scanf("%d",&x)!=EOF)
	{
		z=0;
		for(y=0;y<=2600;y++) z+=bignum[x][y];
		printf("%d\n",z);
	}
	return 0;
}

