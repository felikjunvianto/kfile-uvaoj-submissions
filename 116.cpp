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
#define init -((1<<30)+10000)

using namespace std;

int bawah,samping;
int x,y,z;
int mat[110][15],dp[110][15],terkecil;
int path[110][15]; //nilainya adalah koordinat x di y+1 <path selanjutnya>

int solve(int x,int y)
{
	if(x==samping) return(mat[x][y]);
	if(dp[x][y]==init)
		for(int z=-1;z<=1;z++)
		{
			int next=y+z;
			if(next==0) next=bawah; else if(next==bawah+1) next=1;
			int temp=mat[x][y]+solve(x+1,next);
			
			if((dp[x][y]==init)||(dp[x][y]>temp)||((dp[x][y]==temp)&&(path[x][y]>next)))
			{
				dp[x][y]=temp;
				path[x][y]=next;
			}
		}
	return(dp[x][y]);
}

int main()
{
	while(scanf("%d %d",&bawah,&samping)!=EOF)
	{
		for(y=1;y<=bawah;y++)
			for(x=1;x<=samping;x++) 
			{
				scanf("%d",&mat[x][y]);
				path[x][y]=1000;
				dp[x][y]=init;
			}
			
		terkecil=-1*init;
		z=0;
		for(y=1;y<=bawah;y++) 
			if((terkecil==-1)||(terkecil>solve(1,y)))
			{
				terkecil=solve(1,y);
				z=y;
			}

		x=0;
		do
		{
			x++;
			printf("%d",z);
			z=path[x][z];
			if(x!=samping) printf(" ");
		}while(x<samping);
		printf("\n%d\n",terkecil);
	}
	return 0;
}

