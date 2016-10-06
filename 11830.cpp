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

int flaw,x,len;
char msk[111],c;
bool zero;

int main()
{
	while(1)
	{
		scanf("%d %s",&flaw,msk);
		if(!flaw) break;
		
		c=flaw+'0';
		len=strlen(msk);
		zero=true;
		for(x=0;x<len;x++) if((msk[x]!=c)&&(msk[x]!='0'))
		{
			zero=false;
			break;
		}
		
		if(zero) printf("0\n"); else
		{
			for(x=0;x<len;x++) if(msk[x]!=c) printf("%c",msk[x]);
			printf("\n");
		}
	}
	return 0;
}

