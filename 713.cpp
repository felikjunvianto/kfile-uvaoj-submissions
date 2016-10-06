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

int T,x,y,z,carry;
int a[250],b[250];
char ang[250];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(a,-1,sizeof(a));
		scanf("%s",ang);
		z=strlen(ang);
		for(x=0;x<z;x++) a[x]=ang[x]-'0';
		
		memset(b,-1,sizeof(b));
		scanf("%s",ang);
		z=strlen(ang);
		for(x=0;x<z;x++) b[x]=ang[x]-'0';
		
		carry=0;
		for(x=0;x<250;x++) if((a[x]==-1)&&(b[x]==-1)&&(!carry)) break; else
		{
			if(a[x]==-1) a[x]=0;
			if(b[x]==-1) b[x]=0;
			
			a[x]=a[x]+b[x]+carry;
			if(a[x]>9)
			{
				carry=a[x]/10;
				a[x]%=10;
			} else carry=0;
		}
		
		for(x=0;x<250;x++) if(a[x]>0) break;
		for(y=x;a[y]!=-1;y++) printf("%d",a[y]);
		printf("\n");
	}
	return 0;
}

