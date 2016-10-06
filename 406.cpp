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

bool prime[1010];
vector<int> ans;
int N,C;
int x,y,z;

int main()
{
	memset(prime,true,sizeof(prime));
	for(x=2;x*x<=1000;x++) if(prime[x])
	{
		z=2;
		while(x*z<=1000) 
		{
			prime[x*z]=false;
			z++;
		}
	}
	
	z=0;
	while(scanf("%d %d",&N,&C)!=EOF)
	{
		ans.clear();
		for(x=1;x<=N;x++) if(prime[x]) ans.pb(x);
		
		printf("%d %d:",N,C);
		if(ans.size()%2==1)
		{
			int mulai=((ans.size()-1)/2)-(C-1);
			if(mulai<0) for(x=0;x<ans.size();x++) printf(" %d",ans[x]); else
				for(x=0;x<2*C-1;x++) printf(" %d",ans[mulai+x]);
		} else
		{
			int mulai=((ans.size()-2)/2)-(C-1);
			if(mulai<0) for(x=0;x<ans.size();x++) printf(" %d",ans[x]); else
				for(x=0;x<2*C;x++) printf(" %d",ans[mulai+x]);
		}
		printf("\n\n");
	}
	return 0;
}

