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

int M,N,x,y,cnt;
bool divided;

int main()
{
	while(scanf("%d %d",&N,&M)!=EOF)
	{
		printf("%d ",M);
		
		divided=true;
		for(x=2;x*x<=M && divided;x++) if(M%x==0)
		{
			cnt=0;
			while(M%x==0)
			{
				cnt++;
				M/=x;
			}
			
			int tmp=N;
			while(tmp)
			{
				cnt-=tmp/x;
				tmp/=x;
			}
			
			if(cnt>0) divided=false;
		}
		if(M>1 && N<M) divided=false;
		
		if(divided) printf("divides %d!\n",N);
			else printf("does not divide %d!\n",N);
	}
	return 0;
}

