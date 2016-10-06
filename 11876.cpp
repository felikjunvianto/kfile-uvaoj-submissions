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

int T,A,B,x,y,now;
vector<int> N;

int main()
{
	N.pb(1);
	while(N.back()<1000000)
	{
		now = x = N.back();
		for(y=1;y*y<=now;y++) if(now%y==0)
		{
			x++;
			if(y*y!=now) x++;
		}
		N.pb(x);
	}
	
	scanf("%d",&T);
	for(int i = 1;i<=T;i++)
	{
		scanf("%d %d",&A,&B);
		x = lower_bound(N.begin(),N.end(),A)-N.begin();
		y = upper_bound(N.begin(),N.end(),B)-N.begin() - 1;
		
		printf("Case %d: %d\n",i,y-x+1);
	}
	return 0;
}

