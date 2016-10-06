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

int T,N,i;
vector<int> res;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		if(!N) printf("-1\n"); else
		if(N==1) printf("1\n"); else
		{
			res.clear();
			for(i=9;i>1;i--)
				while(N%i==0)
				{
					N/=i;
					res.pb(i);
				}
				
			if(res.empty() || N!=1) printf("-1");
				else for(i=(int)res.size()-1;i>=0;i--) printf("%d",res[i]);
			printf("\n");
		}
	}
	return 0;
}

