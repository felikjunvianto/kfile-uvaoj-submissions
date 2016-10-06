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

int N,x,y,num[1000100],temp[1000100];
LL ans;

void merge(int la,int ra,int lb,int rb)
{
	int s=la,i=la;
	while((la<=ra)&&(lb<=rb))
	{
		if(num[la]<num[lb])
		{
			ans+=(LL)abs(la-i);
			temp[i++]=num[la++];
		} else
		{
			ans+=(LL)abs(lb-i);
			temp[i++]=num[lb++];
		}
	}
	
	while(la<=ra)
	{
		ans+=(LL)abs(la-i);
		temp[i++]=num[la++];
	}
	
	while(lb<=rb)
	{
		ans+=(LL)abs(lb-i);
		temp[i++]=num[lb++];
	}
	
	for(i=s;i<=rb;i++) num[i]=temp[i];
}

void sort(int l,int r)
{
	if(l==r) return;
	sort(l,(l+r)/2);
	sort((l+r)/2+1,r);
	merge(l,(l+r)/2,(l+r)/2+1,r);
}

int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		for(x=1;x<=N;x++) scanf("%d",&num[x]);
		ans=0LL;
		sort(1,N);
		printf("%lld\n",ans/2LL);
	}
	return 0;
}

