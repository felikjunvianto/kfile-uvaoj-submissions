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

int bawah,samping,x,y,ya,yb,z,ans;
int grid[111][111];

int main()
{
	memset(grid,0,sizeof(grid));
	while(1)
	{
		scanf("%d %d",&bawah,&samping);
		if(!bawah && !samping) break;
		
		for(y=1;y<=bawah;y++)
			for(x=1;x<=samping;x++)
			{
				scanf("%d",&z);
				grid[x][y]=z+grid[x][y-1];
			}
			
		ans=0;
		for(ya=1;ya<=bawah;ya++)
			for(yb=ya;yb<=bawah;yb++)
			{
				x=0;
				do
				{
					x++;
					y=x;
					while((y<=samping)&&(grid[y][yb]==grid[y][ya-1])) y++;
					ans=max(ans,(y-x)*(yb-ya+1));
					while((y<=samping)&&(grid[y][yb]>grid[y][ya-1])) y++;
					x=y-1;
				}while(x+1<=samping);
			}
		printf("%d\n",ans);
	}
	return 0;
}

