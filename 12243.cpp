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

char sen[2010];
int x,y,z,len;
bool tau;

char up(char c)
{
	if(c>='a' && c <='z') c^=32;
	return c;
}

int main()
{
	while(1)
	{
		gets(sen);
		if(sen[0]=='*') break;
		
		len = strlen(sen);
		
		tau = true;
		for(x=1;x<len && tau;x++) if(sen[x-1]==' ')
			if(up(sen[x])!=up(sen[0])) tau = false;
			
		printf("%c\n",tau?'Y':'N');
	}
	return 0;
}

