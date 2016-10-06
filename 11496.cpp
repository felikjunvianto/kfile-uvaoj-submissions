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

int N,ans,x;
int arr[10010];

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		for(x=0;x<N;x++) scanf("%d",&arr[x]);
		ans=0;
		for(x=0;x<N;x++)
		{
			int prev = arr[(x-1+N)%N];
			int next = arr[(x+1)%N];
			
			if((prev<arr[x] && next<arr[x])||(prev>arr[x] && next>arr[x])) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

