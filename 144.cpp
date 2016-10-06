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

int N,K;
int x,store;
queue<PII> q;

int main()
{
	while(1)
	{
		scanf("%d %d",&N,&K);
		if(!N && !K) break;
		
		for(x=1;x<=N;x++) q.push(mp(x,0));
		x=1,store=0;
		while(!q.empty())
		{
			PII now = q.front();q.pop();
			if(!store) 
			{
				store=x;
				if(x==K) x=1; else x++;
			}
			
			int taken=min(store,40-now.se);
			store-=taken;
			now.se+=taken;
			
			if(now.se==40) printf("%3d",now.fi);
				else q.push(mp(now.fi,now.se+store));
		}
		printf("\n");
	}
	return 0;
}

