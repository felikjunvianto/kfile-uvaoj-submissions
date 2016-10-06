#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000
#define PI 2*acos(0.0)
#define eps 1e-9
#define LL long long
#define PII pair<int,int> 

using namespace std;

int N,x,y,ans;

int GCD(int x,int y)
{
	if(!y) return(x);
	return(GCD(y,x%y));
}

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		ans=0;
		for(x=1;x<N;x++)
			for(y=x+1;y<=N;y++) ans+=GCD(x,y);
			
		printf("%d\n",ans);
	}
	return 0;
}

