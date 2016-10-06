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

int prime[510],x,y,N;
vector<int> num;
LL K,tot;

int euler(int N)
{
	if(N==1) return 2;
	int ans = N;
	for(int i=0;i<num.size();i++) if(N%num[i]==0)
	{
		ans-=ans/num[i];
		while(N%num[i]==0) N/=num[i];
		if(N==1) break;
	}
	if(N!=1) ans-=ans/N;
	return ans;
}

int main()
{
	memset(prime,true,sizeof(prime));
	for(x=2;x*x<=500;x++) if(prime[x])
		for(y=2;x*y<=500;y++) prime[x*y]=false;
	for(x=2;x<=500;x++) if(prime[x]) num.pb(x);
	
	while(1)
	{
		scanf("%lld",&K);
		if(!K) break;
		
		tot=0LL;
		N=1;
		y=euler(N);
		while(tot+(LL)y<K)
		{
			tot+=(LL)y;
			//cout << tot << " " << K << endl;
			N++;
			y=euler(N);
		}
		
		for(x=0;x<N;x++) if(__gcd(x,N)==1)
		{
			tot++;
			if(tot==K) break;
		}
		printf("%d/%d\n",x,N);
	}
	return 0;
}

