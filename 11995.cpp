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

stack<int> s;
queue<int> q;
priority_queue<int> pq;

int N,code,val,x;
int popped[5];
bool isTrue[5];

int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		while(!s.empty()) s.pop();
		while(!q.empty()) q.pop();
		while(!pq.empty()) pq.pop();
		
		memset(isTrue,true,sizeof(isTrue));
		while(N--)
		{
			scanf("%d %d",&code, &val);
			if(code==1)
			{
				s.push(val);
				q.push(val);
				pq.push(val);
			} else
			
			if(code==2)
			{
				if(s.empty()) isTrue[0]=false; else {popped[0] = s.top();s.pop();}
				if(q.empty()) isTrue[1]=false; else {popped[1] = q.front();q.pop();}
				if(pq.empty()) isTrue[2]=false; else {popped[2] = pq.top();pq.pop();}
				
				for(x=0;x<3;x++) if(popped[x]!=val) isTrue[x]=false;
			}	
		}
		
		int howMany = 0;
		for(x=0;x<3;x++) if(isTrue[x]) howMany++;
		
		if(!howMany) printf("impossible\n"); else
			if(howMany>1) printf("not sure\n"); else
				if(isTrue[0]) printf("stack\n"); else
					if(isTrue[1]) printf("queue\n"); else
						if(isTrue[2]) printf("priority queue\n");
	}
	return 0;
}

