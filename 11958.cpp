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

const int aday = 1440;

int T,bus,i,hh,mm,now,best,waktu;

int main()
{
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d:%d",&bus,&hh,&mm);
		now = hh*60+mm;
		
		best = INF;
		while(bus--)
		{
			scanf("%d:%d %d",&hh,&mm,&waktu);
			int temp = hh*60+mm - now;
			if(temp < 0) temp += aday;
			temp += waktu;
			best = min(best, temp);
		}
		
		printf("Case %d: %d\n",i,best);
	}
	return 0;
}

