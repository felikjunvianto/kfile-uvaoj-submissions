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

int T,N,i,x,low,high;
int arr[100];

int main()
{
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&N);
		for(x=0;x<N;x++) scanf("%d",&arr[x]);
		
		low=high=0;
		for(x=0;x+1<N;x++) if(arr[x]>arr[x+1]) low++;
			else if(arr[x]<arr[x+1]) high++;
			
		printf("Case %d: %d %d\n",i,high,low);
	}
	return 0;
}

