/**
 Algoritma : Binary search
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define INF 1000000000
#define eps 1e-9
#define PII pair<int,int> 

using namespace std;

int arr[1111];
vector<int> unik;
int N, Q, x;

int compare(int a, int b, int c)
{
	if(abs(a - c) > abs(b - c)) return b;
	return a;
}

int main()
{
	int T = 0;
	while(1)
	{
		scanf("%d", &N);
		if(!N) break;
		
		for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
		sort(arr, arr + N);
		
		unik.clear();
		for(int i = 0; i < N; i++) if(!i || arr[i] != arr[i-1]) unik.pb(arr[i]);
		
		printf("Case %d:\n", ++T);
		scanf("%d", &Q);
		while(Q--)
		{
			scanf("%d", &x);
			int ans = INF;
			
			for(int i = 0; i < unik.size(); i++)
			{
				int pivot = upper_bound(unik.begin(), unik.end(), x - unik[i]) - unik.begin();
				if(pivot < unik.size() && pivot != i) ans = compare(ans, unik[pivot] + unik[i], x);	
				if(pivot-1 >= 0 && pivot-1 != i) ans = compare(ans, unik[pivot-1] + unik[i], x);
				if(pivot+1 < unik.size() && pivot+1 != i) ans = compare(ans, unik[pivot+1] + unik[i], x);
			}
			
			printf("Closest sum to %d is %d.\n", x, ans);
		}
	}
	return 0;
}
