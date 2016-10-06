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
#define INF 1e+150

using namespace std;

double jarak,dp[1010][1010],pohon[2020];
int N,x,lebar,panjang;
bool visited[1010][1010];

double solve(int kiri,int kanan)
{
	if(kiri+kanan==N) return(0);
	if(visited[kiri][kanan]) return(dp[kiri][kanan]);
	
	int now=kiri+kanan;
	double &ret = dp[kiri][kanan]=INF;
	visited[kiri][kanan]=true;
	if(2*kiri<N) 
	{
		double cost=fabs(jarak*(double)kiri-pohon[now]);
		ret=min(ret,cost+solve(kiri+1,kanan));
	}
	
	if(2*kanan<N) 
	{
		double dx=jarak*(double)kanan-pohon[now],dy=(double)lebar;
		double cost=sqrt(dx*dx+dy*dy);
		ret=min(ret,cost+solve(kiri,kanan+1));
	}
	return(ret);
}

int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		scanf("%d %d",&panjang,&lebar);
		jarak=panjang*2/(double)(N-2);
		for(x=0;x<N;x++) scanf("%lf",&pohon[x]);
		sort(pohon,pohon+N);
		
		memset(visited,false,sizeof(visited));
		printf("%.10lf\n",solve(0,0));
	}
	return 0;
}

