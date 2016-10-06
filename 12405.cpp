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

int T,i,len,ans,x;
char msk[111];

int main()
{
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&len);
		scanf("%s",msk);
		ans=0;
		for(x=0;x<len;x++) if(msk[x]=='.') 
		{
			ans++;
			x+=2;
		}
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}

