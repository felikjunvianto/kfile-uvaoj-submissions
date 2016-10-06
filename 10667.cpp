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

int T,S,B;
int r1,r2,c1,c2,r,c;
int sum[111][111];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&S);
		scanf("%d",&B);
		memset(sum,0,sizeof(sum));
		
		while(B--)
		{
			scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
			for(r=r1;r<=r2;r++)
				for(c=c1;c<=c2;c++) sum[r][c]++;
		}
		
		for(c=1;c<=S;c++)
			for(r=1;r<=S;r++)
				sum[r][c]+=sum[r-1][c];
				
		int ans = 0;
		for(r1=1;r1<=S;r1++)
			for(r2=r1;r2<=S;r2++)
			{
				c=0;
				do
				{
					c++;
					if(sum[r2][c]-sum[r1-1][c]) continue;
					
					int cm = c+1;
					while(cm<=S && sum[r2][cm]-sum[r1-1][cm]==0) cm++;
					ans = max(ans,(r2-r1+1)*(cm-c));
					c = cm;
				} while(c+1<=S);
			}
		printf("%d\n",ans);
	}
	return 0;
}

