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

int N,x,now;
int temp,ans;

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		ans=temp=0;
		for(x=0;x<N;x++)
		{
			scanf("%d",&now);
			temp+=now;
			ans=max(ans,temp);
			if(temp<0) temp=0;
		}
		
		if(!ans) printf("Losing streak.\n");
			else printf("The maximum winning streak is %d.\n",ans);
	}
	return 0;
}

