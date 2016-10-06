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

int N,x,y;
bool ada;

int binser(int l, int r, int T)
{
	while(l<=r)
	{
		int pivot = (l+r)/2;
		int temp = pivot*pivot*pivot;
		
		if(temp == T) return pivot; else
			if(temp < T) l = pivot+1; else
				if(temp > T) r = pivot-1;
	}
	return -1;
}

int main()
{
	while(1)
	{
		scanf("%d",&N);
		if(!N) break;
		
		ada=false;
		for(y=0;y<=100;y++) 
		{
			x=binser(0,100,N+y*y*y);
			if(x!=-1)
			{
				ada=true;
				break;
			}
		}
		
		if(!ada) printf("No solution\n");
			else printf("%d %d\n",x,y);
	}
	return 0;
}

