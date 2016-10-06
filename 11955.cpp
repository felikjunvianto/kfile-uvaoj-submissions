#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define INF 1000000000
#define eps 1e-9
#define pi 2*acos(0.0)
#define PII pair<int,int> 

using namespace std;

LL C[60][60];
int T,i,x,y,z,k,len;
string a,b;
char msk[111];

int main()
{
	C[0][0]=1LL;
	for(x=1;x<=50;x++)
	{
		C[x][0] = C[x][x] = 1LL;
		for(y=1;y<x;y++) C[x][y]=C[x-1][y-1]+C[x-1][y];
	}
	
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%s",msk);len=strlen(msk);
		for(x=1;x<len;x++) if(msk[x]=='+') break;
		a.clear();
		for(y=1;y<x;y++) a+=msk[y];
		
		for(z=x+1;z<len;z++) if(msk[z]==')') break;
		b.clear();
		for(y=x+1;y<z;y++) b+=msk[y];
		
		k=0;
		for(y=z+2;y<len;y++) k=k*10+(msk[y]-'0');
		printf("Case %d: ",i);
		
		for(x=0;x<=k;x++)
		{
			LL koef = C[k][x];
			if(koef!=1LL) printf("%lld*",koef);
			
			if(k-x!=0) printf("%s",a.c_str());
			if(k-x>1) printf("^%d",k-x);
			
			if(x!=0 && k-x!=0) printf("*");
			
			if(x!=0) printf("%s",b.c_str());
			if(x>1) printf("^%d",x);
			
			printf("%c",x==k?'\n':'+');
		} 
	}
	return 0;
}

