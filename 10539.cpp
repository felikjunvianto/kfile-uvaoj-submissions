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

bool prime[1000010];
int x,y,T,ans;
LL low, high;
vector<LL> num;

int main()
{
	memset(prime,true,sizeof(prime));
	for(x=2;x*x<=1000000;x++) if(prime[x])
		for(y=2;x*y<=1000000;y++) prime[x*y]=false;
		
	for(x=2;x<=1000000;x++) if(prime[x])
	{
		LL tmp = (LL)x;
		while(tmp*(LL)x <= 1000000000000LL)
		{
			tmp*=(LL)x;
			num.pb(tmp);	
		}	
	}
	sort(num.begin(),num.end());

	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld %lld",&low,&high);
		x=lower_bound(num.begin(),num.end(),low)-num.begin();
		y=upper_bound(num.begin(),num.end(),high)-num.begin();
		printf("%d\n",y-x);
	}
	return 0;
}

