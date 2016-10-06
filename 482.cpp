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

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define eps 1e-9

using namespace std;

int t,x,y,z;
char c;
vector<pair<int,string> > bil;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		bil.clear();
		do
		{
			scanf("%d%c",&x,&c);
			bil.pb(mp(x,"0.0"));
		}while(c!='\n');
		for(x=0;x<bil.size();x++) cin >> bil[x].se;
		sort(bil.begin(),bil.end());
		for(x=0;x<bil.size();x++) printf("%s\n",bil[x].se.c_str());
		if(t>0) printf("\n");
	}
	return 0;
}

