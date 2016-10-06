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
#define ULL unsigned long long
#define INF 1000000000

using namespace std;

int mat[1010][1010];
int r,c,N,M,tmp;
bool awal;
ULL sum;

int main()
{
	memset(mat,0,sizeof(mat));
	awal=true;
	while(scanf("%d %d",&N,&M)!=EOF)
	{
		for(r=N;r;r--)
			for(c=1;c<=N;c++) scanf("%d",&mat[r][c]);
			
		for(r=1;r<=N;r++)
			for(c=1;c<=N;c++) mat[r][c]+=mat[r-1][c]+mat[r][c-1]-mat[r-1][c-1];
			
		if(!awal) printf("\n");
		awal=false;
		
		sum=0ULL;
		for(r=N-M+1;r;r--)
			for(c=1;c+M-1<=N;c++) 
			{
				tmp=mat[r+M-1][c+M-1]-mat[r-1][c+M-1]-mat[r+M-1][c-1]+mat[r-1][c-1];
				printf("%d\n",tmp);
				sum+=(ULL)tmp;
			}
		printf("%llu\n",sum);
	}
	return 0;
}

