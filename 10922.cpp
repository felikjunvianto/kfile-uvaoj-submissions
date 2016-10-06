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

char msk[1010];
int x,y,z,num,temp,cnt;
bool oke;

int main()
{
	while(1)
	{
		scanf("%s",msk);
		if(msk[0]=='0') break;
		
		printf("%s",msk);
		z=strlen(msk);
		oke=true;
		cnt=0;
		do
		{
			cnt++;
			num=0;
			for(x=0;x<z;x++) num+=msk[x]-'0';
			if(num%9) oke=false;
			
			z=0;
			temp=num;
			while(temp)
			{
				msk[z++]=temp%10+'0';
				temp/=10;
			}
		}while((oke)&&(num!=9));
		
		if(!oke) printf(" is not a multiple of 9.\n"); else
			printf(" is a multiple of 9 and has 9-degree %d.\n",cnt);
	}
	return 0;
}

