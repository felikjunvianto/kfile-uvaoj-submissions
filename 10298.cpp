#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi 2*acos(0.0)
#define eps 1e-9
#define INF 1000000000
#define LL long long
#define PII pair<int,int> 
#define PDD pair<double,double> 

using namespace std;

int ans,len,x;
char masuk[1000010],gede[2000010];
bool oke;

int main()
{
	while(1)
	{
		scanf("%s",masuk);
		if(masuk[0]=='.') break;
		
		len=strlen(masuk);
		strcpy(gede,masuk);
		strcat(gede,masuk);
		char *p=strstr(gede+1,masuk);
		printf("%d\n",len/int(p-gede));
	}
	return 0;
}

