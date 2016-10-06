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

int T,R,C,Q;
int r,c,ukuran,x;
int r1,r2,c1,c2;
char msk[111][111];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&R,&C,&Q);
		printf("%d %d %d\n",R,C,Q);
		for(r=0;r<R;r++) scanf("%s",msk[r]);
		
		while(Q--)
		{
			scanf("%d %d",&r,&c);
			
			bool bisa=true;
			ukuran=0;
			while(bisa)
			{
				ukuran++;
				r1 = r - ukuran, c1 = c - ukuran;
				r2 = r + ukuran, c2 = c + ukuran;
				
				if((r1<0)||(c1<0)||(r2>=R)||(c2>=C)) bisa=false;
				if(bisa) for(x=c1;x<=c2;x++) if(msk[r1][x]!=msk[r][c]) bisa=false;
				if(bisa) for(x=c1;x<=c2;x++) if(msk[r2][x]!=msk[r][c]) bisa=false;
				if(bisa) for(x=r1;x<=r2;x++) if(msk[x][c1]!=msk[r][c]) bisa=false;
				if(bisa) for(x=r1;x<=r2;x++) if(msk[x][c2]!=msk[r][c]) bisa=false;
			}
			
			printf("%d\n",2*(ukuran-1)+1);
		}
	}
	return 0;
}

