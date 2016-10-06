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

int x,y,z,len;
char msk[10010];
string asli;

int main()
{
	while(1)
	{
		gets(msk);
		if(!strcmp(msk,"DONE")) break;
		
		asli.clear();
		len=strlen(msk);
		for(x=0;x<len;x++)
		{
			if((msk[x]>='a')&&(msk[x]<='z')) msk[x]^=32;
			if((msk[x]>='A')&&(msk[x]<='Z')) asli.pb(msk[x]);
		}
		
		bool oke=true;
		len=(int)asli.size();
		for(x=0;2*x<len;x++) if(asli[x]!=asli[len-x-1])
		{
			oke=false;
			break;
		}
		
		if(oke) printf("You won't be eaten!\n"); else printf("Uh oh..\n");
	}
	return 0;
}

