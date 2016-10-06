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

int a,b,c,d;
bool visited[202][202][202];

int binser(int N)
{
	int l=0,r=200;
	while(l<=r)
	{
		int mid = (l+r)/2;
		int ans = mid*mid*mid;
		if(ans==N) return mid;
			else if(ans<N) l = mid+1;
				else r=mid-1;
	} return -1;
}

int main()
{
	memset(visited,sizeof(visited),false);
	for(a=6;a<=200;a++)
		for(b=2;b<=200;b++)
			for(c=2;c<=200;c++)
			{
				int tmp = a*a*a-b*b*b-c*c*c;
				d = binser(tmp);
				if(d>1) 
				{
					int mi = min(min(d,b),c);
					int ma = max(max(d,b),c);
					int mid = b+c+d-mi-ma;
					if(visited[mi][mid][ma]) continue;
					
					visited[mi][mid][ma] = true;
					printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
				}
			}
	return 0;
}

