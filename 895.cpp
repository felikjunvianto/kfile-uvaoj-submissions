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

vector<string> dict;
char msk[1010];
int len,x,y,z;
string inp;

int main()
{
	while(1)
	{
		scanf("%s",msk);
		if(msk[0]=='#') break;
		
		sort(msk,msk+strlen(msk));
		dict.pb(msk);
	}
	
	getchar();
	while(1)
	{
		gets(msk);
		if(msk[0]=='#') break;
		
		len=strlen(msk);
		inp.clear();
		for(x=0;x<len;x++) if(msk[x]!=' ') inp=inp+msk[x];
		sort(inp.begin(),inp.end());
		
		int ans = 0;
		for(x=0;x<dict.size();x++)
		{
			z=0;
			bool fit = true;
			for(y=0;y<dict[x].size() && fit;y++) 
			{
				while((z<inp.size())&&(inp[z]!=dict[x][y])) z++;
				if(z==inp.size()) fit=false; else z++;
			}
			if(fit) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

