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

int T,N,bawah,samping,z,tmp;
int x[50010],y[50010];

bool cf(int i,int j)
{
	return(i<j);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&bawah,&samping,&N);
		for(z=1;z<=N;z++) scanf("%d %d",&x[z],&y[z]);
		sort(x+1,x+N+1,cf);
		sort(y+1,y+N+1,cf);
		
		tmp=(N+1)/2;
		printf("(Street: %d, Avenue: %d)\n",x[tmp],y[tmp]);
	}
	return 0;
}

