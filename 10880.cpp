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

int T,i,C,R;
vector<int> Q;

int main()
{
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d",&C,&R);
		printf("Case #%d:",i);
		if(C==R)
		{
			printf(" 0\n");
			continue;
		}
		
		C-=R;
		Q.clear();
		for(int x=1;x*x<=C;x++) if(C%x==0)
		{
			if(x>R) Q.pb(x);
			if(x*x!=C && C/x>R) Q.pb(C/x);
		}
		
		sort(Q.begin(),Q.end());
		
		for(int x=0;x<Q.size();x++) printf(" %d",Q[x]);
		printf("\n");
	}
	return 0;
}

