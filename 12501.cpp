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

using namespace std;

struct node
{
	LL incSum, linSum;
	int left, right, rangeVal;
};

int T, N, Q;
node segtree[400004];
char op[10];

void construct(int idx, int left, int right)
{
	segtree[idx].left = left;
	segtree[idx].right = right;
	segtree[idx].incSum = segtree[idx].linSum = 0LL;
	segtree[idx].rangeVal = 0;
	
	if(left < right)
	{
		int mid = (left + right) / 2;
		construct(2 * idx + 1, left, mid);
		construct(2 * idx + 2, mid + 1, right);
	}
}

void computeValue(int idx, int val)
{
	LL num = (LL)(segtree[idx].right - segtree[idx].left + 1);
	segtree[idx].incSum += (((num + 1LL) * num) / 2LL) * (LL) val;
	segtree[idx].linSum += num * (LL) val;
	segtree[idx].rangeVal += val;
}

void propagate(int idx)
{
	if(segtree[idx].rangeVal == 0) return;
	
	int leftIdx = 2 * idx + 1, rightIdx = leftIdx + 1;
	computeValue(leftIdx, segtree[idx].rangeVal);
	computeValue(rightIdx, segtree[idx].rangeVal);
	
	segtree[idx].incSum = segtree[idx].linSum = 0LL;
	segtree[idx].rangeVal = 0;
}

void update(int idx, int L, int R, int val)
{
	if(segtree[idx].right < L || segtree[idx].left > R) return; // outside range
	
	if(segtree[idx].left >= L && segtree[idx].right <= R) // just inside the range
	{
		computeValue(idx, val);
	} else // split
	{
		int leftIdx = 2 * idx + 1, rightIdx = leftIdx + 1;
		propagate(idx);
		update(leftIdx, L, R, val);
		update(rightIdx, L, R, val);
		
		LL offset = (LL) (segtree[rightIdx].left - segtree[leftIdx].left);
		segtree[idx].incSum = segtree[leftIdx].incSum + segtree[rightIdx].incSum + offset * segtree[rightIdx].linSum;
		segtree[idx].linSum = segtree[leftIdx].linSum + segtree[rightIdx].linSum;
	}
}

LL query(int idx, int L, int R)
{
	if(segtree[idx].right < L || segtree[idx].left > R) return 0LL; // outside range
	
	if(segtree[idx].left >= L && segtree[idx].right <= R) // just inside the range
	{
		LL offset = (LL)(segtree[idx].left - L);
		return segtree[idx].incSum + offset * segtree[idx].linSum;
	} else // split
	{
		int leftIdx = 2 * idx + 1, rightIdx = leftIdx + 1;
		propagate(idx);
		LL ans = query(leftIdx, L, R) + query(rightIdx, L, R);
		
		LL offset = (LL) (segtree[rightIdx].left - segtree[leftIdx].left);
		segtree[idx].incSum = segtree[leftIdx].incSum + segtree[rightIdx].incSum + offset * segtree[rightIdx].linSum;
		segtree[idx].linSum = segtree[leftIdx].linSum + segtree[rightIdx].linSum;
		
		return ans;
	}
}

int main()
{
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d %d", &N, &Q);
		construct(0, 1, N);
		update(0, 1, N, 100); // initial condition

		printf("Case %d:\n", t);
		int i, j, u;
		while(Q--)
		{
			scanf("%s", op);
			if(op[0] == 'c') // change
			{
				scanf("%d %d %d", &i, &j, &u);
				update(0, i, j, u);
			} else // query
			{
				scanf("%d %d", &i, &j);
				printf("%lld\n", query(0, i, j));
			}
		}
	}
	
	return 0;
}

