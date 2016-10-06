// Linked List version of this solution = http://ideone.com/iKXtT (WA)

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

int group[1000010];
queue<int> bigq, teamq[1010];
int T,i,N,x,y;
char comm[30];

int main()
{
	i = 0;

	while(1)
	{
		scanf("%d",&T);
		if(!T) break;
		
		for(x=0;x<T;x++)
		{
			scanf("%d",&N);
			while(N--)
			{
				scanf("%d",&y);
				group[y]=x;
			}
			while(!teamq[x].empty()) teamq[x].pop();
		}
		
		while(!bigq.empty()) bigq.pop();
		
		printf("Scenario #%d\n",++i);
		while(1)
		{
			scanf("%s",comm);
			if(comm[0]=='S') break; else
			if(comm[0]=='E') 
			{
				scanf("%d",&x);
				if(teamq[group[x]].empty()) bigq.push(group[x]);
				teamq[group[x]].push(x);
			} else
			
			if(comm[0]=='D')
			{
				x = bigq.front();
				printf("%d\n",teamq[x].front());
				teamq[x].pop();
				if(teamq[x].empty()) bigq.pop();
			}
		}
		printf("\n");
	}
	
	return 0;
}

