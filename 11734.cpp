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

int N,x,y,z,lena,lenm,lenb;
char asli[30],masuk[30],bersih[30];

int main()
{
	scanf("%d",&N);getchar();
	for(y=1;y<=N;y++)
	{
		gets(masuk);lenm=strlen(masuk);
		gets(asli);lena=strlen(asli);
		lenb=0;
		for(x=0;x<lenm;x++) if(masuk[x]!=' ') bersih[lenb++]=masuk[x];
		
		printf("Case %d: ",y);
		if(lena!=lenb) 
		{
			printf("Wrong Answer\n");
			continue;
		}
		bool sama=true;
		for(x=0;x<lena;x++) if(asli[x]!=bersih[x]) 
		{
			sama=false;
			break;
		}
		
		if(!sama) printf("Wrong Answer\n"); else
		{
			if(lenb!=lenm) printf("Output Format Error\n");
				else printf("Yes\n");
		}
	}
	return 0;
}

