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

int node[400010];
int N, Q, arr[100010];
int x, y, z, len, BL, BR;
vector<int> shift;
char inp[50];

void construct(int L, int R, int idx)
{
	if(L==R)
	{
		node[idx]=arr[L];
		return;
	}
	
	construct(L, (L+R)/2, idx*2 +1); int left = node[idx*2 + 1];
	construct((L+R)/2+1, R, idx*2 +2); int right = node[idx*2 + 2];
	node[idx] = min(left,right);
}

int query(int L, int R, int idx)
{
	if(L>BR || R<BL) return -1;
	if(BL<=L && R<=BR) return node[idx];
	
	int left = query(L, (L+R)/2, idx*2 +1);
	int right = query((L+R)/2+1, R, idx*2 +2);
	
	if(left<0) return right;
	if(right<0) return left;
	return min(left,right);
}

void update(int L, int R, int idx, int U)
{
	if(U<L || R<U) return;
	if(L==R && L==U)
	{
		node[idx] = arr[U];
		return;
	}
	
	update(L, (L+R)/2, idx*2 +1, U); int left = node[idx*2 + 1];
	update((L+R)/2+1, R, idx*2 +2, U); int right = node[idx*2 + 2];
	node[idx] = min(left,right);
}

int main()
{
	scanf("%d %d",&N, &Q);
	for(x=1;x<=N;x++) scanf("%d",&arr[x]);
	
	construct(1, N, 0);
	
	while(Q--)
	{
		scanf("%s",inp); len=strlen(inp);
		x = 5; //xxxxx( <--
		if(inp[0]=='q')
		{
			BL = 0; while(inp[++x]!=',') {BL = BL*10 + (inp[x]-'0');}
			BR = 0; while(inp[++x]!=')') {BR = BR*10 + (inp[x]-'0');}
			printf("%d\n",query(1, N, 0));
		} else
		{
			shift.clear();
			len = strlen(inp);
			y = 0;
			while(++x < len)
			{
				if(inp[x]>='0' && inp[x]<='9') y = y*10 + (inp[x]-'0'); else
				{
					shift.pb(y);
					y = 0;
				}
			}
			
			z = arr[shift[0]];
			for(x=1;x<shift.size();x++) arr[shift[x-1]] = arr[shift[x]];
			arr[shift[(int)shift.size()-1]] = z;
			
			for(x=0;x<shift.size();x++) update(1, N, 0, shift[x]);
		}
	}
	return 0;
}

