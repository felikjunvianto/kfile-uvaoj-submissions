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

int N,len,x,y,z;
int now,ans;
vector<int> num;
char msk[1000];

int main()
{
	scanf("%d",&N);getchar();
	while(N--)
	{
		gets(msk);len=strlen(msk);
		num.clear();
		x=-1;
		do
		{
			x++;
			if(msk[x]==' ') continue;
			
			now=0;
			y=x;
			while((y<len)&&(msk[y]!=' '))
			{
				now=now*10+(msk[y]-'0');
				y++;
			}
			num.pb(now);
			x=y;
		}while(x+1<len);
		
		ans=0;
		for(x=0;x<num.size();x++)
			for(y=x+1;y<num.size();y++)
				ans=max(ans,__gcd(num[x],num[y]));
				
		printf("%d\n",ans);
	}
	return 0;
}

