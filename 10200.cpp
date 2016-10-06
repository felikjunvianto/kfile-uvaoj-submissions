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

int byk[10010];
int a,b,x,y,n;
double ans;

bool prime(int N)
{
	for(int i=2;i*i<=N;i++) if(N%i==0) return(false);
	return(true);
}

int main()
{
	for(x=0;x<=10000;x++)
	{
		if(x) byk[x]=byk[x-1]; else byk[x]=0;
		n=x*x+x+41;
		if(prime(n)) byk[x]++;
	}
	
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		y=byk[b];
		if(a) y-=byk[a-1];
		ans=y*10000/(double)(b-a+1);
		ans=floor(ans+0.5);
		printf("%.2lf\n",ans/100.00);
	}
	return 0;
}

