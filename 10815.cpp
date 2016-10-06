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

vector<string> ans;
string titip;
char masuk[250];
int x,y,z,panjang;

int main()
{
	ans.pb("@");
	while(gets(masuk))
	{
		panjang=strlen(masuk);
		if(panjang==0) continue;
		
		for(x=0;x<panjang;x++) if((masuk[x]>='A')&&(masuk[x]<='Z')) 
			masuk[x]=masuk[x]-'A'+'a';
		
		x=-1;
		do
		{
			x++;
			while(!((masuk[x]>='a')&&(masuk[y]<='z'))&&(x<panjang)) x++;
			if(x==panjang) break;
			
			y=x+1;
			while((masuk[y]>='a')&&(masuk[y]<='z')&&(y<panjang)) y++;y--;
			titip="";
			for(z=x;z<=y;z++) titip.pb(masuk[z]);
			ans.pb(titip);
			x=y;
		}while(x+1<panjang);
	}	
		
	sort(ans.begin(),ans.end());
	
	for(x=1;x<ans.size();x++) 
		if(ans[x]!=ans[x-1]) printf("%s\n",ans[x].c_str());
	return 0;
}

