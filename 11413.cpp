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

int N,C,x,y,z;
int kecil,besar;
int milk[1010];

bool cek(int T)
{
	if(T<kecil) return false;
	
	int tong=0,cnt=1;
	for(int i=0;i<N;i++)
	{
		if(milk[i]+tong>T)
		{
			tong=0;
			cnt++;
		}
		tong+=milk[i];
	}
	return(cnt<=C);
}

int solve(int l,int r)
{
	while(l<=r)
	{
		int p=(l+r)/2;
		bool now=cek(p);
		bool prev=cek(p-1);
		
		if(now && !prev) return p; else
			if(now && prev) r=p-1; else
				if(!now) l=p+1;
	} return r;
}

int main()
{
	while(scanf("%d %d",&N,&C)!=EOF)
	{
		kecil=besar=0;
		for(x=0;x<N;x++) 
		{
			scanf("%d",&milk[x]);
			kecil=max(kecil,milk[x]);
			besar=besar+milk[x];
		}
		
		printf("%d\n",solve(kecil,besar));
	}
	return 0;
}

