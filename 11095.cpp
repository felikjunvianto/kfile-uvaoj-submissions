#include <cstdio>
#include <cstdlib>
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
#include <set>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int> 
#define pdd pair<double,double>
#define LL long long

#define PI 2*acos(0.0)
#define EPS 1e-9
#define INF 1000000000

using namespace std;

int T, V, E;
int adjlist[40];
int best_so_far, state_now, ans;

string binary(int N)
{
	string ret = "";
	while(N > 0)
	{
		ret += char((N % 2) + '0');
		N /= 2;
	}
	
	while(ret.length() < V) ret += "0";
	return ret;
}

void backtrack(int now)
{
	if(now == V) 
	{
		// printf("%2d %s %2d\n", now, binary(state_now).c_str(), __builtin_popcount(state_now));
		best_so_far = __builtin_popcount(state_now);
		ans = state_now; 
	} 
	
	else
	{
		// printf("%2d %s\n", now, binary(state_now).c_str());
	
		// if current node is already picked by previous process OR every adjacent is picked, skip current process
		if((state_now & (1 << now)) || ((state_now & adjlist[now]) == adjlist[now])) backtrack(now + 1); else
		{
			// if we pick current node
			if(__builtin_popcount(state_now) + 1 < best_so_far)
			{
				state_now ^= (1 << now);
				backtrack(now + 1);
				state_now ^= (1 << now);
			}
			
			// if we don't pick current node, all adjacent must be picked
			if(__builtin_popcount(state_now) + __builtin_popcount(adjlist[now]) - __builtin_popcount(state_now & adjlist[now]) < best_so_far)
			{
				int temp = state_now;
				state_now |= adjlist[now];
				backtrack(now + 1);
				
				state_now = temp;
			}
		}
	}
}

int main()
{
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d", &V);
		scanf("%d", &E);
		
		for(int i = 0; i < V; i++) adjlist[i] = 0;
		while(E--)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			
			adjlist[a] |= (1 << b);
			adjlist[b] |= (1 << a);
		}
		
		best_so_far = V;
		state_now = ans = 0;
		backtrack(0);
		
		printf("Case #%d: %d\n", t, best_so_far);
		
		bool awal = true;
		for(int i = 0; i < V; i++) if(ans & (1 << i))
		{
			if(!awal) printf(" ");
			awal = false;
			printf("%d", i);
		}
		
		printf("\n");
	}
	return 0;
}
