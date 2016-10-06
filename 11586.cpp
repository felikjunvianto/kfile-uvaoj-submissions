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

int T,x,len;
int FF,MM,FM,MF;
char msk[1000];
bool loop;

int main()
{
	scanf("%d",&T);getchar();
	while(T--)
	{
		FF=MM=FM=MF=0;
		gets(msk);len=strlen(msk);
		x=-1;
		do
		{
			x++;
			if(msk[x]==' ') continue;
			
			if((msk[x]=='M')&&(msk[x+1]=='F')) MF++; else
			if((msk[x]=='M')&&(msk[x+1]=='M')) MM++; else
			if((msk[x]=='F')&&(msk[x+1]=='M')) FM++; else FF++;
			
			x++;
		}while(x+1<len);	
		
		loop = false;
		if(FF+MM+MF+FM>1)
		{
			if((FF>0)&&(MM>0)) loop=(FF==MM); else
			if((!FF)&&(!MM)) loop=((MF>0)^(FM>0));
		}
		
		if(!loop) printf("NO ");
		printf("LOOP\n");
	}
	return 0;
}

