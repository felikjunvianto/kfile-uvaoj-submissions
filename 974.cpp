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

LL ten,square;
int N,x,y,z;
vector<int> kap;

int main()
{
	for(N=2;N<=40000;N++)
	{
		square=(LL)N*(LL)N;
		ten=10LL;
		while(ten<square)
		{
			LL a = square/ten;
			LL b = square%ten;
			if(a>0LL && b>0LL && a+b==(LL)N)
			{
				kap.pb(N);
				break;
			} else ten*=10LL;
		}
	}
	
	scanf("%d",&N);
	for(x=1;x<=N;x++) 
	{
		scanf("%d %d",&y,&z);
		int i = lower_bound(kap.begin(),kap.end(),y)-kap.begin();
		int j = upper_bound(kap.begin(),kap.end(),z)-kap.begin();
		
		if(x>1) printf("\n");
		printf("case #%d\n",x);
		if(i==j) printf("no kaprekar numbers\n");
			else while(i<j) printf("%d\n",kap[i++]);
	}
	return 0;
}

