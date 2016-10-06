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

pair<LL,LL> gas[40010];
LL L,x,r,last;
int G,i,j,cnt;
bool connect;

int main()
{
	while(1)
	{
		scanf("%lld %d",&L,&G);
		if(!L && !G) break;
		
		for(i=0;i<G;i++)
		{
			scanf("%lld %lld",&x,&r);
			gas[i] = mp(x-r,x+r);
		} sort(gas,gas+G);
		
		cnt=0;
		last=0LL;
		i=0;
		connect = true;
		while(i<G && connect)
		{
			if(gas[i].fi>last) connect = false; else
			{
				j = i++;
				while(i<G && gas[i].fi<=last) 
				{
					if(gas[i].se > gas[j].se) j = i;
					i++;
				}
				cnt++;
				last = gas[j].se;
			}
			if(last >= L) break;
		}
		
		if(last < L) connect = false;
		
		printf("%d\n",connect?G-cnt:-1);
	}
	return 0;
}

