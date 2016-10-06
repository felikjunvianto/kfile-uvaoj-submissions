#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
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

int N,A,i,x,y,carry;
int sum[200],Ap[200];

int main()
{
	while(scanf("%d %d",&N,&A)!=EOF)
	{
		memset(sum,0,sizeof(sum));
		memset(Ap,0,sizeof(Ap));
		Ap[0]=1;
		
		for(i=1;i<=N;i++)
		{
			carry=0;
			for(x=0;x<200;x++)
			{
				Ap[x]=Ap[x]*A+carry;
				carry=Ap[x]/10;
				Ap[x]%=10;
			}	
			
			carry=0;
			for(x=0;x<200;x++)
			{
				sum[x]=sum[x]+i*Ap[x]+carry;
				carry=sum[x]/10;
				sum[x]%=10;
			}
		}

		for(y=199;y>=0;y--) if(sum[y]) break;
		for(x=y;x>=0;x--) printf("%d",sum[x]);
		if(y==-1) printf("0");
		printf("\n");
	}
	return 0;
}

