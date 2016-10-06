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

using namespace std;

int a[]={6,35,204,1189,6930,40391,235416,1372105,7997214,46611179};
int b[]={8,49,288,1681,9800,57121,332928,1940449,11309768,65918161};

int main()
{
	for(int x=0;x<10;x++) printf("%10d%10d\n",a[x],b[x]);
	return 0;
}

/*precompute dengan code di bawah
long long prev,now,next,t,x;
vector<PII> a;

int main()
{
	t=0;
	prev=now=0;
	do
	{
		now++;printf("%I64d %I64d\n",now,t);
		prev+=(now-1);
		next=x=now+1;
		while(next<prev) next+=++x;
		if(prev==next)
		{
			t++;
			a.pb(mp(now,x));
		}
	}while(t<10);
	for(t=0;t<10;t++) printf("%10d%10d\n",a[t].fi,a[t].se);
	return 0;
}*/

