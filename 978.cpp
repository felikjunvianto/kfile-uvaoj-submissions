/*
   Algorithm : Gunakan priority queue agar proses pencarian prajurit terkuat dapat berjalan cepat.
               Kemudian setelah itu disimulasikan saja hingga salah satu pihak kehabisan prajurit.
*/

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

int N, Battle, Nblue, Ngreen;
int arena[100010], i, j, k;
priority_queue<int> blue, green;

int main()
{
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d %d %d",&Battle, &Ngreen, &Nblue);
		while(Ngreen--)
		{
			scanf("%d", &i);
			green.push(i);
		}
		
		while(Nblue--)
		{
			scanf("%d", &i);
			blue.push(i);
		}
		
		while(!blue.empty() && !green.empty())
		{
			memset(arena,0,sizeof(arena));
			for(i = 0; i < Battle; i++) if(blue.empty()) break; else 
			{
				arena[i] += blue.top();
				blue.pop();
			}
			
			for(i = 0; i < Battle; i++) if(green.empty()) break; else
			{
				arena[i] -= green.top();
				green.pop();
			}
			
			for(i = 0; i < Battle; i++) if(arena[i] > 0) blue.push(arena[i]);
				else if(arena[i] < 0) green.push(-arena[i]);
		}
		
		if(blue.empty() && green.empty()) printf("green and blue died\n"); else
		
		if(green.empty()) 
		{
			printf("blue wins\n");
			while(!blue.empty()) 
			{
				printf("%d\n", blue.top()); 
				blue.pop();
			}
		} else
		{
			printf("green wins\n");
			while(!green.empty())
			{
				printf("%d\n", green.top());
				green.pop();
			}
		}
		
		if(N) printf("\n");
	}
	return 0;
}

