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

vector<LL> node;
LL N,x,y;

int main()
{
	node.pb(1),node.pb(1);
	do
	{
		N=0LL;
		x=(int)node.size()-1;
		for(y=0;y<=x;y++) N+=node[y]*node[x-y];
		node.pb(N);
	}while(N<4294967295LL);
	node[0]=0;
	while(scanf("%lld",&N)!=EOF)
	{
		y=lower_bound(node.begin(),node.end(),N)-node.begin();
		printf("%d\n",y);
	}
	return 0;
}

