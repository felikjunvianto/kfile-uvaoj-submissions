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

bool square[100010];
int sum[100010];
int a,b,x;

int main()
{
	memset(square,false,sizeof(square));
	for(x=0;x*x<=100000;x++) square[x*x]=true;
	
	sum[0]=1;
	for(x=1;x<=100000;x++) sum[x]=sum[x-1]+(int)square[x];
	
	while(1)
	{
		scanf("%d %d",&a,&b);
		if(!a && !b) break;
		
		int ans = sum[b];
		if(a) ans-=sum[a-1];
		printf("%d\n",ans);
	}
	return 0;
}

