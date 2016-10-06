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

int N,arr[100010],x,y,z;
LL ans;

void merge(int a1,int b1,int a2,int b2)
{
	int i=a1,awal=a1,temp[100010];
	
	while((a1<=b1)&&(a2<=b2))
	{
		if(arr[a1]<arr[a2])
		{
			ans+=(LL)abs(a1-i);
			temp[i++]=arr[a1++];
		} else
		{
			ans+=(LL)abs(a2-i);
			temp[i++]=arr[a2++];
		}
	}
	
	while(a1<=b1)
	{
		ans+=(LL)abs(a1-i);
		temp[i++]=arr[a1++];
	}
	
	while(a2<=b2)
	{
		ans+=(LL)abs(a2-i);
		temp[i++]=arr[a2++];
	}
	
	for(i=awal;i<=b2;i++) arr[i]=temp[i];
}

void sort(int kiri,int kanan)
{
	if(kiri<kanan)
	{
		sort(kiri,(kiri+kanan)/2);
		sort((kiri+kanan)/2+1,kanan);
		
		merge(kiri,(kiri+kanan)/2,(kiri+kanan)/2+1,kanan);
	}
}

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		for(x=1;x<=N;x++) scanf("%d",&arr[x]);
		ans=0LL;
		sort(1,N);
		ans/=2LL;
		if(ans&1LL) printf("Marcelo\n"); else printf("Carlos\n");
	}
	return 0;
}

