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

int N,x;
queue<int> q;
bool awal;

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		for(x=1;x<=N;x++) q.push(x);
		awal = true;
		printf("Discarded cards:");
		
		while(q.size()>1)
		{
			x = q.front();q.pop();
			if(!awal) printf(",");awal = false;
			printf(" %d",x);
			x = q.front();q.pop();
			q.push(x);
		}
		
		printf("\nRemaining card: %d\n",q.front()); q.pop();
	}
	return 0;
}

