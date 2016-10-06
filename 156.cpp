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

char masuk[100];
int x,y;
vector<pair<string,string> > dict;
vector<string> ans;

int main()
{
	while(1)
	{
		gets(masuk);
		if(masuk[0]=='#') break;
		
		for(char *p=strtok(masuk," ");p;p=strtok(NULL," "))
		{
			string temp=p;
			for(x=0;x<temp.size();x++) if((temp[x]>='A')&&(temp[x]<='Z')) temp[x]^=32;
			sort(temp.begin(),temp.end());
			dict.pb(mp(temp,p));
		}
	}
	
	sort(dict.begin(),dict.end());
	x=-1;
	do
	{
		x++;
		y=x+1;
		while((y<dict.size())&&(dict[x].fi==dict[y].fi)) y++;y--;
		if(x==y) ans.pb(dict[x].se);
		x=y;
	}while(x+1<dict.size());
	sort(ans.begin(),ans.end());
	for(x=0;x<ans.size();x++) printf("%s\n",ans[x].c_str());
	return 0;
}

