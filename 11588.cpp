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

int T,N,M,bawah,samping,x,y,i,maks,ans;
int cnt[30];
char msk[30];

int main()
{
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d %d %d",&bawah,&samping,&N,&M);
		memset(cnt,0,sizeof(cnt));
		for(y=0;y<bawah;y++)
		{
			scanf("%s",msk);
			for(x=0;x<samping;x++) cnt[msk[x]-'A']++;
		}
		
		maks=0;
		for(x=0;x<26;x++) maks=max(maks,cnt[x]);
		
		ans=0;
		for(x=0;x<26;x++) if(cnt[x]==maks) ans+=N*cnt[x]; else ans+=M*cnt[x];
		printf("Case %d: %d\n",i,ans);
	}
	return 0;
}

