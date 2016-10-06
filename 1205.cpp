// Algoritma: it works, I don't know why

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
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>
#define LL long long
#define INF 1000000000

using namespace std;

int N, R, i, j, k;
int v[1010];
PII r[1010];
vector<int> child[1010], family[1010];

PII calcRatio(vector<int> &T)
{
	int sum = 0;
	for(int x = 0; x < T.size(); x++) sum += v[T[x]];
	return mp(sum, T.size());
}

int compare(PII &a, PII &b)
{
	int left = a.fi * b.se;
	int right = b.fi * a.se;
	
	if(left < right) return -1;
	if(left == right) return 0;
	return 1;
}

PII findRatio(int &now)
{
	if(r[now] != mp(-1, -1)) return r[now];
	
	vector<int> T; T.pb(now);
	PII k = calcRatio(T);
	
	while(1)
	{
		PII M = mp(0, 1);
		int y;
		bool inT[1010]; 
		memset(inT, false, sizeof(inT));
		for(int a = 0; a < T.size(); a++) inT[T[a]] = true;
		
		for(int a = 0; a < T.size(); a++)
			for(int b = 0; b < child[T[a]].size(); b++)
			{
				int next = child[T[a]][b];
				PII ratNext = findRatio(next);
				if(!inT[next] && compare(M, ratNext) < 0)
				{
					y = next;
					M = ratNext;
				}
			}
			
		if(compare(M, k) <= 0)
		{
			family[now] = T;
			r[now] = calcRatio(family[now]);
			break;
		} else
		{
			for(int a = 0; a < family[y].size(); a++) T.pb(family[y][a]);
			k = calcRatio(T);
		}
	}
	
	return r[now];
}

int findTotal()
{
	set<int> inR;
	int ret = 0, tt = 0;
	
	inR.insert(R);
	for(int k = 0; k < N; k++)
	{
		int next = -1;
		for(set<int>::iterator it = inR.begin(); it != inR.end(); it++)
		{
			int currentR = (*it);
			if(next == -1 || compare(r[next], r[currentR]) < 0) next = currentR;
		}
		
		inR.erase(next);
		for(int i = 0; i < child[next].size(); i++) inR.insert(child[next][i]);
		ret += (++tt) * v[next];
	}
	
	return ret;
}

int main()
{
	while(scanf("%d %d", &N, &R), N && R)
	{
		for(i = 1; i <= N; i++) 
		{
			child[i].clear();
			family[i].clear();
			r[i] = mp(-1, -1);
		}
		
		for(i = 1; i <= N; i++) scanf("%d", &v[i]);
		for(i = 1; i < N; i++)
		{
			scanf("%d %d", &j, &k);
			child[j].pb(k);
		}
		
		findRatio(R);
		printf("%d\n", findTotal());
	}
	return 0;
}

