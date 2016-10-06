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

string msk;
int len,x,y,z,great,ans;

int main()
{
	while(getline(cin,msk))
	{
		len=msk.size();
		great=0;
		
		for(x=0;x<len;x++) if(msk[x]==' ')
		{
			y=x;
			while(y<len && msk[y]==' ') y++;
			great=max(great,y-x);
			x=y-1;
		} 
		
		ans=0;
		while(great>1)
		{
			ans++;
			great=(great/2)+(great%2);
		}
		printf("%d\n",ans);
	}
	return 0;
}

