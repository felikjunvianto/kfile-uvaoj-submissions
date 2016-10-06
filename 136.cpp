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
#define PLL pair<long long,long long> 

using namespace std;

int faktor[]={2,3,5};
priority_queue<PLL,vector<PLL>,greater<PLL> > pq;
int next,t,x;
long long now;

int main()
{
	pq.push(mp(1,0));
	t=0;
	do
	{
		now=pq.top().fi;
		next=pq.top().se;
		t++;
		pq.pop();
		for(x=next;x<3;x++) pq.push(mp(now*(long long)faktor[x],x));
	}while(t<1500);
	printf("The 1500'th ugly number is %lld.\n",now);
	return 0;
}

