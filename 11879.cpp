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

char msk[111];
int len,rem,x;

int main()
{
	while(1)
	{
		scanf("%s",msk);
		if(!strcmp(msk,"0")) break;
		
		len=strlen(msk);
		rem=0;
		for(x=0;x<len;x++) rem=(rem*10+(msk[x]-'0'))%17;
		printf("%d\n",rem?0:1);
	}
	return 0;
}

